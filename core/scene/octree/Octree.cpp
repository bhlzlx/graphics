#include "Octree.h"
#include <queue>
#include <scene/octree/OctreeRenderNode.h>

namespace Graphics
{

	Octree::Octree()
	{
	}

	Octree::~Octree()
	{
	}
	
	bool OctreeNode::Contains( aabb & AABB )
	{
		return this->m_aabb.Contains( AABB);
	}
	
	bool Octree::InsertRenderNode( OctreeRenderNode * _pRenderNode )
	{
		OctreeNode * pCurrNode = m_pRootNode;
		// 如果最大包围盒也容不下就失败了！
		if(!pCurrNode->m_aabb.Contains( _pRenderNode->m_localAABB))
		{
			return false;
		}
		
		while(true)
		{
			bool shouldBreak = true;
			for(int i = 0; i<8; ++i)
			{
				if(pCurrNode->m_pChildrenNodes[i].m_aabb.Contains( _pRenderNode->m_localAABB) )
				{
					pCurrNode = &pCurrNode->m_pChildrenNodes[i];
					shouldBreak = false;
				}
			}
			if(shouldBreak || pCurrNode->m_nNumChildren == 0)
			{
				break;
			}
		}
		
		pCurrNode->m_renderNodes.insert( _pRenderNode );
		return true;
	}

	void Octree::Init( glm::vec3 _center, glm::vec3 _bound, uint16_t _depth )
	{
		glm::vec3 vecMin = _center - _bound;
		glm::vec3 vecMax = _center + _bound;
		std::queue<OctreeNode *> nodeQueue;
		this->m_pRootNode = new OctreeNode;
		m_pRootNode->m_aabb.m_vecMin = vecMin;
		m_pRootNode->m_aabb.m_vecMax = vecMax;
		m_pRootNode->m_nDepthFloor = _depth;
		
		while(!nodeQueue.empty())
		{
			OctreeNode * pCurrNode = nodeQueue.front();
			nodeQueue.pop();
			uint16_t currDepth = pCurrNode->m_nDepthFloor;
			if(currDepth != 0)
			{
				pCurrNode->m_nNumChildren = 8;
				pCurrNode->m_pChildrenNodes = new OctreeNode[8];
				for(int i = 0; i<8; ++i)
				{
					pCurrNode->m_pChildrenNodes[i].m_nDepthFloor = currDepth - 1;
					nodeQueue.push(pCurrNode->m_pChildrenNodes+i);
				}
				glm::vec3 currVecMin = pCurrNode->m_aabb.m_vecMin;
				glm::vec3 currVecMax = pCurrNode->m_aabb.m_vecMax;
			
				glm::vec3 halfVec = (currVecMin + currVecMax) / 2.0f;
			
				pCurrNode->m_pChildrenNodes[0].m_aabb.m_vecMin = currVecMin;
				pCurrNode->m_pChildrenNodes[0].m_aabb.m_vecMax = halfVec;
				
				pCurrNode->m_pChildrenNodes[1].m_aabb.m_vecMin = pCurrNode->m_pChildrenNodes[0].m_aabb.m_vecMin;
				pCurrNode->m_pChildrenNodes[1].m_aabb.m_vecMax = pCurrNode->m_pChildrenNodes[0].m_aabb.m_vecMax;
				pCurrNode->m_pChildrenNodes[1].m_aabb.m_vecMin.x += halfVec.x;
				pCurrNode->m_pChildrenNodes[1].m_aabb.m_vecMax.x += halfVec.x;
				
				pCurrNode->m_pChildrenNodes[2].m_aabb.m_vecMin = pCurrNode->m_pChildrenNodes[0].m_aabb.m_vecMin;
				pCurrNode->m_pChildrenNodes[2].m_aabb.m_vecMax = pCurrNode->m_pChildrenNodes[0].m_aabb.m_vecMax;
				pCurrNode->m_pChildrenNodes[2].m_aabb.m_vecMin.y += halfVec.y;
				pCurrNode->m_pChildrenNodes[2].m_aabb.m_vecMax.y += halfVec.y;
				
				pCurrNode->m_pChildrenNodes[3].m_aabb.m_vecMin = pCurrNode->m_pChildrenNodes[1].m_aabb.m_vecMin;
				pCurrNode->m_pChildrenNodes[3].m_aabb.m_vecMax = pCurrNode->m_pChildrenNodes[1].m_aabb.m_vecMax;
				pCurrNode->m_pChildrenNodes[3].m_aabb.m_vecMin.y += halfVec.y;
				pCurrNode->m_pChildrenNodes[3].m_aabb.m_vecMax.y += halfVec.y;
				
				pCurrNode->m_pChildrenNodes[4].m_aabb.m_vecMin = pCurrNode->m_pChildrenNodes[0].m_aabb.m_vecMin;
				pCurrNode->m_pChildrenNodes[4].m_aabb.m_vecMax = pCurrNode->m_pChildrenNodes[0].m_aabb.m_vecMax;
				pCurrNode->m_pChildrenNodes[4].m_aabb.m_vecMin.z += halfVec.z;
				pCurrNode->m_pChildrenNodes[4].m_aabb.m_vecMax.z += halfVec.z;

				pCurrNode->m_pChildrenNodes[5].m_aabb.m_vecMin = pCurrNode->m_pChildrenNodes[4].m_aabb.m_vecMin;
				pCurrNode->m_pChildrenNodes[5].m_aabb.m_vecMax = pCurrNode->m_pChildrenNodes[4].m_aabb.m_vecMax;
				pCurrNode->m_pChildrenNodes[5].m_aabb.m_vecMin.x += halfVec.x;
				pCurrNode->m_pChildrenNodes[5].m_aabb.m_vecMax.x += halfVec.x;
				
				pCurrNode->m_pChildrenNodes[6].m_aabb.m_vecMin = pCurrNode->m_pChildrenNodes[4].m_aabb.m_vecMin;
				pCurrNode->m_pChildrenNodes[6].m_aabb.m_vecMax = pCurrNode->m_pChildrenNodes[4].m_aabb.m_vecMax;
				pCurrNode->m_pChildrenNodes[6].m_aabb.m_vecMin.y += halfVec.y;
				pCurrNode->m_pChildrenNodes[6].m_aabb.m_vecMax.y += halfVec.y;
				
				pCurrNode->m_pChildrenNodes[7].m_aabb.m_vecMin = pCurrNode->m_pChildrenNodes[6].m_aabb.m_vecMin;
				pCurrNode->m_pChildrenNodes[7].m_aabb.m_vecMax = pCurrNode->m_pChildrenNodes[6].m_aabb.m_vecMax;
				pCurrNode->m_pChildrenNodes[7].m_aabb.m_vecMin.x += halfVec.x;
				pCurrNode->m_pChildrenNodes[7].m_aabb.m_vecMax.x += halfVec.x;
				
			}
			else
			{
				pCurrNode->m_nNumChildren = 0;
				pCurrNode->m_pChildrenNodes = NULL;
			}
		}
	}
}




