//
// Created by phantom on 2015/5/27 0027.
//

#include "Camera.h"
#include <cstring>
#include <cstdio>

#define M_PI		3.14159265358979323846

const vec4 default_normal       = vec4(0,0,-1,0);
const vec4 default_top          = vec4(0,1,0,0);
const vec4 default_left         = vec4(-1,0,0,0);

void CCamera::RotateAxisX(float angle)
{
    this->m_quat_x = glm::rotate<float>(m_quat_x, - angle / 180 * M_PI,vec3(1,0,0));
}

void CCamera::RotateAxisY(float angle)
{
    this->m_quat_y = glm::rotate<float>(m_quat_y, - angle / 180 * M_PI,vec3(0,1,0));
}

void CCamera::Forward(float iden)
{
    vec4 forward_vec = glm::inverse(m_rotateMatrix) * default_normal;
    m_position += forward_vec * (float)iden;
    vec4 modelOffset = m_position * -1.0f;
    m_offsetMatrix = glm::translate(mat4(1.0),vec3(modelOffset.x,modelOffset.y,modelOffset.z));
    m_viewMatrix = m_rotateMatrix * m_offsetMatrix;
}

void CCamera::Leftward(float iden)
{
    vec4 leftward_vec = glm::inverse(m_rotateMatrix) * default_left;
    m_position += leftward_vec * (float)iden;
    vec4 modelOffset = m_position * -1.0f;
    m_offsetMatrix = glm::translate(mat4(1.0),vec3(modelOffset.x,modelOffset.y,modelOffset.z));
    m_viewMatrix = m_rotateMatrix * m_offsetMatrix;
}
void CCamera::Rightward(float iden)
{
    vec4 leftward_vec = glm::inverse(m_rotateMatrix) * default_left;
    m_position -= leftward_vec * (float)iden;
    vec4 modelOffset = m_position * -1.0f;
    m_offsetMatrix = glm::translate(mat4(1.0),vec3(modelOffset.x,modelOffset.y,modelOffset.z));
    m_viewMatrix = m_rotateMatrix * m_offsetMatrix;
}

void CCamera::Translate(vec4 &offset)
{
}

void CCamera::ApplyRotate()
{
    m_rotateMatrix = glm::mat4_cast((m_quat_x * m_quat_y));
    m_viewMatrix = m_rotateMatrix * m_offsetMatrix;
}

mat4& CCamera::GetMatrix()
{
    return m_viewMatrix;
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
