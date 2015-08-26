#ifndef __RENDERTARGET_OGL__
#define __RENDERTARGET_OGL__

#include "TexOGL.h"
#include "device.h"

namespace Graphics
{

    struct RenderTargetOGL:public IRenderTarget
    {
        
        RenderTargetDesc        m_desc;
        TexOGL              *   m_pTexture;
        
        static RenderTargetOGL * CreateRenderTarget( RenderTargetDesc * _pDesc);
        
        void Release();
        ITex * GetColorTex();
        RenderTargetDesc* GetDesc();
        
        RenderTargetOGL();
        ~RenderTargetOGL();
    };


}

#endif // __RENDERTARGET_OGL__
