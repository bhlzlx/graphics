//
// Created by phantom on 2015/5/21.
//
#ifndef GRAPHICSLIBRARY_OPENGLVIEWCONTROLLER_H
#define GRAPHICSLIBRARY_OPENGLVIEWCONTROLLER_H
#include <gl/glew.h>
#include <stdint.h>

#include <scene/GameScene.h>
#include <model/md5parser/md5Model.h>
#include <event/MouseEvent.h>
#include <math/Camera.h>

#include <core/ShaderOGL.h>
#include <core/EffectOGL.h>
#include <core/BufferOGL.h>
#include <core/RenderPipelineOGL.h>
#include <core/renderer/TextRenderer.h>
#include <gui/Label.h>
#include <audio/owAudio.h>
#include <audio/owAEPlayer.h>
#include <package/owPackage.h>

using namespace Graphics;
using namespace glm;

struct OpenGLViewController
{
	double 				m_startTime;
    RenderPipelineDefault * \
                        m_pRenderPipelineDefault;
    RenderPipeline*         \
                        m_pMiniRenderPipeline;

	GameScene			m_gameScene;
	
	ow::owPackage*		m_pPackage;
    
	wchar_t				m_szTextSample[1024];
	
    mat4                m_view_light;
    vec4                m_lightPosition;
    float               m_lightRotation;
	
	Rect<uint32_t>		m_viewport;
	
    CCamera *           m_pGameCamera;
	
	TextRenderer*		m_pTextRenderer;
	
	gui::GuiRenderer*	m_pGuiRenderer;
	gui::Label*			m_pLabel;
	
	ow::owAEDevice*		m_pAudioDevice;
	ow::owAEMusicPlayer * m_pPlayer;;

    OpenGLViewController();

    void OnMouseEvent(MouseEvent * event);
    void OnResize(unsigned width,unsigned height);
    void OnInit();

    void OnUpdate();
    void OnTimer();
    void Release();

    void OnKeyPressed(unsigned char key, int x, int y);
};

extern OpenGLViewController * __pViewController;


#endif //GRAPHICSLIBRARY_OPENGLVIEWCONTROLLER_H
