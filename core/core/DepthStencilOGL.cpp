#include <gl/glew.h>
#include "DepthStencilOGL.h"
#include <cstring>
namespace Graphics
{
    
    const DepthStencilDesc * DepthStencilOGL::GetDesc()
    {
        return &this->m_desc;
    }
    
    void DepthStencilOGL::Release()
    {
        if(this->m_pDepthTex)
        {
            m_pDepthTex->Release();
            m_pDepthTex = NULL;
        }
        delete this;
    }
    
    DepthStencilOGL * DepthStencilOGL::CreateDepthStencil(DepthStencilDesc * _pDesc)
    {
        DepthStencilOGL * pDepthStencil = new DepthStencilOGL();
        memcpy(&pDepthStencil->m_desc,_pDesc,sizeof(DepthStencilDesc));
        TexDesc texDesc;
		texDesc.size = _pDesc->m_Size;
        texDesc.eTexClass = TEX_CLASS_RENDERTARGET;
        texDesc.ePixelFormat = PIXEL_FORMAT_DEPTH_32;
        pDepthStencil->m_pDepthTex = TexOGL::CreateTex(&texDesc);
        //texDesc.ePixelFormat = PIXEL_FORMAT_STENCIL_8;
        //pDepthStencil->m_pStencilTex = TexOGL::CreateTex(&texDesc);
        return pDepthStencil;
    }
}

