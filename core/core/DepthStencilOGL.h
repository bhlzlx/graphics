#ifndef __DEPTH_STENCIL_OGL__
#define __DEPTH_STENCIL_OGL__

#include "device.h"
#include <gl/gl.h>
#include "TexOGL.h"

namespace Graphics
{

    struct DepthStencilOGL:public IDepthStencil
    {
        TexOGL*                     m_pDepthTex;
        //TexOGL*                     m_pStencilTex;
        DepthStencilDesc            m_desc;
        
        const DepthStencilDesc * GetDesc();
        
        void Release();
        
        static DepthStencilOGL * CreateDepthStencil(DepthStencilDesc * _pDesc);
    };

}

#endif // __DEPTH_STENCIL_OGL__
