#ifndef __MD5_MODEL_H__
#define __MD5_MODEL_H__

#include <EffectOGL.h>
#include <TexOGL.h>
#include <BufferOGL.h>
#include "md5/md5Frame.h"
#include <vector>

using namespace Graphics;

namespace _MD5_
{
    struct MD5Mesh
    {
        unsigned int    					m_nNumVertices;
        Graphics::VertexBuffer *  			m_pVertexBuffer;
        Graphics::VertexBuffer *  			m_pUVBuffer;
        Graphics::VertexBuffer*   			m_pIndexBuffer;
        Graphics::VertexArray*    			m_pVertexArray;
		Graphics::TexOGL*					m_pTexture;
    };

    class MD5Model
    {
        public:
        std::vector<MD5Mesh>    			m_vecMeshes;
        MD5Model(MD5FramePtr _pFrame);
        
        void Render(Graphics::EffectOGL * _pEffect, bool _wiredframe);
    };

}

#endif // __MD5_MODEL_H__
