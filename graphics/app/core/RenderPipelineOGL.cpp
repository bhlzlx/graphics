#include <gl/glew.h>
#include "RenderPipelineOGL.h"
#include "DepthStencilOGL.h"
#include "RenderTargetOGL.h"
#include "TexOGL.h"
#include <cstdlib>
#include <cstdio>
#include <assert.h>
#include <memory.h>
#include <assert.h>

namespace Graphics
{   
	RenderPipelineDefault * __pRenderPipelineMain = NULL;
	
    RenderPipeline::RenderPipeline()
    {
        
    }
    
    RenderPipeline * RenderPipeline::CreateRenderPipeline( RenderPipelineDesc * _pDesc)
    {
        // 创建fbo
        RenderPipeline * pRenderPipeline = new RenderPipeline();
        GLuint & fbo = pRenderPipeline->m_FrameBuffer;
        glGenFramebuffers(1,&fbo);        
        glBindFramebuffer(GL_FRAMEBUFFER,fbo);
        
        // 深度缓冲区
        if(_pDesc->pDepthStencil != NULL)
        {
            //
            DepthStencilOGL * pDepthStecil = static_cast<DepthStencilOGL *>(_pDesc->pDepthStencil);
            TexOGL * pDepthTex = pDepthStecil->m_pDepthTex;
//            TexOGL * pStencilTex = pDepthStecil->m_pStencilTex;
            glFramebufferTexture(GL_FRAMEBUFFER,GL_DEPTH_ATTACHMENT,pDepthTex->m_texture,0);
            //glFramebufferTexture(GL_FRAMEBUFFER,GL_STENCIL_ATTACHMENT,pStencilTex->m_texture,0);
            //
            pRenderPipeline->m_viewport = Rect<uint32_t>(_pDesc->pDepthStencil->GetDesc()->m_Size);
            pRenderPipeline->m_scissor = Rect<uint32_t>(_pDesc->pDepthStencil->GetDesc()->m_Size);
        }
        else
        {
            assert(false);
        }
        
        if(_pDesc->nRendertargetCount == 0)
        {
            glDrawBuffer(GL_NONE);
            return pRenderPipeline;
        }
        
        static char Keywords[32];
        for(int i = 0;i<_pDesc->nRendertargetCount;++i)
        {
            sprintf(Keywords,"GL_COLOR_ATTACHMENT%d",i);
            RenderTargetOGL * pRenderTarget = (RenderTargetOGL *)_pDesc->pRenderTargets[i];
            TexOGL * pTex = pRenderTarget->m_pTexture;
            glFramebufferTexture(GL_DRAW_FRAMEBUFFER,GL_COLOR_ATTACHMENT0+i,pTex->m_texture,0);            
        }
        
        GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
        if(status != GL_FRAMEBUFFER_COMPLETE)
            assert(false);
            
        memcpy(&pRenderPipeline->m_desc,_pDesc,sizeof(RenderPipelineDesc));
        
        return pRenderPipeline;
    }
    
    bool RenderPipeline::Begin()
    {   
        // bind framebuffer
        glBindFramebuffer(GL_FRAMEBUFFER,this->m_FrameBuffer);
        // viewport
        glViewport(m_viewport.x,m_viewport.y,m_viewport.width,m_viewport.height);
        // scissor 这里只是调用scissor方法，实际上还要打开开关，这个选项放在effect里
        glScissor(m_scissor.x,m_scissor.y,m_scissor.width,m_scissor.height);
        // clear color
        if(this->m_desc.clearOP.bClearColor)
        {
            glClearColor(
            m_desc.clearOP.vClearColors[0],
            m_desc.clearOP.vClearColors[1],
            m_desc.clearOP.vClearColors[2],
            m_desc.clearOP.vClearColors[3]);
            glClear(GL_COLOR_BUFFER_BIT);
        }
        if(this->m_desc.clearOP.bClearDepth)
        {
            glClearDepth(m_desc.clearOP.fDepthValue);
            glClear(GL_DEPTH_BUFFER_BIT);
        }
        return true;
    }
	
