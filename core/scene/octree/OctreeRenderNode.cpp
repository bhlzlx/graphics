#include "OctreeRenderNode.h"

namespace Graphics
{
	OctreeRenderNode::OctreeRenderNode()
	{
	}

	OctreeRenderNode::~OctreeRenderNode()
	{
	}
	
	OctreeRenderNode * OctreeRenderNode::CreateRenderNode( SceneObject* _pSceneObject)
	{
		OctreeRenderNode * pRenderNode = new OctreeRenderNode;
		pRenderNode->m_pSceneObject = _pSceneObject;
		pRenderNode->m_localAABB = _pSceneObject->m_localAABB;
		return pRenderNode;
	}
	
	void OctreeRenderNode::Release()
	{
		delete this;
	}
	
}