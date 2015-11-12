#include "aabb.h"

namespace Graphics
{

	aabb::aabb( glm::vec3 _min, glm::vec3 _max)
	{
		this->m_vecMin = _min;
		this->m_vecMax = _max;
	}
	
	aabb::aabb()
	{
		this->m_vecMin = this->m_vecMax = glm::vec3(0,0,0);
	}

	aabb::~aabb()
	{
	}
	
	void aabb::SetMinimum( glm::vec3 & _min)
	{
		this->m_vecMin = _min;
	}
	
	void aabb::SetMaximum( glm::vec3 & _max)
	{
		this->m_vecMax = _max;
	}

	bool aabb::Contains( glm::vec3 & _vec)
	{
		if(_vec.x >= m_vecMin.x &&
		   _vec.y >= m_vecMin.y &&
		   _vec.z >= m_vecMin.z &&
		   _vec.x <= m_vecMax.x &&
		   _vec.y <= m_vecMax.y &&
		   _vec.z <= m_vecMax.z
		)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	bool aabb::Contains( aabb & _other)
	{
		if(_other.m_vecMin.x >= m_vecMin.x &&
		   _other.m_vecMin.y >= m_vecMin.y &&
		   _other.m_vecMin.z >= m_vecMin.z &&
		   _other.m_vecMax.x <= m_vecMax.x &&
		   _other.m_vecMax.y <= m_vecMax.y &&
		   _other.m_vecMax.z <= m_vecMax.z
		)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void aabb::Transform( glm::mat4 & matrix)
	{
		glm::vec3 oldMin = m_vecMin;
		glm::vec3 oldMax = m_vecMax;
		glm::vec4 currentCorner = glm::vec4( oldMin, 1.0f);
		glm::vec4 r;
		// 0,0,0
		r = matrix * currentCorner;
		this->m_vecMax = glm::vec3(r.x,r.y,r.z);
		this->m_vecMin = glm::vec3(r.x,r.y,r.z);
		
		Merge( glm::vec3(r.x,r.y,r.z) );
		// 1,0,0
		currentCorner.x = oldMax.x;
		r = matrix * currentCorner;
		Merge( glm::vec3(r.x,r.y,r.z) );
		// 1,1,0
		currentCorner.y = oldMax.y;
		r = matrix * currentCorner;
		Merge( glm::vec3(r.x,r.y,r.z) );
		// 0,1,0
		currentCorner.x = oldMin.x;
		r = matrix * currentCorner;
		Merge( glm::vec3(r.x,r.y,r.z) );
		// 0,1,1
		currentCorner.z = oldMax.z;
		r = matrix * currentCorner;
		Merge( glm::vec3(r.x,r.y,r.z) );
		// 0,0,1
		currentCorner.y = oldMin.y;
		r = matrix * currentCorner;
		Merge( glm::vec3(r.x,r.y,r.z) );
		// 1,0,1
		currentCorner.x = oldMax.x;
		r = matrix * currentCorner;
		Merge( glm::vec3(r.x,r.y,r.z) );
		// 1,1,1
		currentCorner.y = oldMax.y;
		r = matrix * currentCorner;
		Merge( glm::vec3(r.x,r.y,r.z) );
	}
	
	void Graphics::aabb::Merge(glm::vec3 _vec)
	{
		if( m_vecMin.x > _vec.x )
			m_vecMin.x = _vec.x;
		if( m_vecMin.y > _vec.y )
			m_vecMin.y = _vec.y;
		if( m_vecMin.z > _vec.z )
			m_vecMin.z = _vec.z;
			
		if( m_vecMax.x < _vec.x )
			m_vecMax.x = _vec.x;
		if( m_vecMax.y < _vec.y )
			m_vecMax.y = _vec.y;
		if( m_vecMax.z < _vec.z )
			m_vecMax.z = _vec.z;
	}
	
	void CreateAABBVBO( aabb& _box, VertexBuffer ** _ppVBO, VertexBuffer ** _ppIBO)
	{
		glm::vec3 points[8];
		points[0] = _box.m_vecMin;
		points[1] = points[0];
		points[1].x = _box.m_vecMax.x;
		points[2] = points[1];
		points[2].y = _box.m_vecMax.y;
		points[3] = points[2];
		points[3].x = _box.m_vecMin.x;
		points[4] = points[3];
		points[4].z = _box.m_vecMax.z;
		points[5] = points[4];
		points[5].y = _box.m_vecMin.y;
		points[6] = points[5];
		points[6].x = _box.m_vecMax.x;
		points[7] = points[6];
		points[7].y = _box.m_vecMax.y;
		
		unsigned int indices[] = 
		{
			0,1,2, 2,3,0,
			4,5,0, 0,3,4,
			1,0,5, 5,6,1,
			2,1,6, 6,7,2,
			4,5,6, 6,7,4,
			4,3,2, 2,7,4
		};
		*_ppVBO = Graphics::VertexBuffer::CreateBuffer( &points, sizeof(points));
		*_ppIBO = Graphics::VertexBuffer::CreateBuffer( &indices, sizeof(indices));
	}
}



