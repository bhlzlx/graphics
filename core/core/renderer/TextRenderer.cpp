#include "TextRenderer.h"
#include <iconv.h>
#include <buffer/buffer.h>
#include <cassert>
#include <core/texogl.h>
#include <core/effectogl.h>
#include <core/rendertargetogl.h>
#include <core/depthstencilogl.h>

#include <settings/settings.h>

namespace Graphics
{
	const uint32_t CHARSET_MAX 	= 1<<17-1;	
	const uint32_t PPI			= 96;
	const uint32_t FONT_PT		= 24;	
	const int32_t  FONT_TEX_SIZE = 2048;
	const int32_t  FONT_GAP		= 2;
	
	float FONT_BOUND = 0.0f;

	TextRenderer::TextRenderer()
	{
	}

	TextRenderer::~TextRenderer()
	{
	}

	uint8_t TextRenderer::Init( const char * _szFontpath, const char * _szFontLib )
	{
		// 判断文件可读性
		FILE * file = NULL;
		file = fopen(_szFontLib,"r");
		assert(file);
		fclose(file);
		file = fopen(_szFontpath,"r");
		assert(file);
		fclose(file);
		
		// 初始化 shader effect
		Graphics::EffectDesc effectDesc;
		effectDesc.renderState.blendDest = BLEND_FACTOR_INVSRCALPHA;
		effectDesc.renderState.blendSrc = BLEND_FACTOR_SRCALPHA;
		effectDesc.renderState.blendable = true;
		
		effectDesc.szPixelShaderText = 
									#include <glsl/fontrender.frag>
		effectDesc.szVertexShaderText = 
									#include <glsl/fontrender.vert>
		
		this->m_pEffect = Graphics::EffectOGL::CreateEffect(&effectDesc);
		// 创建帧缓冲区
		RenderTargetDesc renderTargetDesc;
		renderTargetDesc.eFormat = PIXEL_FORMAT_RGBA8888;
		renderTargetDesc.m_Size.width = 4;
		renderTargetDesc.m_Size.height = 4;
		DepthStencilDesc depthStencilDesc;
		depthStencilDesc.m_Size.width = 2048;
		depthStencilDesc.m_Size.height = 2048;
		
		Graphics::RenderTargetOGL * pRenderTarget = Graphics::RenderTargetOGL::CreateRenderTarget( &renderTargetDesc);
		Graphics::IDepthStencil* pDepthStencil = Graphics::DepthStencilOGL::CreateDepthStencil( &depthStencilDesc);
		Graphics::RenderPipelineDesc pipelineDesc;
		pipelineDesc.nRendertargetCount = 1;
		pipelineDesc.pDepthStencil = pDepthStencil;
		pipelineDesc.pRenderTargets[0] = pRenderTarget;
		pipelineDesc.clearOP.vClearColors[3] = 0.4f;
		
		this->m_pFramebuffer = Graphics::RenderPipeline::CreateRenderPipeline( &pipelineDesc);
		m_pFramebuffer->m_desc.pRenderTargets[0]->GetColorTex()->Release();
		m_pFramebuffer->m_desc.pRenderTargets[0]->SetColorTex( NULL);
		
		
		// 将utf8转换为unicode编码
		iBuffer * pFontlibBuffer = BufferFromFile( _szFontLib);	
		iBuffer * pUTFBuffer = CreateStandardBuffer( pFontlibBuffer->GetLength() * 1.5);
		
		uint8_t * ptr_in = pFontlibBuffer->GetBuffer();
		uint32_t size_in = pFontlibBuffer->GetLength();
		uint8_t * ptr_out = pUTFBuffer->GetBuffer();
		uint32_t size_avail = pUTFBuffer->GetLength();
		
		uint32_t char_count = 0;
		iconv_t conv = iconv_open("UCS-2LE", "UTF-8");
		if(conv == iconv_t(-1))
		{
			return 0;
		}
		uint32_t error = 0;
		error = iconv(conv,(char**)&ptr_in,&size_in,(char **)&ptr_out,&size_avail);
		if(error != 0)
		{
			iconv_close(conv);
			return false;
		}
		char_count =  (pUTFBuffer->GetLength() - size_avail) / sizeof(uint16_t);
		// 关闭转换流
		iconv_close(conv);
		// 销毁文件缓冲
		pFontlibBuffer->Release();
		// 创建Font内存池
		this->m_pMemPool = new Memory::SMemPool(32,sizeof(FontCharacter));
		// 分配满FontChar位,置零
		this->m_pFontMap = new FontCharacter*[CHARSET_MAX];
		memset(m_pFontMap, 0, sizeof(FontCharacter*) * CHARSET_MAX);
		// init freetype 
		FT_Library 		freetype_lib;
		FT_Face			freetype_face;
		
		error = FT_Init_FreeType( &freetype_lib);
		error = FT_New_Face( freetype_lib, _szFontpath, 0, &freetype_face);
		error = FT_Select_Charmap(freetype_face,FT_ENCODING_UNICODE);
		error = FT_Set_Char_Size(freetype_face, 0, FONT_BOUND*64, PPI, PPI);
		// 遍历字符
		uint16_t* pChar = (uint16_t *)pUTFBuffer->GetBuffer();
		// 
		iBuffer * fontBuff = NULL;
		
		int32_t iTexCoordBaseX = FONT_TEX_SIZE;
		int32_t iTexCoordBaseY = FONT_TEX_SIZE;
		int32_t  iCurrTexIdx = -1;
		
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		
		for(uint32_t charIdx = 0; charIdx<char_count; ++charIdx)
		{
			uint16_t charcode = pChar[ charIdx ];
			if(m_pFontMap[ charcode ] != NULL)
			{
				continue;
			}
			// 加载位图
			FT_Load_Char(freetype_face, charcode, FT_LOAD_RENDER);
			FT_Size_Metrics & metrics	= freetype_face->size->metrics;
			FT_Bitmap & bitmap			= freetype_face->glyph->bitmap;
			
			int32_t  cellsize		= metrics.height>>6;
			uint32_t cellbytes 		= cellsize * cellsize;
			uint32_t down_pixels	= (-metrics.descender)>>6;
			uint32_t up_pixels		= metrics.ascender>>6;
			uint32_t height_pixels	= bitmap.rows;
			uint32_t width_pixels	= bitmap.width;
			uint32_t offsetx		= freetype_face->glyph->bitmap_left > 0?freetype_face->glyph->bitmap_left:0;
			int32_t  offsety		= cellsize - (up_pixels - freetype_face->glyph->bitmap_top) - height_pixels;
			
			if(!fontBuff)
			{
				m_fDefSize = (float)cellsize;
				fontBuff = CreateStandardBuffer( cellbytes );
			}
			else
			{
				assert( fontBuff->GetLength() >= cellbytes);
			}
			if(offsety < 0)
			{
				offsety = 0;
			}
			// 从freetype中复制像素到fontbuffer
			// copy pixels to buffer
			memset(fontBuff->GetBuffer(),0,fontBuff->GetLength());
			for(int32_t r = 0; r<bitmap.rows; ++r)
			{
				memcpy(
					(uint8_t*)fontBuff->GetBuffer() + r * bitmap.width,
					bitmap.buffer + (bitmap.rows - 1 - r) * bitmap.width,
					bitmap.width);
			}
			
			int width_left = FONT_TEX_SIZE - FONT_GAP - iTexCoordBaseX;
			if(width_left < (int)(width_pixels + offsetx))
			{
				// 看宽度还够，不够就换下一行，x值归零
				iTexCoordBaseX = 0;
				iTexCoordBaseY += cellsize;
				iTexCoordBaseY += FONT_GAP;
				// 如果高度也不够了新建一个texture
				if(FONT_TEX_SIZE - FONT_GAP - iTexCoordBaseY < cellsize)
				{
					if(iCurrTexIdx != -1)
					{
						m_pFontTexArray[iCurrTexIdx]->Bind();
						//glGenerateMipmap(GL_TEXTURE_2D);
					}
					Graphics::TexDesc texdesc;		
					texdesc.eTexClass = TEX_CLASS_DYNAMIC;
					texdesc.ePixelFormat = PIXEL_FORMAT_A8;
					texdesc.size = Size<uint32_t>(FONT_TEX_SIZE, FONT_TEX_SIZE);
					Graphics::TexOGL * pTex = Graphics::TexOGL::CreateTex( &texdesc, false);
					pTex->Bind();
					iBuffer * emptyBuff = CreateStandardBuffer(FONT_TEX_SIZE * FONT_TEX_SIZE);
					memset(emptyBuff->GetBuffer(),0,emptyBuff->GetLength());
					glTexSubImage2D(
						GL_TEXTURE_2D,
						0,
						0,
						0,
						FONT_TEX_SIZE,
						FONT_TEX_SIZE,
						GL_RED,
						GL_UNSIGNED_BYTE,
						emptyBuff->GetBuffer()
						);
					emptyBuff->Release();
					
					error = glGetError();
					++iCurrTexIdx;
					m_pFontTexArray[iCurrTexIdx] = pTex;
					iTexCoordBaseY = iTexCoordBaseX = 0;
				}
			}
			
			FontCharacter * pInfo = ( FontCharacter *)this->m_pMemPool->Alloc( sizeof( FontCharacter));
			pInfo->m_iPage = iCurrTexIdx;
			pInfo->m_range.x = (float)iTexCoordBaseX / (float)FONT_TEX_SIZE;
			pInfo->m_range.y = (float)iTexCoordBaseY / (float)FONT_TEX_SIZE;
			pInfo->m_range.width = (float)(width_pixels + offsetx) / (float)FONT_TEX_SIZE;
			pInfo->m_range.height = (float)cellsize / (float)FONT_TEX_SIZE;
			m_pFontMap[charcode] = pInfo;
			
			void * pPixels = fontBuff->GetBuffer();
			error = 0;
			
			if(bitmap.width && bitmap.rows)
			{
				this->m_pFontTexArray[iCurrTexIdx]->Bind();
				glTexSubImage2D(
					GL_TEXTURE_2D,
					0,
					offsetx + iTexCoordBaseX,
					offsety + iTexCoordBaseY,
					bitmap.width,
					bitmap.rows,
					GL_RED,
					GL_UNSIGNED_BYTE,
					pPixels
					);
			}
			
			error = glGetError();
			if(error != 0)
			{
				assert(error == 0);
			}
			iTexCoordBaseX = iTexCoordBaseX + FONT_GAP + width_pixels + offsetx;
		}
		
		FT_Done_Face(freetype_face);
		FT_Done_FreeType(freetype_lib);
		if(fontBuff)
		{
			fontBuff->Release();
		}
		pUTFBuffer->Release();
		//glGenerateMipmap(GL_TEXTURE_2D);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
	}
	
