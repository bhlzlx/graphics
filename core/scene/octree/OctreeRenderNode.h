#ifndef __OCTREE_NODE_H__
#define __OCTREE_NODE_H__

#include <scene/aabb/aabb.h>
#include <scene/octree/Octree.h>

namespace Graphics
{
	class OctreeRenderNode
	{
	public:
		OctreeRenderNode();
		~OctreeRenderNode();
	private:
		OctreeNode*		m_pAttachNode;
		aabb*			m_pLocalAABB;
	};
}

#endif // __OCTREE_NODE_H__
