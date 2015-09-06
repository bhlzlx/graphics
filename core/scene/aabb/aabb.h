#ifndef __AABB_H__
#define __AABB_H__
#include <gl/glew.h>
#include <glm/glm.hpp>
#include <core/bufferogl.h>

namespace Graphics
{

	struct aabb
	{
	public:
		glm::vec3		m_vecMin;
		glm::vec3		m_vecMax;
		
		void SetMinimum( glm::vec3 & _min);
		void SetMaximum( glm::vec3 & _max);
		
		bool Contains( glm::vec3 & _vec);
		bool Contains( aabb & _other);
		
		void Transform( glm::mat4 & matrix);
		
		void Merge(glm::vec3 _vec);
		
		aabb( glm::vec3 _min, glm::vec3 _max);
		aabb();
		~aabb();
	};
	
	void CreateAABBVBO( aabb& _box, VertexBuffer ** _ppVBO, VertexBuffer ** _ppIBO);

}

#endif // __AABB_H__
