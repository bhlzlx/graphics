#ifndef __GUI_LABEL_H__
#define __GUI_LABEL_H__
#include <gl/glew.h>

#include <core/renderer/textrenderer.h>
#include <core/texogl.h>
#include <core/device.h>
#include <core/effectogl.h>

using namespace Graphics;

namespace gui
{
	struct GuiObject;
	
	struct GuiRenderer
	{
		EffectOGL * m_pEffect;
		
		void Init();
		void Render( GuiObject * _pGuiObject);
	};
	
	struct GuiObject
	{
		virtual void Draw( EffectOGL * _pEffect ) = 0;
	};
	
	class Label:public GuiObject
	{
	public:
		Label();
		~Label();
		void Draw( EffectOGL * _pEffect );		
		static Label* CreateLabel( Rect<float>& _rc, uint32_t _color, float _fontSize);
	private:
		Graphics::Rect<float> m_area;
		Graphics::TexOGL* m_pTex;
		
		uint16_t * m_szText;
		uint32_t * m_nTextLen;
					
		float 		m_fFontSize;
	};

}

#endif // __GUI_LABEL_H__
