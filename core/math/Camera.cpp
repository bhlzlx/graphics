//
// Created by phantom on 2015/5/27 0027.
//

#include "Camera.h"
#include <cstring>
#include <cstdio>

#define M_PI		3.14159265358979323846

const vec4 default_normal = vec4(0,0,-1,0);
const vec4 default_top = vec4(0,1,0,0);
const vec4 default_left = vec4(-1,0,0,0);

CCamera  gameCamera;

void CCamera::RotateAxisX(float angle)
{
    // xÖá·½Ïò¿ØÖÆÔÚ -90~90Ö®¼ä
    this->m_axis_x += angle;
    if(m_axis_x > 90)
        m_axis_x = 90;
    else if(m_axis_x < -90)
        m_axis_x = -90;
}

void CCamera::RotateAxisY(float angle)
{
    // ¿ØÖÆºÃyÖáÐý×ª½Ç¶È
    this->m_axis_y += angle;
    if(m_axis_y > 360)
        m_axis_y -= 360;
    else if(m_axis_y < -360)
        m_axis_y += 360;
	//printf("axis y : %f",m_axis_y);
}

void CCamera::Forward(float iden)
{
    vec4 forward_vec = glm::inverse(m_rotateMatrix) * default_normal;
    m_position += forward_vec * (float)iden;
    // ¼ÆËãÄ£ÐÍµÄÎ»ÒÆ¾ØÕó
    vec4 modelOffset = m_position * -1.0f;
    m_offsetMatrix = glm::translate(mat4(1.0),vec3(modelOffset.x,modelOffset.y,modelOffset.z));
    // Ó¦ÓÃÎ»ÒÆ
    m_viewMatrix = m_rotateMatrix * m_offsetMatrix;
}

void CCamera::Leftward(float iden)
{
    vec4 leftward_vec = glm::inverse(m_rotateMatrix) * default_left;
    m_position += leftward_vec * (float)iden;
    // ¼ÆËãÄ£ÐÍµÄÎ»ÒÆ¾ØÕó
    vec4 modelOffset = m_position * -1.0f;
    m_offsetMatrix = glm::translate(mat4(1.0),vec3(modelOffset.x,modelOffset.y,modelOffset.z));
    // Ó¦ÓÃÎ»ÒÆ
    m_viewMatrix = m_rotateMatrix * m_offsetMatrix;
}
void CCamera::Rightward(float iden)
{
    vec4 leftward_vec = glm::inverse(m_rotateMatrix) * default_left;
    m_position -= leftward_vec * (float)iden;
    // ¼ÆËãÄ£ÐÍµÄÎ»ÒÆ¾ØÕó
    vec4 modelOffset = m_position * -1.0f;
    m_offsetMatrix = glm::translate(mat4(1.0),vec3(modelOffset.x,modelOffset.y,modelOffset.z));
    // Ó¦ÓÃÎ»ÒÆ
    m_viewMatrix = m_rotateMatrix * m_offsetMatrix;
}

void CCamera::Translate(vec4 &offset)
{
   /* m_position += offset;
    // Ó¦ÓÃÎ»ÒÆ
    vec4 modelOffset = -m_position;
    memcpy(&m_viewMatrix[3][0],&modelOffset[0],sizeof(modelOffset));
    */
}

void CCamera::ApplyRotate()
{
    // Ó¦ÓÃÐý×ª
    // ÊÀ½çÎïÌå×ø±ê±ä»»ºÍÏà»úµÄ±ä»»Ïà·´
    mat4 rotatex = glm::rotate<float>(glm::mat4(1.0),-m_axis_x / 180.0f * M_PI,vec3(1,0,0));
    m_rotateMatrix = glm::rotate<float>(rotatex,-m_axis_y / 180.0f * M_PI,vec3(0,1,0));
    // Ó¦ÓÃÎ»ÒÆ
    m_viewMatrix = m_rotateMatrix * m_offsetMatrix;
   // memcpy(&m_viewMatrix[3][0],&modelOffset[0],sizeof(float)*3);
}

mat4& CCamera::GetViewMatrix()
{
	return m_viewMatrix;
}

mat4& CCamera::GetProjectionMatrix()
{
	return m_projectionMatrix;
}

vec4& CCamera::GetPosition()
{
    return m_position;
}

CCamera::CCamera()
{
    m_position = vec4(0,0,0,1);
	m_axis_x = 0;
	m_axis_y = 0;
}


CCamera * GetGameCamera()
{
	return &gameCamera;
}