	Rect<float>& TextRenderer::GetCharRect( uint16_t _uChar )
	{
		return this->m_pFontMap[_uChar]->m_range;
	}
	
	void TextRenderer::Render(ITex * _pTex, Size<uint32_t>& _offset,const uint16_t* _pUnicode, uint32_t _nChar )
	{
		float fRealHeight = 0;
		float fRealWidth = 0;
		// 获取要渲染纹理的大小
		Size<uint32_t>& texSize = _pTex->GetSize();
		// 设置viewport
		m_pFramebuffer->m_viewport.width = texSize.width;
		m_pFramebuffer->m_viewport.height = texSize.height;
		// 设置纹理
		m_pFramebuffer->m_desc.pRenderTargets[0]->SetColorTex(_pTex);
		TexOGL * pTex = (TexOGL*)_pTex;
		glBindFramebuffer(GL_FRAMEBUFFER, m_pFramebuffer->m_FrameBuffer);
		glFramebufferTexture(GL_DRAW_FRAMEBUFFER,GL_COLOR_ATTACHMENT0,pTex->m_texture,0);
		// 渲染
		m_pFramebuffer->Begin();
		m_pEffect->Begin();
		m_pEffect->m_pShader->SetUniformData( &this->m_renderState.m_vecFontColor, "FONT_COLOR");
		static Rect<float>  drawRect;
		uint32_t xoffset_t = _offset.width;
		for(uint32_t charId = 0; charId<_nChar; ++charId )
		{
			if(_pUnicode[charId] == 32)
			{
				xoffset_t+= m_renderState.m_fFontSize/2;
				continue;
			}
			FontCharacter * pFontInfo = this->m_pFontMap[_pUnicode[charId]];
			if(pFontInfo == NULL)
			{
				pFontInfo = m_pFontMap[95];
			}
			Rect<float>& fontRect = pFontInfo->m_range;
			uint32_t iPage = pFontInfo->m_iPage;
			fRealHeight = m_renderState.m_fFontSize;
			fRealWidth = m_renderState.m_fFontSize * fontRect.width / fontRect.height;
			drawRect.height = fRealHeight / texSize.height;
			drawRect.width = fRealWidth / texSize.width;
			drawRect.x = (float)xoffset_t / (float)texSize.width;
			drawRect.y = 1 - _offset.height/texSize.height - drawRect.height;
			// 设置shader变量
			m_pEffect->m_pShader->SetTexture(0, this->m_pFontTexArray[iPage]);
			m_pEffect->m_pShader->SetUniformData( &fontRect, "FONT_RECT");
			m_pEffect->m_pShader->SetUniformData( &drawRect, "DRAW_RECT");
			// 画字符
			glDrawArrays(GL_TRIANGLES,0,6);
			xoffset_t += fRealWidth;
			// 超限判断放在最后
			if(xoffset_t > texSize.width || drawRect.y > texSize.height)
			{
				break;
			}
		}
		m_pEffect->End();
		m_pFramebuffer->End();
	}
	
