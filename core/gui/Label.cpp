#include "Label.h"
#include <core/texogl.h>
#include <core/device.h>

namespace gui
{
	void GuiRenderer::Init()
	{
		const char * szVertShader = 
						#include <glsl/uirender.vert>
		const char * szFragShader =
						#include <glsl/uirender.frag>
						
		EffectDesc effectDesc;
		effectDesc.szPixelShaderText = szFragShader;
		effectDesc.szVertexShaderText = szVertShader;
		this->m_pEffect = Graphics::EffectOGL::CreateEffect( &effectDesc);
	}
	
	void GuiRenderer::Render( GuiObject * _pGuiObject)
	{
		_pGuiObject->Draw( m_pEffect);
	}
	
	Label::Label()
	{
		
	}

	Label::~Label()
	{
	}
	void Label::Draw( Graphics::EffectOGL* _pEffect)
	{
	}

	Label * Label::CreateLabel( Rect<float>& _rc, uint32_t _color, float _fontSize)
	{
		Label * pLabel = new Label;
		pLabel->m_area = _rc;
		pLabel->m_fFontSize = _fontSize;
		Graphics::TexDesc texDesc;
		texDesc.ePixelFormat = Graphics::PIXEL_FORMAT_RGBA8888;
		texDesc.eTexClass = Graphics::TEX_CLASS_DYNAMIC;
		texDesc.size.width = _rc.width;
		texDesc.size.height = _rc.height;
		pLabel->m_pTex = Graphics::TexOGL::CreateTex( &texDesc, false);
	}
}

