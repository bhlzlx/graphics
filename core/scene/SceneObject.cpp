#include "SceneObject.h"
#include <audioManager/AudioManager.h>

SceneObject::SceneObject()
{
}

SceneObject::~SceneObject()
{
}

void SceneObject::Beep( owBOOL _bLoop )
{
	app::GetAudioManager()->PlaySound3D( this->m_iSoundID, this->m_vOffset.x, this->m_vOffset.y, this->m_vOffset.z, 2.0f , _bLoop);
}

void SceneObject::SetPosition( glm::vec3 & _position )
{
	this->m_vOffset = _position;
	m_matrix = glm::translate(
						glm::mat4(1.0f),this->m_vOffset ) * 
						glm::mat4_cast( this->m_qRotation ) * 
						glm::scale( glm::mat4(1.0),glm::vec3(m_fScale,m_fScale,m_fScale)
						);
	this->m_localAABB = this->m_pModel->m_localAABB;
	this->m_localAABB = this->m_pModel->m_localAABB;
	this->m_localAABB.Transform(m_matrix);
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
						glm::mat4(1.0f),this->m_vOffset ) * 
						glm::mat4_cast( this->m_qRotation ) * 
						glm::scale( glm::mat4(1.0),glm::vec3(m_fScale,m_fScale,m_fScale)
						);
	this->m_localAABB = this->m_pModel->m_localAABB;
	this->m_localAABB = this->m_pModel->m_localAABB;
	this->m_localAABB.Transform(m_matrix);
 }
 
void SceneObject::SetScale(float _scale)
{
	m_fScale = _scale;
	m_matrix = glm::translate(
						glm::mat4(1.0f),this->m_vOffset ) * 
						glm::mat4_cast( this->m_qRotation ) * 
						glm::scale( glm::mat4(1.0),glm::vec3(m_fScale,m_fScale,m_fScale)
						);
	this->m_localAABB = this->m_pModel->m_localAABB;
	this->m_localAABB.Transform(m_matrix);
}

void SceneObject::Release()
{
	delete this;
}

void SceneObject::Render(Graphics::EffectOGL* _pEffect)
{
	this->m_pModel->Render(_pEffect,this->m_matrix,false);
	// draw wired frame
	/*int renderMode;
	glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
	glPolygonOffset(-0.2,-0.2);
	glEnable(GL_POLYGON_OFFSET_LINE);
	renderMode = 1;
	_pEffect->m_pShader->SetUniformData(&renderMode,"RENDER_MODE");
	static glm::vec4 wiredframe_color = glm::vec4(1.0,1.0,1.0,1.0);
	_pEffect->m_pShader->SetUniformData(&wiredframe_color,"WIREDFRAME_COLOR");
	m_pAABBVAO->Bind();
	m_pAABBVAO->Draw(36);
	glPolygonOffset(0,0);
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	glDisable(GL_POLYGON_OFFSET_LINE);
	 */
}

SceneObject * SceneObject::CreateSceneObject( Graphics::RenderObjectBase * _pRenderObject )
{
	SceneObject * pSceneObject = new SceneObject();
	pSceneObject->m_matrix = glm::mat4(1.0f);
	pSceneObject->m_localAABB = _pRenderObject->m_localAABB;
	pSceneObject->m_fScale = 1.0f;
	pSceneObject->m_qRotation = glm::quat(1.0f,0.0f,0.0f,0.0f);
	pSceneObject->m_vOffset = glm::vec3(0.0f,0.0f,0.0f);
	pSceneObject->m_pModel = _pRenderObject;
	
	CreateAABBVBO(pSceneObject->m_localAABB,&pSceneObject->m_pAABBVBO,&pSceneObject->m_pAABBIBO);
	pSceneObject->m_pAABBVAO = Graphics::VertexArray::CreateVertexArray();
	pSceneObject->m_pAABBVAO->SetIndexBuffer(pSceneObject->m_pAABBIBO);
	pSceneObject->m_pAABBVAO->SetVertexBuffer(0,pSceneObject->m_pAABBVBO,3,0,0,GL_FLOAT);
	
	return pSceneObject;
}
