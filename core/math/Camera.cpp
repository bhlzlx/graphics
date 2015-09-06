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
	m_vpMat = m_projectionMatrix * m_viewMatrix;
	updateFrustumPlane();
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
	m_vpMat = m_projectionMatrix * m_viewMatrix;
	updateFrustumPlane();
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
	m_vpMat = m_projectionMatrix * m_viewMatrix;
	updateFrustumPlane();
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
	m_vpMat = m_projectionMatrix * m_viewMatrix;
	updateFrustumPlane();
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

bool CCamera::InFrustumBoundBox(float _x, float _y, float _z)
{
	//printf("x : %05f y : %05f z : %05f \n",_x,_y,_z);
	for( int i = 0; i < 6; ++i )
    {
        if( g_frustumPlanes[i][0] * _x +
            g_frustumPlanes[i][1] * _y +
            g_frustumPlanes[i][2] * _z +
            g_frustumPlanes[i][3] <= 0)
            return false;
    }

    return true;
}

void CCamera::updateFrustumPlane()
{
	float * matPtr = (float *)&m_vpMat;
	float t = 0.0f;
	g_frustumPlanes[0][0] = matPtr[3] - matPtr[0];
    g_frustumPlanes[0][1] = matPtr[7] - matPtr[4];
    g_frustumPlanes[0][2] = matPtr[11] - matPtr[8];
    g_frustumPlanes[0][3] = matPtr[15] - matPtr[12];

    t = (float) sqrt( g_frustumPlanes[0][0] * g_frustumPlanes[0][0] +
                      g_frustumPlanes[0][1] * g_frustumPlanes[0][1] +
                      g_frustumPlanes[0][2] * g_frustumPlanes[0][2] );

    g_frustumPlanes[0][0] /= t;
    g_frustumPlanes[0][1] /= t;
    g_frustumPlanes[0][2] /= t;
    g_frustumPlanes[0][3] /= t;

    //
    // Extract the frustum's left clipping plane and normalize it.
    //

    g_frustumPlanes[1][0] = matPtr[ 3] + matPtr[ 0];
    g_frustumPlanes[1][1] = matPtr[ 7] + matPtr[ 4];
    g_frustumPlanes[1][2] = matPtr[11] + matPtr[ 8];
    g_frustumPlanes[1][3] = matPtr[15] + matPtr[12];

    t = (float) sqrt( g_frustumPlanes[1][0] * g_frustumPlanes[1][0] +
                      g_frustumPlanes[1][1] * g_frustumPlanes[1][1] +
                      g_frustumPlanes[1][2] * g_frustumPlanes[1][2] );

    g_frustumPlanes[1][0] /= t;
    g_frustumPlanes[1][1] /= t;
    g_frustumPlanes[1][2] /= t;
    g_frustumPlanes[1][3] /= t;
    //
    // Extract the frustum's bottom clipping plane and normalize it.
    //
    g_frustumPlanes[2][0] = matPtr[ 3] + matPtr[ 1];
    g_frustumPlanes[2][1] = matPtr[ 7] + matPtr[ 5];
    g_frustumPlanes[2][2] = matPtr[11] + matPtr[ 9];
    g_frustumPlanes[2][3] = matPtr[15] + matPtr[13];

    t = (float) sqrt( g_frustumPlanes[2][0] * g_frustumPlanes[2][0] +
                      g_frustumPlanes[2][1] * g_frustumPlanes[2][1] +
                      g_frustumPlanes[2][2] * g_frustumPlanes[2][2] );

    g_frustumPlanes[2][0] /= t;
    g_frustumPlanes[2][1] /= t;
    g_frustumPlanes[2][2] /= t;
    g_frustumPlanes[2][3] /= t;

    //
    // Extract the frustum's top clipping plane and normalize it.
    //

    g_frustumPlanes[3][0] = matPtr[ 3] - matPtr[ 1];
    g_frustumPlanes[3][1] = matPtr[ 7] - matPtr[ 5];
    g_frustumPlanes[3][2] = matPtr[11] - matPtr[ 9];
    g_frustumPlanes[3][3] = matPtr[15] - matPtr[13];

    t = (float) sqrt( g_frustumPlanes[3][0] * g_frustumPlanes[3][0] +
                      g_frustumPlanes[3][1] * g_frustumPlanes[3][1] +
                      g_frustumPlanes[3][2] * g_frustumPlanes[3][2] );

    g_frustumPlanes[3][0] /= t;
    g_frustumPlanes[3][1] /= t;
    g_frustumPlanes[3][2] /= t;
    g_frustumPlanes[3][3] /= t;



    //
    // Extract the frustum's far clipping plane and normalize it.
    //

    g_frustumPlanes[4][0] = matPtr[ 3] - matPtr[ 2];
    g_frustumPlanes[4][1] = matPtr[ 7] - matPtr[ 6];
    g_frustumPlanes[4][2] = matPtr[11] - matPtr[10];
    g_frustumPlanes[4][3] = matPtr[15] - matPtr[14];

    t = (float) sqrt( g_frustumPlanes[4][0] * g_frustumPlanes[4][0] +
                      g_frustumPlanes[4][1] * g_frustumPlanes[4][1] +
                      g_frustumPlanes[4][2] * g_frustumPlanes[4][2] );

    g_frustumPlanes[4][0] /= t;
    g_frustumPlanes[4][1] /= t;
    g_frustumPlanes[4][2] /= t;
    g_frustumPlanes[4][3] /= t;

    //
    // Extract the frustum's near clipping plane and normalize it.
    //

    g_frustumPlanes[5][0] = matPtr[ 3] + matPtr[ 2];
    g_frustumPlanes[5][1] = matPtr[ 7] + matPtr[ 6];
    g_frustumPlanes[5][2] = matPtr[11] + matPtr[10];
    g_frustumPlanes[5][3] = matPtr[15] + matPtr[14];

    t = (float) sqrt( g_frustumPlanes[5][0] * g_frustumPlanes[5][0] +
                      g_frustumPlanes[5][1] * g_frustumPlanes[5][1] +
                      g_frustumPlanes[5][2] * g_frustumPlanes[5][2] );

    g_frustumPlanes[5][0] /= t;
    g_frustumPlanes[5][1] /= t;
    g_frustumPlanes[5][2] /= t;
    g_frustumPlanes[5][3] /= t;
}

