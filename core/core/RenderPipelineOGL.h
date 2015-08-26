#ifndef __RENDER_PIPELINE__
#define __RENDER_PIPELINE__

#include "device.h"

namespace Graphics
{

    struct RenderPipeline:public IRenderPipeline
    {
        RenderPipelineDesc          m_desc;
        GLuint                      m_FrameBuffer;
        
        Rect<GLint>                 m_viewport;
        Rect<GLint>                 m_scissor;
        RenderPipeline();
        
        
        bool Begin();
        void End();
        const RenderPipelineDesc * GetDesc();
        void Release();
        
        static RenderPipeline * CreateRenderPipeline( RenderPipelineDesc * _pDesc);
    };
    
    struct RenderPipelineDefault
    {
        ClearOP                     m_clearOp;
        
        Rect<GLint>                 m_viewport;
        Rect<GLint>                 m_scissor;
        
        void                        UpdateViewport(int _x,int _y,int _width,int _height);
        void                        SetScissor( int _x,int _y,int _width,int _height );
        bool                        Begin();
        void                        End();
        void                        Release();
        
        static RenderPipelineDefault * CreateRenderPipelineDefault( ClearOP * _pClear);
    };

}

#endif // __RENDER_PIPELINE__
