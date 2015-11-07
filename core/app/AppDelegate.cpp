//
// Created by phantom on 2015/5/18.
//

#include "AppDelegate.h"
#include <gl/glew.h>
#include <cstdio>
#include <glm/glm.hpp>
#include <archive/owArchive.h>
#include <owcmn/log/logger.h>
#include <owcmn/resources.h>

using namespace ow;

ow::Logger * __logger__ = NULL;

void AppDelegate::AppWillStart()
{
	owArchive * pArchive = NULL;
	pArchive = ow::GetArchive();
	pArchive->Init(".","./package.pkg");
	
    __logger__ = ow::Logger::GetInstance("./log.txt");
    assert(__logger__);
	// 初始化文件包
    m_pViewController = new OpenGLViewController();
}

void AppDelegate::AppMouseAction(MouseEvent * event)
{
    //event->Trace();
    m_pViewController->OnMouseEvent(event);
}

void AppDelegate::AppDidStart()
{
    printf("OpenGL Application Started~\n");
	resource::Init();
    this->m_pViewController->OnInit();
}

void AppDelegate::AppWillTerminate()
{
	resource::Release();
    m_pViewController->Release();
}

void AppDelegate::AppWindowDidResize(uint32 width,uint32 height)
{
    m_pViewController->OnResize(width,height);
}

void AppDelegate::AppKeyPressed(unsigned char key, int x, int y)
{
    m_pViewController->OnKeyPressed(key,x,y);
}

void AppDelegate::AppOnUpdate()
{
    m_pViewController->OnUpdate();
}

void AppDelegate::AppOnTimer()
{
    m_pViewController->OnTimer();
}