	TextRenderer * __pTextureRenderer = NULL;
	
	TextRenderer * GetTextRenderer()
	{
		if( __pTextureRenderer == NULL)
		{
			__pTextureRenderer = new TextRenderer();
			phantom::Config & config = phantom::GetSettings();
			const char * fontPath = config.m_strings["FONT_TTF"].c_str();
			const char * charLib = config.m_strings["CHAR_LIB"].c_str();
			FONT_BOUND = config.m_floats["FONT_BASIC_SIZE"];
			__pTextureRenderer->Init( fontPath, charLib);
		}
		return __pTextureRenderer;
	}
	
	void Graphics::TextRenderer::Release()
	{
		this->m_pEffect->Release();
		this->m_pFramebuffer->Release();		
		// fontmap里的对象全部由内存池分配，所以直接销毁内存池，和指针数组就可以了
		delete []this->m_pFontMap;
		delete m_pMemPool;
		// 销毁纹理
		for(int i = 0; i<this->m_nFontTexCount; ++i)
		{
			this->m_pFontTexArray[i]->Release();
		}
	}
	
	void Graphics::TextRenderer::SetFontColor(float _r, float _g, float _b, float _a)
	{
		this->m_renderState.m_vecFontColor.x = _r;
		this->m_renderState.m_vecFontColor.y = _g;
		this->m_renderState.m_vecFontColor.z = _b;
		this->m_renderState.m_vecFontColor.w = _a;
	}

	void Graphics::TextRenderer::SetFontSize(float _fFontSize)
	{
		this->m_renderState.m_fFontSize = _fFontSize;
	}

}

