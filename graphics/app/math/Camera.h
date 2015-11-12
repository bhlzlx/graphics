//
// Created by phantom on 2015/5/27 0027.
//

#ifndef GRAPHICSLIBRARY_CAMERA_H
#define GRAPHICSLIBRARY_CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <scene/aabb/aabb.h>

using namespace glm;

extern const vec4 default_normal;
extern const vec4 default_top;
extern const vec4 default_left;

struct CameraState
{
	float m_axisX;
	float m_axisY;

	vec4  m_position;
	mat4  m_proj;
};


struct CCamera
{
    float m_axis_x;
    float m_axis_y;

    vec4  m_position;

    mat4  m_offsetMatrix;
    mat4  m_rotateMatrix;

    mat4  m_viewMatrix;
	mat4  m_projectionMatrix;
	mat4  m_vpMat;
	
	float g_frustumPlanes[6][4];

    void RotateAxisX(float angle);
    void RotateAxisY(float angle);
    void Translate(vec4 &offset);
    void ApplyRotate();

    void Forward( float iden);
    void Leftward( float iden);
    void Rightward( float iden);

    mat4& GetViewMatrix();
	mat4& GetProjectionMatrix();
	
	void updateFrustumPlane();
	void updateListener();
	bool InFrustumBoundBox(float _x, float _y, float _z);
	bool InFrustumBoundBox( Graphics::aabb & _box );
	
    vec4& GetPosition();

    CCamera();
};

extern CCamera gameCamera;

CCamera * GetGameCamera();

#endif //GRAPHICSLIBRARY_CAMERA_H