bool CCamera::InFrustumBoundBox(Graphics::aabb& _box)
{
	glm::vec3 oldMin = _box.m_vecMin;
	glm::vec3 oldMax = _box.m_vecMax;
	glm::vec4 currentCorner = glm::vec4( oldMin, 1.0f);
	glm::vec3 camPos = glm::vec3( m_position.x, m_position.y, m_position.z );
	if(_box.Contains(camPos))
	{
		return true;
	}
	
	if(this->InFrustumBoundBox( currentCorner.x, currentCorner.y, currentCorner.z))
	{
		return true;
	}
	currentCorner.x = oldMax.x;
	if(this->InFrustumBoundBox( currentCorner.x, currentCorner.y, currentCorner.z))
	{
		return true;
	}
	currentCorner.y = oldMax.y;
	if(this->InFrustumBoundBox( currentCorner.x, currentCorner.y, currentCorner.z))
	{
		return true;
	}
	currentCorner.x = oldMin.x;
	if(this->InFrustumBoundBox( currentCorner.x, currentCorner.y, currentCorner.z))
	{
		return true;
	}
	currentCorner.z = oldMax.z;
	if(this->InFrustumBoundBox( currentCorner.x, currentCorner.y, currentCorner.z))
	{
		return true;
	}
	currentCorner.y = oldMin.y;
	if(this->InFrustumBoundBox( currentCorner.x, currentCorner.y, currentCorner.z))
	{
		return true;
	}
	currentCorner.x = oldMax.x;
	if(this->InFrustumBoundBox( currentCorner.x, currentCorner.y, currentCorner.z))
	{
		return true;
	}
	currentCorner.y = oldMax.y;
	if(this->InFrustumBoundBox( currentCorner.x, currentCorner.y, currentCorner.z))
	{
		return true;
	}
	return false;
}


CCamera * GetGameCamera()
{
	return &gameCamera;
}
