//
// Created by phantom on 2015/5/18.
//

#include "AppDelegate.h"
#include <gl/glew.h>
#include <cstdio>
#include <glm/glm.hpp>

#include <common/log/logger.h>
#include <common/ResourcePool.h>

ow::Logger * __logger__ = NULL;

void AppDelegate::AppWillStart()
{
    __logger__ = ow::Logger::GetInstance("./log.txt");
    assert(__logger__);
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
	InitResourcePool();
    this->m_pViewController->OnInit();
}

void AppDelegate::AppWillTerminate()
{
	ReleaseResourcePool();
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
