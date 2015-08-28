//
// Created by phantom on 2015/5/21.
//
#ifndef GRAPHICSLIBRARY_OPENGLVIEWCONTROLLER_H
#define GRAPHICSLIBRARY_OPENGLVIEWCONTROLLER_H
#include <gl/glew.h>
#include <stdint.h>

#include <model/md5parser/md5Model.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <event/MouseEvent.h>
#include <math/Camera.h>

#include <core/ShaderOGL.h>
#include <core/UICommon.h>
#include <core/EffectOGL.h>
#include <core/BufferOGL.h>
#include <core/RenderPipelineOGL.h>




using namespace UI;
using namespace Graphics;
using namespace glm;

struct OpenGLViewController
{
	double 				m_startTime;
    RenderPipelineDefault * \
                        m_pRenderPipelineDefault;
    RenderPipeline*         \
                        m_pMiniRenderPipeline;
    
	EffectOGL*			m_pEffectCpu;
    EffectOGL*          m_pEffectGpu;
    VertexBuffer*       m_cubeBuffer;
    VertexArray*        m_vertexArray;
    TexOGL*             m_pChessTex;
    TexOGL*             m_pCustomTex;
    
   // CModelParser        m_modelObject;
    
    //_MD5_::MD5Model*    m_pMD5Model;
	//MD5FilePtr			m_pMD5File;
	//MD5Frame			m_motionFrame;
	
	md5Model			m_md5Model;
	//Graphics::MD5Model  m_GPUModel;
	
	
    
	wchar_t				m_szTextSample[1024];

    mat4                m_projection;
    mat4                m_view;
    mat4                m_model;

    mat4                m_view_light;
    vec4                m_lightPosition;
    float               m_lightRotation;
    
    static UISize              screenSize;

    CCamera *           m_pCamera;

    OpenGLViewController();
    
    UISize & GetScreenSize();

    void OnMouseEvent(MouseEvent * event);
    void OnResize(unsigned width,unsigned height);
    void OnInit();

    void OnUpdate();
    void OnTimer();
    void Release();

    void OnKeyPressed(unsigned char key, int x, int y);
};


#endif //GRAPHICSLIBRARY_OPENGLVIEWCONTROLLER_H
