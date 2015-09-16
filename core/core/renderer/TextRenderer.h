#ifndef __CORE_TEXTRENDERER_H__
#define __CORE_TEXTRENDERER_H__

#include <gl/glew.h>
#include <stdint.h>

#include <ft2build.h>
#include FT_FREETYPE_H

#include <core/ShaderOGL.h>
#include <core/EffectOGL.h>
#include <core/TexOGL.h>
#include <core/RenderPipelineOGL.h>
#include <memory/memory.h>
#include <glm/glm.hpp>

using namespace Memory;

namespace Graphics
{
	extern const uint32_t CHARSET_MAX;	
	extern const uint32_t PPI;
	extern const uint32_t FONT_PT;
	extern const int32_t  FONT_TEX_SIZE;
	extern const int32_t  FONT_GAP;
	
	class TextRenderer
	{
	public:
		struct FontCharacter
		{
			uint8_t 	m_iPage;
			Rect<float>	m_range;
		};
		
		struct FontRenderState
		{
			glm::vec4 	m_vecFontColor;
			float 		m_fFontSize;
		};
		
	public:
		TextRenderer();
		~TextRenderer();
		
		uint8_t Init( const char * _szFontpath, const char * _szFontLib );
		
		void SetFontSize( float _fFontSize);
		void SetFontColor( float _r, float _g, float _b, float _a);
		void Render(ITex * _pTex, Size<uint32_t>& _offset,const uint16_t* _pUnicode, uint32_t _nChar );
		
		Rect<float>& GetCharRect( uint16_t _uChar );
		
		void Release();
		// 用于分配Font对象的内存池
		SMemPool*		m_pMemPool;
		FontCharacter** m_pFontMap;
		TexOGL* 		m_pFontTexArray[4];
		uint8_t			m_nFontTexCount;
		
		float 			m_fDefSize;
		
		Graphics::RenderPipeline* m_pFramebuffer;
		
		EffectOGL* 	    m_pEffect;
		
		FontRenderState	m_renderState;
	};
	
	TextRenderer * GetTextRenderer();
}

#endif // __CORE_TEXTRENDERER_H__
