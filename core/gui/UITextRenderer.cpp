#include "stdafx.h"
#include <iconv.h>
#include <cassert>
#include "UITextRenderer.h"
#include "./buffer/IBuffer.h"
#include <glm/glm.hpp>
#include "./app/OpenGLViewController.h"

const GLsizei PPI			= 96;
const GLsizei FONT_PT		= 24;
//const GLsizei FONT_PIXEL    = ((float)PPI * ((float)FONT_PT / 72.0f));
//static const GLsizei FONT_N_SIZE = FONT_PIXEL * FONT_PIXEL;

const GLsizei FONT_TEX_SIZE = 2048;
const GLsizei FONT_GAP		= 2;

UITextRenderer::UITextRenderer(void)
{
}

void UITextRenderer::Init(const char * szFilepath,const char * textlib )
{

	const char * szFontRenderVert = 
		#include "./models/fontrender.vert"
	const char * szFontRenderFrag = 
		#include "./models/fontrender.frag"

	m_pTextShader = CShader::ShaderFromStrings(szFontRenderVert,szFontRenderFrag);

	UISize size = OpenGLViewController::GetScreenSize();
	m_textFrameBuffer.InitFrameBuffer(
		RENDER_BUFFER_TYPE_DEPTH | RENDER_BUFFER_TYPE_COLOR,
		2048,
		128
		);

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	// ³õÊ¼»¯Êý¾Ý
	m_texCurrIndex = -1;
	m_offsetx_base = FONT_TEX_SIZE;
	m_offsety_base = FONT_TEX_SIZE;

	// ´´½¨Á½¸öbuffer¶ÔÏó Ò»¸ö¶ÁÎÄ¼þ£¬Ò»¸öÌá¹©×ª»»¿Õ¼ä
	IBuffer * textBuff = BufferFromFile(textlib);
	IBuffer * convBuff = CreateStandardBuffer(textBuff->GetLength() * 1.5);

	IBuffer * fontBuff = NULL;

	char * ptr_in = (char *)textBuff->GetBuffer();
	size_t siz_in = textBuff->GetLength();
	char * ptr_out = (char *)convBuff->GetBuffer();
	size_t siz_avail = convBuff->GetLength();
	size_t char_count = 0;

    iconv_t cd = iconv_open("UCS-2LE", "UTF-8");

    if (cd == (iconv_t)-1)
    {
		assert(false);
        return;
    }
	size_t error = 0;
	error = iconv(cd,&ptr_in,&siz_in,&ptr_out,&siz_avail);
	if(error != 0)
	{
		assert(false);
	}
	char_count =  (convBuff->GetLength() - siz_avail) / sizeof(unsigned short);
    iconv_close(cd);
	// Ïú»ÙÔ­Ê¼ÎÄ±¾buffer¶ÔÍâ
	textBuff->Release();
	// ´´½¨FontÄÚ´æ³Ø
	m_pFontInfoPool = new MemoryPoolX::MemoryPool(128,sizeof(Font));
	// ·ÖÅä´óÐ¡
	unsigned int N_FONT_MAX = 1<<17-1;
	m_pFontIndexer = new Font*[N_FONT_MAX];
	// Ö¸ÕëÖÃNULL
	memset(m_pFontIndexer,0,sizeof(Font*) * N_FONT_MAX);
	// ³õÊ¼»¯freetype
	error = FT_Init_FreeType(&m_library);
	error = FT_New_Face(m_library,szFilepath,0,&m_face);

	FT_Select_Charmap(m_face,FT_ENCODING_UNICODE);
	error = FT_Set_Char_Size(m_face,0, FONT_PT*64,PPI, PPI);
	// ÉèÖÃ
	unsigned short * pChar = (unsigned short *)convBuff->GetBuffer();

	
	for(int i = 0;i<char_count;++i)
	{
		if(m_pFontIndexer[pChar[i]] != NULL)
		{
			continue;
		}
		// äÖÈ¾³öÀ´Ò»¸öBitmap
		FT_Load_Char(m_face,pChar[i],FT_LOAD_RENDER);
		FT_Size_Metrics & metrics	= m_face->size->metrics;
		FT_Bitmap & bitmap			= m_face->glyph->bitmap;
		this->m_cellsize = metrics.max_advance / 64;
		this->m_cellbytes = m_cellsize * m_cellsize;
		
		if(!fontBuff)
		{
			fontBuff = CreateStandardBuffer(m_cellbytes);
		}

		GLuint down_pixels		= (-metrics.descender)>>6;
		GLuint up_pixels		= metrics.ascender>>6;
		GLuint height_pixels	= bitmap.rows;
		GLuint width_pixels		= bitmap.width;
		// °üÎ§ºÐ ×ó±ß
		GLuint offsetx			= m_face->glyph->bitmap_left > 0?m_face->glyph->bitmap_left:0;
		GLint  offsety		    = m_cellsize - (up_pixels - m_face->glyph->bitmap_top) - height_pixels;

		if(offsety < 0)
		{
			offsety = 0;
		}
		// Î»Í¼ÉÏÏÂ·´×ª
		for(int r = 0;r<bitmap.rows;++r)
		{
			memcpy((unsigned char*)fontBuff->GetBuffer() + r * bitmap.width,
				bitmap.buffer + (bitmap.rows - 1 - r) * bitmap.width,
				bitmap.width);
		}
		// ¿´¿´µ±Ç°ÎÆÀí»¹¹»²»¹»ÓÃ£¬Èç¹û²»¹»ÓÃ¾Í´´½¨Ò»¸öÐÂµÄÎÆÀí
		int width_left = FONT_TEX_SIZE - FONT_GAP - m_offsetx_base;
		if(width_left < (int)(width_pixels + offsetx))
		{
			// Èç¹ûÊ£ÓàµÄ¿í¶È²»¹»£¬¾Í³¢ÊÔÏÂÒ»ÐÐ
			m_offsetx_base = 0;
			m_offsety_base += m_cellsize;
			m_offsety_base += FONT_GAP;
			if(FONT_TEX_SIZE - FONT_GAP - m_offsety_base < m_cellsize)
			{
				// ÏÂÒ»ÐÐÒ²ÈÝ²»ÏÂÁË£¬·ÖÅäÒ»¸öÐÂµÄÌùÍ¼
				// Éú³ÉÒ»¸öÎÆÀí
				error = glGetError();
				GLuint tex;
				glGenTextures(1,&tex);
				glBindTexture(GL_TEXTURE_2D,tex);
				glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP_TO_EDGE);
				glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP_TO_EDGE);
				glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR_MIPMAP_LINEAR);
				glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR);
				glGenerateMipmap(GL_TEXTURE_2D);
				error = glGetError();
				glTexStorage2D(GL_TEXTURE_2D,1,GL_R8,FONT_TEX_SIZE,FONT_TEX_SIZE);

				IBuffer * emptyBuff = CreateStandardBuffer(FONT_TEX_SIZE * FONT_TEX_SIZE);
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
				
				++m_texCurrIndex;
				m_texFonts[m_texCurrIndex] = tex;
				m_offsety_base = m_offsetx_base = 0;
			}
		}

		Font * pInfo = (Font*)m_pFontInfoPool->Alloc(sizeof(Font));
		pInfo->page_index = m_texCurrIndex;
		pInfo->rect.x = (float)m_offsetx_base / (float)FONT_TEX_SIZE;
		pInfo->rect.y = (float)m_offsety_base / (float)FONT_TEX_SIZE;
		pInfo->rect.dx = (float)(width_pixels + offsetx) / (float)FONT_TEX_SIZE;
		pInfo->rect.dy = (float)m_cellsize / (float)FONT_TEX_SIZE;

		m_pFontIndexer[pChar[i]] = pInfo;

		// ½«µãÕóÊý¾Ý£¬Ð´Èë´óÎÆÀí
		glTexSubImage2D(
			GL_TEXTURE_2D,
			0,
			offsetx + m_offsetx_base,
			offsety + m_offsety_base,
			bitmap.width,
			bitmap.rows,
			GL_RED,
			GL_UNSIGNED_BYTE,
			fontBuff->GetBuffer()
			);
		error = glGetError();
		assert(error == 0);
		// Ë®Æ½Æ«ÒÆÒ»ÏÂ
		m_offsetx_base = m_offsetx_base + FONT_GAP + width_pixels + offsetx;
	}

	FT_Done_Face(m_face);
	FT_Done_FreeType(m_library);
	if(fontBuff)
		fontBuff->Release();
	convBuff->Release();
	glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
}

