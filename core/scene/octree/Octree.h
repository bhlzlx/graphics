#ifndef _OCTREE_H__
#define _OCTREE_H__

#include <stdint.h>
#include <scene/aabb/aabb.h>
#include <set>

namespace Graphics
{
	struct OctreeRenderNode;
	struct OctreeNode
	{
		aabb					m_aabb;
		
		bool 					Contains( aabb & AABB );
		void					InitOctree( glm::vec3 _vecMin, glm::vec3 _vecMax, uint16_t _depth);
		bool 					InsertRenderNode( Graphics::OctreeRenderNode * _pRenderNode );
		// 子节点
		OctreeNode* 			m_pChildrenNodes;
		int16_t 				m_nNumChildren;
		// 渲染对象
		std::set<OctreeRenderNode *> m_renderNodes;
		int16_t 				m_nDepthFloor;
	};
	
	struct Octree
	{
		Octree();
		~Octree();
		
		void Init( glm::vec3 _center, glm::vec3 _bound, uint16_t _depth );
		
		bool InsertRenderNode( OctreeRenderNode * _pRenderNode );
		
		OctreeNode * 	m_pRootNode;
		uint16_t 		m_nDepth;
	};
}

#endif // _OCTREE_H__
