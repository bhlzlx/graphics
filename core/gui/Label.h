#ifndef __GUI_LABEL_H__
#define __GUI_LABEL_H__
#include <gl/glew.h>

#include <core/renderer/textrenderer.h>
#include <core/texogl.h>
#include <core/device.h>

namespace gui
{
	class Label
	{
	public:
		Label();
		~Label();
		void Draw(  );
	private:
		Graphics::Rect<float>\
					m_area;
		Graphics::TexOGL*\
					m_pTex;
					
		float 		m_fFontSize;
	};

}

#endif // __GUI_LABEL_H__
