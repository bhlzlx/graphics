#ifndef __OCTREE_NODE_H__
#define __OCTREE_NODE_H__

#include <scene/aabb/aabb.h>
#include <scene/SceneObject.h>


namespace Graphics
{
	struct OctreeNode;
	struct OctreeRenderNode
	{
		OctreeRenderNode();
		~OctreeRenderNode();
		
		static OctreeRenderNode * CreateRenderNode( SceneObject* _pSceneObject);
		
		void Release();
		
		Graphics::OctreeNode*		m_pAttachNode;
		SceneObject*				m_pSceneObject;
		aabb						m_localAABB;
	};
}

#endif // __OCTREE_NODE_H__
