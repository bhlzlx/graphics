#include "Label.h"
#include <core/texogl.h>
#include <core/device.h>
#include <app/openglviewcontroller.h>

namespace gui
{
	void GuiRenderer::Init()
	{
		const char * szVertShader = 
						#include <glsl/uirender.vert>
		const char * szFragShader =
						#include <glsl/uirender.frag>
						
		EffectDesc effectDesc;
		int enableBlend = ow::GetPreference().GetIntValue("GUI_ENABLE_BLEND");
		if(enableBlend)
		{
			effectDesc.renderState.blendDest = BLEND_FACTOR_INVSRCALPHA;
			effectDesc.renderState.blendSrc = BLEND_FACTOR_SRCALPHA;
			effectDesc.renderState.blendable = true;
		}		
		effectDesc.szPixelShaderText = szFragShader;
		effectDesc.szVertexShaderText = szVertShader;
		m_pEffect = Graphics::EffectOGL::CreateEffect( &effectDesc);
		m_pTextRenderer = GetTextRenderer();
	}
	
	void GuiRenderer::Render( GuiObject * _pGuiObject )
	{
		if(m_pEffect && m_pTextRenderer)
		{
			_pGuiObject->Draw( m_pEffect, m_pTextRenderer);
		}
	}
	
	Label::Label()
	{
		m_pTex = NULL;
		m_szText = NULL;
		m_nTextLen = 0;
		m_fFontSize = 16.0f;
	}

	Label::~Label()
	{
		if(m_szText != NULL)
		{
			delete m_szText;
		}
		if(m_pTex != NULL)
		{
			m_pTex->Release();
		}
		m_szText = NULL;
		m_pTex = NULL;
	}
	
	void Label::Draw( Graphics::EffectOGL* _pEffect, TextRenderer* _pTextRenderer)
	{
		// 画文字
		_pTextRenderer->SetFontColor( this->m_vecColor.x ,this->m_vecColor.y, this->m_vecColor.z, this->m_vecColor.w);
		_pTextRenderer->SetFontSize( this->m_fFontSize);
		 
		_pTextRenderer->Render(m_pTex,m_offset,m_szText,m_nTextLen);
		// 将文字渲染到主界面
		RenderPipelineDefault * pPipeline = RenderPipelineDefault::GetRenderPipelineDefault( NULL );
		pPipeline->Resume();
		pPipeline->ClearDepth();
		_pEffect->Begin();
		// 计算位置
		Rect<uint32_t>& viewport = __pViewController->m_viewport;
		static Rect<float> drawRect;
		drawRect.x = this->m_area.x / (float)viewport.width;
		drawRect.y = this->m_area.y / (float)viewport.height;
		drawRect.width = this->m_area.width/(float)viewport.width;
		drawRect.height = this->m_area.height/(float)viewport.height;
		_pEffect->m_pShader->SetUniformData(&drawRect,"DRAW_RECT");
		_pEffect->m_pShader->SetTexture(0,this->m_pTex);
		glDrawArrays(GL_TRIANGLES,0,6);
		
		_pEffect->End();
	}

	Label * Label::CreateLabel( Rect<float>& _rc, glm::vec4 _color, float _fontSize)
	{
		Label * pLabel = new Label;
		pLabel->m_area = _rc;
		pLabel->m_vecColor = _color;
		pLabel->m_fFontSize = _fontSize;
		Graphics::TexDesc texDesc;
		texDesc.ePixelFormat = Graphics::PIXEL_FORMAT_RGBA8888;
		texDesc.eTexClass = Graphics::TEX_CLASS_DYNAMIC;
		texDesc.size.width = _rc.width;
		texDesc.size.height = _rc.height;
		pLabel->m_pTex = Graphics::TexOGL::CreateTex( &texDesc, false);
		
		return pLabel;
	}
}

