//
// Created by phantom on 2015/5/21.
//

#include <cstdio>
#include <cstdlib>

#include "OpenGLViewController.h"
#include "../math/Camera.h"
#include "./AppDelegate.h"
#include "../model/models.h"
#include "../core/RenderTargetOGL.h"
#include "../core/DepthStencilOGL.h"
#include "../buffer/buffer.h"
#include "../model/md5/md5Frame.h"
#include <string.h>
#include <math.h>
#include <glfw/glfw3.h>

#define MOVE_STEP 0.5f

UISize OpenGLViewController::screenSize(DEFAULT_SCREEN_WIDTH,DEFAULT_SCREEN_HEIGHT);

namespace Graphics
{
    Size<int> GetWindowSize()
    {
        return Size<int>(OpenGLViewController::screenSize.dx,OpenGLViewController::screenSize.dy);
    }
}

void OpenGLViewController::OnInit()
{
	screenSize = UISize(DEFAULT_SCREEN_WIDTH,DEFAULT_SCREEN_HEIGHT);
    glViewport(0,0,DEFAULT_SCREEN_WIDTH, DEFAULT_SCREEN_HEIGHT);
    OnResize(DEFAULT_SCREEN_WIDTH,DEFAULT_SCREEN_HEIGHT);
    
    // 创建默认的 framebuffer object
    ClearOP clearOp;
    clearOp.bClearColor = GL_TRUE;
    float clearColors[4] = {1.0f,.5f,0.5f,1.0f};
    memcpy(&clearOp.vClearColors,clearColors,sizeof(clearColors));
    m_pRenderPipelineDefault = RenderPipelineDefault::CreateRenderPipelineDefault(&clearOp);
    
    RenderTargetDesc renderTargetDesc;
    renderTargetDesc.eFormat = PIXEL_FORMAT_RGBA8888;
    renderTargetDesc.nHeight = DEFAULT_SCREEN_HEIGHT;
    renderTargetDesc.nWidth = DEFAULT_SCREEN_WIDTH;
    RenderTargetOGL * pRenderTarget = RenderTargetOGL::CreateRenderTarget(&renderTargetDesc);
    
    DepthStencilDesc depthStencilDesc;
    depthStencilDesc.nHeight = DEFAULT_SCREEN_HEIGHT;
    depthStencilDesc.nWidth = DEFAULT_SCREEN_WIDTH;
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

    // 创建camera对象
    m_pCamera = new CCamera();
    // 
    m_lightPosition = vec4(0,125,150,1);
    m_view_light = lookAt(
            vec3(m_lightPosition.x,m_lightPosition.y,m_lightPosition.z),
            vec3(0,0,0),
            vec3(0,1,0)
        );
    m_model = glm::mat4x4(1);

    m_projection = perspective(45.f,screenSize.dx/screenSize.dy,0.001f,1000.0f);
    
    // 创建 effect 对象(内含 shader 的创建)
    const char * szVertText = 
                    #include "../glsl/md5anim.vert"
    const char * szFragText = 
                    #include "../glsl/md5anim.frag"
	const char * szVertSimpleText = 
					#include "../glsl/simple.vert"
	const char * szFragSimpleText =
					#include "../glsl/simple.frag"
	
    EffectDesc effectDesc;
    effectDesc.szPixelShaderText = szFragText;
    effectDesc.szVertexShaderText = szVertText;
    this->m_pEffectGpu = EffectOGL::CreateEffect(&effectDesc);
	effectDesc.szPixelShaderText = szFragSimpleText;
	effectDesc.szVertexShaderText = szVertSimpleText;
	this->m_pEffectCpu = EffectOGL::CreateEffect(&effectDesc);
    
   /* iBuffer * pMeshBuff = BufferFromFile("./Bob.md5mesh");
	iBuffer * pAnimBuff = BufferFromFile("./Bob.md5anim");
	// 断言
	assert(pMeshBuff && pAnimBuff);
	// 解析MD5文件
	m_pMD5File = new MD5File;
	model::md5::ParseMD5(pMeshBuff,pAnimBuff,m_pMD5File);
	
	MD5FrameInit(&m_motionFrame,m_pMD5File);
	GetMD5DefaultFrame(&m_motionFrame,m_pMD5File);
    //GetMD5KeyFrame(&m_motionFrame,m_pMD5File,5018);
    m_pMD5Model = new _MD5_::MD5Model(&m_motionFrame);
    m_pChessTex = TexOGL::CreateChessTex();
	
	Graphics::InitMD5Model(&m_GPUModel,m_pMD5File);
	CalculateAnimMatrices(&m_GPUModel,5000);
	*/
	
	m_md5Model.Init("./model/hellknight.md5mesh");
	m_md5Model.AddAnimation("./model/attack.md5anim");
	m_md5Model.AddAnimation("./model/attack2.md5anim");
	m_md5Model.AddAnimation("./model/stand.md5anim");
	m_md5Model.AddAnimation("./model/walk.md5anim");
	m_md5Model.AddAnimation("./model/roar.md5anim");
	m_md5Model.ActiveAnim(0);
	
//	for(int i = 0;i<m_pMD5Model->m_vecMeshes.size();++i)
//	{
//		m_pMD5Model->m_vecMeshes[i].m_pVertexArray->SetVertexBuffer(0,m_GPUModel.m_pMeshes[i].m_pBindposeVertexBuffer,3,0,0);
//	}
	
//    // 创建棋盘纹理
//    m_pChessTex = TexOGL::CreateChessTex();
//    iBuffer * pImageBuffer = BufferFromFile("./nagisa.png");
//    Image * pImage = Image::ImageFromPng(pImageBuffer);
//    m_pCustomTex = TexOGL::CreateTexWidthImage(pImage,true);
//    pImageBuffer->Release();
//    pImage->Release();
//    // 创建cube模型vbo 
//    m_cubeBuffer = VertexBuffer::CreateBuffer( common_model::__cube,sizeof(common_model::__cube));
//    // vao
//    m_vertexArray = VertexArray::CreateVertexArray();
//    // 顶点
//    m_vertexArray->SetVertexBuffer(0,m_cubeBuffer,3,8 * sizeof(float),0);
//    // 法线
//    m_vertexArray->SetVertexBuffer(1,m_cubeBuffer,3,8 * sizeof(float),sizeof(float) * 3);
//    // uv
//    m_vertexArray->SetVertexBuffer(2,m_cubeBuffer,2,8 * sizeof(float),sizeof(float) * 6);

    //m_modelObject.LoadModel("./Bob.md5mesh");
    //m_modelObject.LoadModel("./spider.obj");
    // 根据模型大小高速model矩阵
	 #define M_PI		3.14159265358979323846
     m_model = glm::scale<float>(glm::rotate( glm::mat4(),-(float)M_PI/2,glm::vec3(1.0f,0.0f,0.0f)),glm::vec3(0.1,0.1,0.1));
   
    //m_model = glm::translate<float>( glm::scale<float>(glm::rotate(glm::mat4(1.0), -(float)M_PI / 2,vec3(1.0f,0.0f,0.0f)),glm::vec3(10 / m_modelObject.m_fMaxBound,10 / m_modelObject.m_fMaxBound,10 / m_modelObject.m_fMaxBound)) ,-m_modelObject.m_ptCenter);;
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
            m_pCamera->RotateAxisY(-diffX);
            m_pCamera->RotateAxisX(-diffY);
            m_pCamera->ApplyRotate();
        }
        else if(event->button == eMouseButtonRight)
        {
            m_pCamera->Forward(diffY * 0.2);
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
            m_pCamera->Forward(MOVE_STEP);break;
        }
    case 'S':
        {
            m_pCamera->Forward(-MOVE_STEP);break;
        }
    case 'A':
        {
            m_pCamera->Leftward(MOVE_STEP);break;
        }
    case 'D':
        {
            m_pCamera->Rightward(MOVE_STEP);break;
        }
	case '-':
		{
			m_md5Model.m_iActivedAnimID--;
			if(m_md5Model.m_iActivedAnimID < 0)
			{
				m_md5Model.m_iActivedAnimID = m_md5Model.m_nNumAnimation - 1;
			}
			break;
		}
	case '=':
		{
			m_md5Model.m_iActivedAnimID++;
			if(m_md5Model.m_iActivedAnimID >= m_md5Model.m_nNumAnimation)
			{
				m_md5Model.m_iActivedAnimID = 0;
			}
			break;
		}
    }
}

