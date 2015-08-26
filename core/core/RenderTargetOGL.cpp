#include "RenderTargetOGL.h"
#include <memory.h>

namespace Graphics
{

    RenderTargetOGL::RenderTargetOGL()
    {
    }

    RenderTargetOGL::~RenderTargetOGL()
    {
    }
    
    RenderTargetOGL * RenderTargetOGL::CreateRenderTarget( RenderTargetDesc * _pDesc)
    {
        RenderTargetOGL * pRenderTarget = new RenderTargetOGL;
        memcpy(&pRenderTarget->m_desc,_pDesc,sizeof(RenderTargetDesc));
        // 创建纹理
        TexDesc texDesc;
        texDesc.ePixelFormat = _pDesc->eFormat;
        texDesc.eTexClass = TEX_CLASS_RENDERTARGET;
        texDesc.nSizeX = _pDesc->nWidth;
        texDesc.nSizeY = _pDesc->nHeight;
        pRenderTarget->m_pTexture = TexOGL::CreateTex(&texDesc);
        // 创建rbo
        // rbo不以纹理的方式创建，所以不用rbo了
        return pRenderTarget;
    }
    
    void RenderTargetOGL::Release()
    {
        this->m_pTexture->Release();
        delete this;
    }
    
    ITex * RenderTargetOGL::GetColorTex()
    {
        return this->m_pTexture;
    }
    
    RenderTargetDesc* RenderTargetOGL::GetDesc()
    {
        &this->m_desc;
    }
    


}

