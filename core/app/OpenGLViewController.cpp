//
// Created by phantom on 2015/5/21.
//

#include <cstdio>
#include <cstdlib>

#include "OpenGLViewController.h"
#include <math/Camera.h>
#include <app/AppDelegate.h>
#include <model/models.h>
#include <core/RenderTargetOGL.h>
#include <core/DepthStencilOGL.h>
#include <buffer/buffer.h>
#include <model/md5/md5Frame.h>
#include <string.h>
#include <math.h>
#include <glfw/glfw3.h>

const uint16_t STRING_TEST[2] = {0x4f60,0x597d};

#define MOVE_STEP 0.5f

OpenGLViewController * __pViewController = NULL;

TexOGL*	textRenderTestTex = NULL;

namespace Graphics
{
    Size<int>& GetWindowSize()
    {
		static Size<int> size;
		size.height = __pViewController->m_viewport.height;
		size.width = __pViewController->m_viewport.width;
		return size;
    }
}

void OpenGLViewController::OnInit()
{
	__pViewController = this;
	m_pGameCamera = GetGameCamera();
	
	m_viewport.width = DEFAULT_SCREEN_WIDTH;
	m_viewport.height = DEFAULT_SCREEN_HEIGHT;
	
    glViewport(0,0,DEFAULT_SCREEN_WIDTH, DEFAULT_SCREEN_HEIGHT);
    OnResize(DEFAULT_SCREEN_WIDTH,DEFAULT_SCREEN_HEIGHT);
    
    // 创建默认的 framebuffer object
    ClearOP clearOp;
    clearOp.bClearColor = GL_TRUE;
    float clearColors[4] = {.8f,0.8f,0.8f,1.0f};
    memcpy(&clearOp.vClearColors,clearColors,sizeof(clearColors));
    m_pRenderPipelineDefault = RenderPipelineDefault::CreateRenderPipelineDefault(&clearOp);
    
    RenderTargetDesc renderTargetDesc;
    renderTargetDesc.eFormat = PIXEL_FORMAT_RGBA8888;
    renderTargetDesc.m_Size.height = DEFAULT_SCREEN_HEIGHT;
    renderTargetDesc.m_Size.width = DEFAULT_SCREEN_WIDTH;
    RenderTargetOGL * pRenderTarget = RenderTargetOGL::CreateRenderTarget(&renderTargetDesc);
    
    DepthStencilDesc depthStencilDesc;
    depthStencilDesc.m_Size.height = DEFAULT_SCREEN_HEIGHT;
    depthStencilDesc.m_Size.width = DEFAULT_SCREEN_WIDTH;
    DepthStencilOGL * pDepthStencil = DepthStencilOGL::CreateDepthStencil(&depthStencilDesc);
    
    RenderPipelineDesc renderPipelineDesc;
    renderPipelineDesc.pDepthStencil = pDepthStencil;
    renderPipelineDesc.nRendertargetCount = 1;
    renderPipelineDesc.pRenderTargets[0] =  pRenderTarget;
    renderPipelineDesc.clearOP.bClearColor = true;
    renderPipelineDesc.clearOP.SetClearColor(1.0f,1.0f,1.0f,1.0f);
    renderPipelineDesc.clearOP.bClearDepth = true;
    renderPipelineDesc.clearOP.fDepthValue = 1.0f;
    
    m_pMiniRenderPipeline = RenderPipeline::CreateRenderPipeline( &renderPipelineDesc);
	
	m_pGameCamera->m_projectionMatrix = perspective(45.f,(float)m_viewport.width/(float)m_viewport.height,0.001f,1000.0f);
	
	m_gameScene.Init();
	
	m_pTextRenderer = new TextRenderer;
	//m_pTextRenderer->Init( "msyh.ttf", "charlib.txt");
	m_pTextRenderer->Init( "liukai.ttf", "charlib.txt");
	
}

void OpenGLViewController::OnUpdate()
{
	long long timepassed = (glfwGetTime() - m_startTime) * 1000;
	static Size<uint32_t> offset = {
			0,0
		};
	if( textRenderTestTex == NULL)
	{
		textRenderTestTex = Graphics::TexOGL::CreateChessTex();
		m_pTextRenderer->Render( textRenderTestTex, offset, &STRING_TEST[0], 2, 0.5f);
	}
	
	m_pRenderPipelineDefault->Begin();
	m_gameScene.Render(timepassed);
	
    m_pRenderPipelineDefault->End();
}

void OpenGLViewController::OnTimer()
{
	
}

OpenGLViewController::OpenGLViewController()
{
	m_lightRotation = 0;
	m_pRenderPipelineDefault = NULL;
	m_pMiniRenderPipeline = NULL;
	m_startTime = glfwGetTime();
}

void OpenGLViewController::OnMouseEvent(MouseEvent * event)
{
	//event->Trace();
    float diffX = event->currX - event->lastX;
    float diffY = event->currY - event->lastY;
    if(event->eventType == eMouseMove)
    {
        if(event->button == eMouseButtonLeft)
        {
            m_pGameCamera->RotateAxisY(-diffX);
            m_pGameCamera->RotateAxisX(-diffY);
            m_pGameCamera->ApplyRotate();
        }
        else if(event->button == eMouseButtonRight)
        {
            m_pGameCamera->Forward(diffY * 0.2);
        }
    }
}

void OpenGLViewController::OnKeyPressed(unsigned char key, int x, int y)
{
    //printf("key : %c pressed...\n",key);
    switch(key)
    {
    case 'W':
        {
            m_pGameCamera->Forward(MOVE_STEP);break;
        }
    case 'S':
        {
            m_pGameCamera->Forward(-MOVE_STEP);break;
        }
    case 'A':
        {
            m_pGameCamera->Leftward(MOVE_STEP);break;
        }
    case 'D':
        {
            m_pGameCamera->Rightward(MOVE_STEP);break;
        }
	case 'B':
		{
			printf("break");
			break;
		}
	case 'P':
		{
			break;
		}
//	case '-':
//		{
//			m_md5Model.m_iActivedAnimID--;
//			if(m_md5Model.m_iActivedAnimID < 0)
//			{w
//				m_md5Model.m_iActivedAnimID = m_md5Model.m_nNumAnimation - 1;b
//			}
//			break;
//		}
//	case '=':
//		{
//			m_md5Model.m_iActivedAnimID++;
//			if(m_md5Model.m_iActivedAnimID >= m_md5Model.m_nNumAnimation)
//			{
//				m_md5Model.m_iActivedAnimID = 0;
//			}
//			break;
//		}
    }
}

void OpenGLViewController::OnResize(unsigned width,unsigned height)
{
    if(width == 0)
        width = 1;
    if(height == 0)
        height = 1;

	m_viewport.x = 0;
	m_viewport.y = 0;
	m_viewport.width = width;
	m_viewport.height = height;
	
	m_pGameCamera->m_projectionMatrix = perspective(45.0f,(float)width/(float)height,0.01f,1000.0f);
	
    if(m_pRenderPipelineDefault)
	{
        m_pRenderPipelineDefault->UpdateViewport(0,0,m_viewport.width,m_viewport.height);
	}
}

void OpenGLViewController::Release()
{
    this->m_pMiniRenderPipeline->Release();
    this->m_pRenderPipelineDefault->Release();
    delete this;
}