Font * UITextRenderer::GetFont(unsigned short unicode)
{
	Font * pFont = m_pFontIndexer[unicode];
	if(pFont)
	{
		return pFont;
	}
	else
	{
		// ¡õ ×Ö·ûÌæ»»
		return m_pFontIndexer[9633];
	}
}

void UITextRenderer::Render(UIRect *_pScreenRect,const wchar_t * _unicodeText,glm::vec3 _color)
{
	GLenum error = glGetError();
	UISize screenSize = OpenGLViewController::GetScreenSize();
	m_textFrameBuffer.Bind();
	m_pTextShader->Active();
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glClearDepth(1.0f);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

	glViewport(0,0,m_textFrameBuffer.m_width,m_textFrameBuffer.m_height);
	// _pScreenRect ´æµÄÊÇÊµ¼ÊµÄÏñËØ¿í¸ßÖµ
	// ¼ÆËãÎÄ×ÖËùÕ¼µÄ´óÐ¡
	UISize size(0,0);

	float offsetx ,offsety;
	offsetx = offsety = 0.0f;

	UIRect drawRect(0,0,0,0);
	// Ëõ·ÅºóµÄ¸ß¶È
	float fontPixelsH = _pScreenRect->dy > m_cellsize ? m_cellsize :_pScreenRect->dy;
	float fontPixelsW = 0;
	drawRect.dy = fontPixelsH / m_textFrameBuffer.m_height;
	// ½«Ò»ÐÐ×ÖäÖÈ¾µ½ÎÆÀíÉÏ
	for (int i = 0; i < wcslen(_unicodeText); i++)
	{
		if(_unicodeText[i] == 32)
		{
			// ¿Õ¸ñ
			drawRect.x += drawRect.dx;
			drawRect.dx = (fontPixelsH / 2)/m_textFrameBuffer.m_width;
			continue;
		}
		Font * pFont = GetFont(_unicodeText[i]);
		if(pFont)
		{
			// ¼ÆËãÔÚframebufferÀïËùÕ¼µÄ¾ØÐÎ´óÐ¡
			// ×ÖµÄÎ»ÖÃÏòÓÒÆ½ÒÆÒ»¸ö×ÖÌå¾àÀë
			drawRect.x += drawRect.dx;
			// ´Ó×ÖÌåµÄ´óÐ¡£¬¿í¸ß±ÈÀý»­³öÀ´Ëõ·ÅºóµÄ¿í¶È
			// ×ÖÌå¿í£¬ÏñËØ¸öÊý
			fontPixelsW = fontPixelsH * (pFont->rect.dx / pFont->rect.dy);
			drawRect.dx = fontPixelsW / m_textFrameBuffer.m_width;
			if(1.0f - drawRect.x - drawRect.dx < 0.0f)
			{
				drawRect.dx = 0.0f;
				break;
			}
			// °ó¶¨×ÖÌåÎÆÀí,×ÖÌåUV,»æÖÆÎ»ÖÃ
			int drawType = 0;
			m_pTextShader->SetSampler(0,m_texFonts[pFont->page_index]);
			m_pTextShader->SetUniformData(&drawRect,"DRAW_RECT");			
			m_pTextShader->SetUniformData(&pFont->rect,"FONT_RECT");
			m_pTextShader->SetUniformData(&_color,"FONT_COLOR");
			m_pTextShader->SetUniformData(&drawType,"DRAW_TYPE");

			glDrawArrays(GL_TRIANGLES,0,6);
		}
	}
	error = glGetError();
	// ½«äÖÈ¾ºÃµÄ×Ö·û´®ÌùÔÚÆÁÄ»ÉÏ
	glViewport(0,0,screenSize.dx,screenSize.dy);
	UIRect stringRect;
	stringRect.dx = drawRect.x + drawRect.dx;
	stringRect.dy = drawRect.dy;
	stringRect.x = stringRect.y = 0.0f;
	float stringPixelsW = stringRect.dx * m_textFrameBuffer.m_width;
	float drawPixelW = _pScreenRect->dx;
	float clipRate = drawPixelW / stringPixelsW;

	stringRect.dx *= clipRate;
	
	drawRect.dx = _pScreenRect->dx / screenSize.dx;
	drawRect.dy = _pScreenRect->dy / screenSize.dy;
	drawRect.x  = _pScreenRect->x / screenSize.dx;
	drawRect.y  = (1 - _pScreenRect->y / screenSize.dy) - drawRect.dy;
	
	// °ó¶¨Ä¬ÈÏFBO
	int drawType = 1;

	glBindFramebuffer(GL_FRAMEBUFFER,0);
	m_pTextShader->Active();
	m_pTextShader->SetSampler(0,m_textFrameBuffer.m_colorTexture);
	m_pTextShader->SetUniformData(&drawRect,"DRAW_RECT");
	m_pTextShader->SetUniformData(&stringRect,"FONT_RECT");
	m_pTextShader->SetUniformData(&drawType,"DRAW_TYPE");
	glDrawArrays(GL_TRIANGLES,0,6);
	error = glGetError();
	glDisable(GL_BLEND);
}

