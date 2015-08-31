#ifndef __RENDER_OBJECT_H__
#define __RENDER_OBJECT_H__

#include <gl/glew.h>
#include <core/bufferogl.h>
#include <core/effectogl.h>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stdint.h>

namespace Graphics
{
	class RenderObjectBase
	{
	public:
		virtual void Render(EffectOGL * _pEffect,uint8_t _wiredFrame) = 0;
		virtual void SetPosition( glm::vec3 & _position );
		virtual void SetRotation( glm::vec3 & _axis, float _angle);
		virtual void SetScale(float _scale);
		virtual void Release() = 0;
	protected:
		glm::quat		m_qRotation;
		glm::vec3		m_vOffset;
		float 			m_fScale;
		glm::mat4		m_matrix;
	};
	

}

#endif // __RENDER_OBJECT_H__
