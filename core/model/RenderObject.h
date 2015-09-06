#ifndef __RENDER_OBJECT_H__
#define __RENDER_OBJECT_H__

#include <gl/glew.h>
#include <core/bufferogl.h>
#include <core/effectogl.h>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stdint.h>
#include <functional>
#include <scene/aabb/aabb.h>

namespace Graphics
{
	class RenderObjectBase
	{
	public:
		virtual void Render(EffectOGL * _pEffect,glm::mat4 _model, uint8_t _wiredFrame) = 0;
		virtual void Release() = 0;
	public:
		aabb			m_localAABB;
	};
	

}

#endif // __RENDER_OBJECT_H__