	bool RenderPipeline::Resume()
	{
		// bind framebuffer
        glBindFramebuffer(GL_FRAMEBUFFER,this->m_FrameBuffer);
        // viewport
        glViewport(m_viewport.x,m_viewport.y,m_viewport.width,m_viewport.height);
        // scissor 这里只是调用scissor方法，实际上还要打开开关，这个选项放在effect里
        glScissor(m_scissor.x,m_scissor.y,m_scissor.width,m_scissor.height);
        return true;
	}
	
	void RenderPipeline::ClearDepth()
	{
		glClearDepth(1.0f);
		glClear( GL_DEPTH_BUFFER_BIT);
	}
	
    void RenderPipeline::End()
    {
        return;
    }
	
    const RenderPipelineDesc * RenderPipeline::GetDesc()
    {
        return &this->m_desc;
    }
    
    void RenderPipeline::Release()
    {
        glDeleteFramebuffers(1,&this->m_FrameBuffer);
        this->m_desc.pDepthStencil->Release();
        for(int i = 0;i<m_desc.nRendertargetCount;++i)
        {
            m_desc.pRenderTargets[i]->Release();
        }
        delete this;
    }
    

    bool   RenderPipelineDefault::Begin()
    {
        // 绑定默认FBO
        glBindFramebuffer(GL_FRAMEBUFFER,0);
        // clear color
        if(this->m_clearOp.bClearColor)
        {
            glClearColor(
            m_clearOp.vClearColors[0],
            m_clearOp.vClearColors[1],
            m_clearOp.vClearColors[2],
            m_clearOp.vClearColors[3]);
            glClear(GL_COLOR_BUFFER_BIT);
        }
        
        if(m_clearOp.bClearDepth)
        {
            glClearDepth(m_clearOp.fDepthValue);
            glClear(GL_DEPTH_BUFFER_BIT);
        }
        // viewport
        glViewport(m_viewport.x,m_viewport.y,m_viewport.width,m_viewport.height);
        // scissor 这里只是调用scissor方法，实际上还要打开开关，这个选项放在effect里
        glScissor(m_scissor.x,m_scissor.y,m_scissor.width,m_scissor.height);
        return true;
    }
	
	bool RenderPipelineDefault::Resume()
	{
		// 绑定默认FBO
        glBindFramebuffer(GL_FRAMEBUFFER,0);
        // viewport
        glViewport(m_viewport.x,m_viewport.y,m_viewport.width,m_viewport.height);
        // scissor 这里只是调用scissor方法，实际上还要打开开关，这个选项放在effect里
        glScissor(m_scissor.x,m_scissor.y,m_scissor.width,m_scissor.height);
        return true;
	}
    
    void RenderPipelineDefault::UpdateViewport(int _x,int _y,int _width,int _height)
    {
        m_viewport = Rect<int>(_x,_y,_width,_height);
    }
    
    void RenderPipelineDefault::SetScissor( int _x,int _y,int _width,int _height )
    {
        m_scissor = Rect<int>(_x,_y,_width,_height);
    }
	
	void RenderPipelineDefault::ClearDepth()
	{
		glClearDepth(1.0f);
		glClear( GL_DEPTH_BUFFER_BIT);
	}
    
    void RenderPipelineDefault::End()
    {
        
    }
    
    void RenderPipelineDefault::Release()
    {
        delete this;
    }
    
    RenderPipelineDefault * Graphics::RenderPipelineDefault::GetRenderPipelineDefault(ClearOP* _pClear)
    {
		if( __pRenderPipelineMain == NULL)
		{
			__pRenderPipelineMain = new RenderPipelineDefault();
			memcpy(&__pRenderPipelineMain->m_clearOp,_pClear,sizeof(ClearOP));
			Size<int> wndSize = GetWindowSize();
			__pRenderPipelineMain->m_viewport = Rect<int>(0,0,wndSize.width,wndSize.height);
			__pRenderPipelineMain->m_scissor = Rect<int>(0,0,wndSize.width,wndSize.height);
		}
        return __pRenderPipelineMain;
    }
}





