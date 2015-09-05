#ifndef __OCTREE_NODE_H__
#define __OCTREE_NODE_H__

#include <scene/aabb/aabb.h>



namespace Graphics
{
	struct OctreeNode;
	struct OctreeRenderNode
	{
		OctreeRenderNode();
		~OctreeRenderNode();
		
		Graphics::OctreeNode*		m_pAttachNode;
		aabb						m_localAABB;
	};
}

#endif // __OCTREE_NODE_H__
