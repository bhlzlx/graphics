#ifndef __SCENE_OBJECT_H__
#define __SCENE_OBJECT_H__
#include <scene/aabb/aabb.h>
#include <core/effectogl.h>
#include <model/RenderObject.h>

class SceneObject
{
public:
	SceneObject();
	~SceneObject();
	
	virtual void SetPosition( glm::vec3 & _position );
	virtual void SetRotation( glm::vec3 & _axis, float _angle);
	virtual void SetScale(float _scale);
	virtual void Release() = 0;
	virtual void Render(Graphics::EffectOGL * _pEffect);
protected:
	glm::quat		m_qRotation;
	glm::vec3		m_vOffset;
	float 			m_fScale;
	glm::mat4		m_matrix;
	aabb			m_localAABB;
	
	Graphics::RenderObjectBase* m_pModel;
};



#endif // __SCENE_OBJECT_H__
