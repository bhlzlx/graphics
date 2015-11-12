#ifndef __SCENE_OBJECT_H__
#define __SCENE_OBJECT_H__
#include <scene/aabb/aabb.h>
#include <core/effectogl.h>
#include <core/bufferogl.h>
#include <model/RenderObject.h>

#undef PlaySound

class SceneObject
{
public:
	SceneObject();
	virtual ~SceneObject();
	
	virtual void SetPosition( glm::vec3 & _position );
	virtual void SetRotation( glm::vec3 & _axis, float _angle);
	virtual void SetScale(float _scale);
	virtual void Release();
	virtual void Render(Graphics::EffectOGL * _pEffect);
	
	void Beep( owBOOL _bLoop );
	
	static SceneObject * CreateSceneObject( Graphics::RenderObjectBase * _pRenderObject );
public:
	glm::quat		m_qRotation;
	glm::vec3		m_vOffset;
	float 			m_fScale;
	glm::mat4		m_matrix;
	Graphics::aabb  m_localAABB;
	Graphics::VertexBuffer* 	m_pAABBVBO;
	Graphics::VertexBuffer* 	m_pAABBIBO;
	Graphics::VertexArray* 		m_pAABBVAO;
	
	Graphics::RenderObjectBase* m_pModel;
	
	owINT32			m_iSoundID;

};

#endif // __SCENE_OBJECT_H__