UISize& OpenGLViewController::GetScreenSize()
{
	return screenSize;
}

void OpenGLViewController::OnUpdate()
{
	long long timepassed = (glfwGetTime() - m_startTime) * 1000;
   /* GetMD5KeyFrame(&m_motionFrame,m_pMD5File,timepassed);
	for(int i = 0;i<m_pMD5Model->m_vecMeshes.size();++i)
	{
		void * ptr = m_motionFrame.m_pMeshes[i].m_pFinalVertices->GetBuffer();
		unsigned int size =  m_motionFrame.m_pMeshes[i].m_pFinalVertices->GetLength();
		m_pMD5Model->m_vecMeshes[i].m_pVertexBuffer->SetSubData(0,ptr,size);
	}
	*/
    m_view = m_pCamera->GetMatrix();
	m_pRenderPipelineDefault->Begin();
	/*
    m_pEffectCpu->Begin();    
    m_pEffectCpu->m_pShader->SetUniformData(&m_model,"MODEL");
    m_pEffectCpu->m_pShader->SetUniformData(&m_view,"VIEW");
    m_pEffectCpu->m_pShader->SetUniformData(&m_projection,"PROJECTION");
    
    m_pMD5Model->Render(m_pEffectCpu,false);
	m_pEffectCpu->End();
	 */
	
	m_pEffectGpu->Begin();
	m_pEffectGpu->m_pShader->SetUniformData(&m_model,"MODEL");
    m_pEffectGpu->m_pShader->SetUniformData(&m_view,"VIEW");
    m_pEffectGpu->m_pShader->SetUniformData(&m_projection,"PROJECTION");
	m_md5Model.Tick(timepassed);
	m_md5Model.Render(m_pEffectGpu,true);
	//Graphics::RenderMD5(&m_GPUModel,m_pEffectGpu,timepassed);
    m_pEffectGpu->End();
	
    m_pRenderPipelineDefault->End();
    
    //glm::vec4 wiredframe_color = glm::vec4(1.0,0.0,0.0,1.0);

    //int renderMode = 0;
    
//    m_pEffect->Begin();
//    m_pEffect->m_pShader->SetUniformData(&m_model,"MODEL");
//    m_pEffect->m_pShader->SetUniformData(&m_view,"VIEW");
//    m_pEffect->m_pShader->SetUniformData(&m_projection,"PROJECTION");
    //m_pEffect->m_pShader->SetUniformData(&wiredframe_color,"WIREDFRAME_COLOR");
    //m_pEffect->m_pShader->SetUniformData(&renderMode,"RENDER_MODE");
    //m_pEffect->m_pShader->SetTexture(TEXTURE_00,m_pCustomTex);
    //m_vertexArray->Bind();
    /*
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    
    this->m_pMiniRenderPipeline->Begin();
    glDrawArrays(GL_TRIANGLES,0,36); 
    
    renderMode = 1;
    glEnable(GL_POLYGON_OFFSET_FILL);
    glPolygonOffset(0.5,1.0);
    m_pEffect->m_pShader->SetUniformData(&renderMode,"RENDER_MODE");
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    glDrawArrays(GL_TRIANGLES,0,36);
    
    this->m_pMiniRenderPipeline->End();
    m_pEffect->End();
  
    

    m_pEffect->Begin(); 
    TexOGL * pColorTex = (TexOGL*)m_pMiniRenderPipeline->GetDesc()->pRenderTargets[0]->GetColorTex();
    
    m_pEffect->m_pShader->SetTexture(TEXTURE_00,pColorTex);
      */
    //m_pRenderPipelineDefault->Begin();
    /*renderMode = 0;    
    m_pEffect->m_pShader->SetUniformData(&renderMode,"RENDER_MODE");
    
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    m_vertexArray->Draw(36);
    
    renderMode = 1;    
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);    
    glPolygonOffset(-0.5,-1.0);
    glEnable(GL_POLYGON_OFFSET_LINE);
    m_pEffect->m_pShader->SetUniformData(&renderMode,"RENDER_MODE");    
    m_vertexArray->Draw(36);
    
    glDisable(GL_POLYGON_OFFSET_LINE);
    glPolygonOffset(0,0);
    */
}

void OpenGLViewController::OnResize(unsigned width,unsigned height)
{
    if(width == 0)
        width = 1;
    if(height == 0)
        height = 1;

	screenSize.dx = width;
	screenSize.dy = height;
    glViewport(0, 0, width,height);
    
    m_projection = perspective(45.0f,(float)width/(float)height,0.01f,1000.0f);
    if(m_pRenderPipelineDefault)
        m_pRenderPipelineDefault->UpdateViewport(0,0,screenSize.dx,screenSize.dy);
}

void OpenGLViewController::Release()
{
    //this->m_cubeBuffer->Release();
    //this->m_pChessTex->Release();
    this->m_pEffectCpu->Release();
    this->m_pEffectGpu->Release();
    this->m_pMiniRenderPipeline->Release();
    this->m_pRenderPipelineDefault->Release();
	this->m_md5Model.Deinit();
    //this->m_pCustomTex->Release();
    
    delete this->m_pCamera;
    delete this;
}
