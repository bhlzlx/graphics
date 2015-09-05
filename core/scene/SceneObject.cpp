#include "SceneObject.h"

SceneObject::SceneObject()
{
}

SceneObject::~SceneObject()
{
}

void SceneObject::SetPosition( glm::vec3 & _position )
{
	this->m_vOffset = _position;
	m_matrix = glm::translate( 
					glm::mat4(1.0f),
					this->m_vOffset ) * glm::mat4_cast( this->m_qRotation ) * glm::scale( glm::mat4(1.0),
					glm::vec3(m_fScale,m_fScale,m_fScale)
					);
}
 void SceneObject::SetRotation( glm::vec3 & _axis, float _angle)
 {
	float sinAngle;
	_angle *= 0.5f;
	glm::vec3 vn(_axis);
	glm::normalize(vn);
	sinAngle = sin(_angle);
	this->m_qRotation.x = (vn.x * sinAngle);
	this->m_qRotation.y = (vn.y * sinAngle);
	this->m_qRotation.z = (vn.z * sinAngle);
	this->m_qRotation.w = cos(_angle);
	m_matrix = glm::translate( 
					glm::mat4(1.0f),
					this->m_vOffset ) * glm::mat4_cast( this->m_qRotation ) * glm::scale( glm::mat4(1.0),
					glm::vec3(m_fScale,m_fScale,m_fScale)
					);
 }
 
void SceneObject::SetScale(float _scale)
{
	m_fScale = _scale;
	m_matrix = glm::translate( 
						glm::mat4(1.0f),
						this->m_vOffset ) * glm::mat4_cast( this->m_qRotation ) * glm::scale( glm::mat4(1.0),
						glm::vec3(m_fScale,m_fScale,m_fScale)
						);
}

void SceneObject::Release()
{
	if(this->m_pModel)
	{
		m_pModel->Release();
	}
}

void SceneObject::Render(Graphics::EffectOGL* _pEffect)
{
	this->m_pModel->Render(_pEffect,this->m_matrix,false);
}
