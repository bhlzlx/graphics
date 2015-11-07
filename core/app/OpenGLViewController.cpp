//
// Created by phantom on 2015/5/21.
//
#include <gl/glew.h>
#include <cstdio>
#include <cstdlib>
#include <glfw/glfw3.h>
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
#include <owcmn/resources.h>
#include <owcmn/owcmn.h>
#include <package/owPackage.h>
#include <owcmn/log/logger.h>
#include <excel/excel_def.h>
#include <owcmn/owstring.h>

using namespace ow::excel;
const char * szConfigPath = "./config.txt";

const uint16_t STRING_TEST[2] = {0x4f60,0x597d};

#define MOVE_STEP 0.5f

OpenGLViewController * __pViewController = NULL;

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
	m_pAudioManager = app::GetAudioManager();
	//m_pAudioManager->PlaySound2D( 1 );
	m_pAudioManager->PlayMusic( 1,0 );
	
	__pViewController = this;
	
	m_pGameCamera = GetGameCamera();
	m_viewport.width = DEFAULT_SCREEN_WIDTH;
	m_viewport.height = DEFAULT_SCREEN_HEIGHT;
	
    glViewport(0,0,DEFAULT_SCREEN_WIDTH, DEFAULT_SCREEN_HEIGHT);
    OnResize(DEFAULT_SCREEN_WIDTH,DEFAULT_SCREEN_HEIGHT);
    
    // 创建默认的 framebuffer object
    ClearOP clearOp;
    clearOp.bClearColor = GL_TRUE;
    float clearColors[4] = { 0.8f,0.8f,0.8f,1.0f };
    memcpy(&clearOp.vClearColors,clearColors,sizeof(clearColors));
    m_pRenderPipelineDefault = RenderPipelineDefault::GetRenderPipelineDefault(&clearOp);
    
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
	m_pTextRenderer = GetTextRenderer();
	
	m_pGuiRenderer = new gui::GuiRenderer();
	m_pGuiRenderer->Init();
	Rect<float> labelRect(0,0,512,32);
	
	l_Preference * pLine = t_Preference.GetLineById(1);
	float lableFontSize = pLine->fValue;
	float r,g,b,a;
	r = t_Preference.GetLineById(2)->fValue;
	g = t_Preference.GetLineById(3)->fValue;
	b = t_Preference.GetLineById(4)->fValue;
	a = t_Preference.GetLineById(5)->fValue;
	glm::vec4 labelColor = glm::vec4(r,g,b,a);

	// 将utf8转换为unicode编码
	char * szText = t_Preference.GetLineById(6)->szString;
	owBuffer * pUTFBuffer = CreateMemBuffer( strlen( szText) * 2);
	char* ptr_out = (char*)pUTFBuffer->GetBuffer();
	uint32_t count = utf82ucsle(szText,strlen(szText),ptr_out,pUTFBuffer->Size());
	
	m_pLabel = gui::Label::CreateLabel( labelRect, labelColor, lableFontSize);
	m_pLabel->m_szText = new uint16_t[count + 1];
	m_pLabel->m_szText[count] = 0;
	memcpy(m_pLabel->m_szText, pUTFBuffer->GetBuffer(),sizeof(uint16_t) * count);
	pUTFBuffer->Release();
	m_pLabel->m_nTextLen = count;
}

void OpenGLViewController::OnUpdate()
{
	long long timepassed = (glfwGetTime() - m_startTime) * 1000;
	
	m_pRenderPipelineDefault->Begin();
	m_gameScene.Render(timepassed);

	m_pGuiRenderer->Render( m_pLabel);
	
    m_pRenderPipelineDefault->End();
}

void OpenGLViewController::OnTimer()
{
	//m_pVorbisSource->UpdateBuffer();
}

OpenGLViewController::OpenGLViewController()
{
	m_lightRotation = 0;
	m_pRenderPipelineDefault = NULL;
	m_pMiniRenderPipeline = NULL;	
	m_pGameCamera = NULL;
	m_pGuiRenderer = NULL;
	m_pLabel = NULL;
	m_pAudioManager = NULL;
	m_pTextRenderer = NULL;
	
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
	this->m_pAudioManager->Release();
    delete this;
}
