#ifndef __RENDER_PIPELINE__
#define __RENDER_PIPELINE__

#include <core/device.h>

namespace Graphics
{

    struct RenderPipeline:public IRenderPipeline
    {
        RenderPipelineDesc				m_desc;
        GLuint							m_FrameBuffer;
        
        Rect<uint32_t>					m_viewport;
        Rect<uint32_t>					m_scissor;
        RenderPipeline();

        bool Begin();
		bool Resume();
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
		bool						Resume();
        void                        End();
        void                        Release();
        
        static RenderPipelineDefault * GetRenderPipelineDefault( ClearOP * _pClear);
    };
	
	RenderPipelineDefault * GetRenderPipelineDefault();
}

#endif // __RENDER_PIPELINE__
