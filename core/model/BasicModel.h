#ifndef __BASIC_MODELS_H__
#define __BASIC_MODELS_H__

#include "RenderObject.h"

namespace Graphics
{
	class Cube: public RenderObjectBase
	{
	public:
		void Render(EffectOGL * _pEffect,uint8_t _wiredFrame);
		void Release();
		static RenderObjectBase * CreateCube();
	public:
		VertexArray*	m_pVertexArray;
		VertexBuffer*	m_pVertexBuffer;
	};
	
	void DrawWiredFrame( EffectOGL * _pEffect, VertexArray * _pVertexArray, uint32_t _nNumVert );
}

#endif // __BASIC_MODELS_H__
