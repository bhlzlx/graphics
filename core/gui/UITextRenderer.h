#pragma once
#include <GL/glew.h>

#include <freetype/ft2build.h>
#include <freetype/freetype.h>

#include "./core/CShader.h"
#include "./core/UIDataType.h"

#include "./mem/MemoryPool.h"
#include "./FrameBuffer.h"

#include <glm/glm.hpp>

typedef unsigned short wchar;

struct Font
{
	unsigned  page_index;
	UIRect    rect;
};

class UITextRenderer
{
public:
	// font 结构多而小，利用内存池减少内存分配，减少内存碎片
	MemoryPoolX::MemoryPool * m_pFontInfoPool;
	Font **	    m_pFontIndexer;

	GLuint		m_texFonts[4]; // 最多提供4个字体纹理，多了就不添加了
	char		m_texCurrIndex;

	int      	m_offsetx_base;
	int     	m_offsety_base;

	// freetype 相关数据结构
	FT_Library	m_library;
	FT_Face		m_face;

	CFrameBuffer	m_textFrameBuffer;
	CShader *		m_pTextShader;

	//
	float		m_cellsize;
	float		m_cellbytes;


	UITextRenderer(void);

	void Render(CShader * _pShader,unsigned short code);

	void Render(UIRect *_pScreenRect,const wchar_t * _unicodeText,glm::vec3 _color);

	void Init(const char * szFilepath,const char * textlib);

	Font * GetFont(unsigned short unicode);
	virtual ~UITextRenderer(void);
private:
	bool pushfont(unsigned short unicode);
};

