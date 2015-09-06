#ifndef _OCTREE_H__
#define _OCTREE_H__

#include <stdint.h>
#include <scene/aabb/aabb.h>
#include <set>
#include <list>
#include <core/bufferogl.h>
#include <core/effectogl.h>

namespace Graphics
{
	struct OctreeRenderNode;
	struct OctreeNode
	{
		aabb					m_aabb;
		
		bool 					Contains( aabb & AABB );
		void					InitOctree( glm::vec3 _vecMin, glm::vec3 _vecMax, uint16_t _depth);
		bool 					InsertRenderNode( Graphics::OctreeRenderNode * _pRenderNode );
		void 					Render(EffectOGL * _pEffect);
		// 子节点
		OctreeNode* 			m_pChildrenNodes;
		int16_t 				m_nNumChildren;
		// 渲染对象
		std::list<OctreeRenderNode *> m_renderNodes;
		int16_t 				m_nDepthFloor;
		
		Graphics::VertexBuffer* 	m_pAABBVBO;
		Graphics::VertexBuffer* 	m_pAABBIBO;
		Graphics::VertexArray* 		m_pAABBVAO;
	};
	
	struct Octree
	{
		Octree();
		~Octree();
		
		void Init( glm::vec3 _center, glm::vec3 _bound, uint16_t _depth );
		bool InsertRenderNode( OctreeRenderNode * _pRenderNode );
		void UpdateRenderList();
		std::list<OctreeRenderNode*>		m_renderList;
		
		OctreeNode * 						m_pRootNode;
		uint16_t 							m_nDepth;
		Graphics::VertexBuffer* 			m_pVertexBuffer;
	};
}

#endif // _OCTREE_H__