void UITextRenderer::Render(CShader * _pShader,unsigned short code)
{

	glEnable(GL_BLEND);
	Font * fontInfo = m_pFontIndexer[code];
	//rect.x = rect.y = 0;
	//rect.w = rect.z = 1;
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	_pShader->SetUniformData(&fontInfo->rect,"FONT_RECT");
	_pShader->SetSampler(0,m_texFonts[0]);
	glDrawArrays(GL_TRIANGLES,0,6);
	glDisable(GL_BLEND);
}

bool UITextRenderer::pushfont(unsigned short unicode)
{
	/*int error;
	unsigned char * pbuff = new unsigned char[FONT_N_SIZE];
	if(m_pFontIndexer[unicode] != NULL)
	{
		return true;
	}
	// äÖÈ¾³öÀ´Ò»¸öBitmap
	FT_Load_Char(m_face,unicode,FT_LOAD_RENDER);
	FT_Size_Metrics & metrics	= m_face->size->metrics;
	FT_Bitmap & bitmap			= m_face->glyph->bitmap;

	GLuint down_pixels		= (-metrics.descender)>>6;
	GLuint up_pixels		= metrics.ascender>>6;
	GLuint height_pixels	= bitmap.rows;
	GLuint width_pixels		= bitmap.width;
	// °üÎ§ºÐ ×ó±ß
	GLuint offsetx			= m_face->glyph->bitmap_left;
	GLint  offsety		    = m_cellsize - (up_pixels - m_face->glyph->bitmap_top) - height_pixels;

	if(offsety < 0)
	{
		offsety = 0;
	}
	// Î»Í¼ÉÏÏÂ·´×ª
	for(int r = 0;r<bitmap.rows;++r)
	{
		memcpy(pbuff + r * bitmap.width,
			bitmap.buffer + (bitmap.rows - 1 - r) * bitmap.width,
			bitmap.width);
	}
	// ¿´¿´µ±Ç°ÎÆÀí»¹¹»²»¹»ÓÃ£¬Èç¹û²»¹»ÓÃ¾Í´´½¨Ò»¸öÐÂµÄÎÆÀí
	int width_left = FONT_TEX_SIZE - FONT_GAP - m_offsetx_base;
	if(width_left < (int)(width_pixels + offsetx))
	{
		// Èç¹ûÊ£ÓàµÄ¿í¶È²»¹»£¬¾Í³¢ÊÔÏÂÒ»ÐÐ
		m_offsetx_base = 0;
		m_offsety_base += m_cellsize;
		m_offsety_base += FONT_GAP;
		if(FONT_TEX_SIZE - FONT_GAP - m_offsety_base < m_cellsize)
		{
			// ÏÂÒ»ÐÐÒ²ÈÝ²»ÏÂÁË£¬·ÖÅäÒ»¸öÐÂµÄÌùÍ¼
			// Éú³ÉÒ»¸öÎÆÀí
			error = glGetError();
			GLuint tex;
			glGenTextures(1,&tex);
			glBindTexture(GL_TEXTURE_2D,tex);
			glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
			error = glGetError();
			glTexStorage2D(GL_TEXTURE_2D,1,GL_R8,FONT_TEX_SIZE,FONT_TEX_SIZE);

			IBuffer * emptyBuff = CreateStandardBuffer(FONT_TEX_SIZE * FONT_TEX_SIZE);
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
			// ¸üÐÂÊý¾Ý
			++m_texCurrIndex;
			m_texFonts[m_texCurrIndex] = tex;
			m_offsety_base = m_offsetx_base = 0;
		}
	}

	Font * pInfo = (Font*)m_pFontInfoPool->Alloc(sizeof(Font));
	pInfo->page_index = m_texCurrIndex;
	pInfo->rect.x = (float)m_offsetx_base / (float)FONT_TEX_SIZE;
	pInfo->rect.y = (float)m_offsety_base / (float)FONT_TEX_SIZE;
	pInfo->rect.dx = (float)(width_pixels + offsetx) / (float)FONT_TEX_SIZE;
	pInfo->rect.dy = (float)m_cellsize / (float)FONT_TEX_SIZE;

	m_pFontIndexer[unicode] = pInfo;

	// ½«µãÕóÊý¾Ý£¬Ð´Èë´óÎÆÀí
	glTexSubImage2D(
		GL_TEXTURE_2D,
		0,
		offsetx + m_offsetx_base,
		offsety + m_offsety_base,
		bitmap.width,
		bitmap.rows,
		GL_RED,
		GL_UNSIGNED_BYTE,
		pbuff
		);
	error = glGetError();
	assert(error == 0);
	// Ë®Æ½Æ«ÒÆÒ»ÏÂ
	m_offsetx_base = m_offsetx_base + FONT_GAP + width_pixels + offsetx;
	return true;
	*/
		return true;
}

UITextRenderer::~UITextRenderer(void)
{
	delete m_pFontInfoPool;
	delete []m_pFontIndexer;
}
