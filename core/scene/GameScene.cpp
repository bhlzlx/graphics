#include "GameScene.h"
#include <model/BasicModel.h>
#include <scene/octree/octreerendernode.h>
#include <stdio.h>

using namespace Graphics;

#define M_PI		3.14159265358979323846

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
}

void GameScene::Init()
{
	 // 创建 effect 对象(内含 shader 的创建)
    const char * szVertText = 
                    #include "../glsl/md5anim.vert"
    const char * szFragText = 
                    #include "../glsl/md5anim.frag"
	const char * szVertSimpleText = 
					#include "../glsl/staticObject.vert"
	const char * szFragSimpleText =
					#include "../glsl/staticObject.frag"
	
    EffectDesc effectDesc;
	effectDesc.renderState.cullMode = CULL_MODE_NONE;
    effectDesc.szPixelShaderText = szFragSimpleText;
    effectDesc.szVertexShaderText = szVertSimpleText;
    this->m_pStaticEffect = EffectOGL::CreateEffect(&effectDesc);
	
	effectDesc.szPixelShaderText = szFragText;
	effectDesc.szVertexShaderText = szVertText;
	this->m_pAnimEffect = EffectOGL::CreateEffect(&effectDesc);
	
	m_pChessTexture = Graphics::TexOGL::CreateChessTex();
	
	m_pGameCamera = GetGameCamera();
	
	// 添加模型
	this->m_pCubeModel = (Graphics::Cube*)Graphics::Cube::CreateCube();
	
	this->m_pOctree = new Octree;
	this->m_pOctree->Init( glm::vec3(0.0f,0.0f,0.0f), glm::vec3(32.0f,32.0f,32.0f),3);

	for(int i = 0; i< 32; ++i)
	{
		SceneObject * pSceneObject = SceneObject::CreateSceneObject( m_pCubeModel);
		glm::vec3 pos = glm::vec3( i%7 * 8 - 2 * 8 + 4 +2,4,i/7 * 8 + 4);
		pSceneObject->SetPosition(pos);
		pSceneObject->SetScale(1.0f);
		OctreeRenderNode * pRenderNode = OctreeRenderNode::CreateRenderNode(pSceneObject);
		this->m_pOctree->InsertRenderNode( pRenderNode);
		this->m_staticObjects.push_back(pSceneObject);
	}
}

void GameScene::Render(uint64_t _time)
{
	glm::mat4& viewMat = m_pGameCamera->GetViewMatrix();
	glm::mat4& projectionMat = m_pGameCamera->GetProjectionMatrix();
	CCamera * pCamera = GetGameCamera();
	
	m_pStaticEffect->Begin();
	m_pStaticEffect->m_pShader->SetUniformData( &viewMat, "VIEW");
	m_pStaticEffect->m_pShader->SetUniformData( &projectionMat, "PROJECTION");
	m_pStaticEffect->m_pShader->SetTexture( 0,m_pChessTexture);
	
	/*	
	for( SceneObject * pObject : m_staticObjects)
	{
		if(pCamera->InFrustumBoundBox( pObject->m_localAABB))
		{
			pObject->Render(m_pStaticEffect);
		}
	}
 */
	this->m_pOctree->UpdateRenderList();
	/*for( OctreeNode * pOctreeNode : this->m_pOctree->m_nodeList)
	{
		pOctreeNode->Render(m_pStaticEffect);
	}
	*/
	
	for( OctreeRenderNode * pRenderNode : this->m_pOctree->m_renderList)
	{
		pRenderNode->m_pSceneObject->Render(m_pStaticEffect);
		pRenderNode->m_pAttachNode->Render(m_pStaticEffect);
	}
	
	m_pStaticEffect->End();
	
	/*
	m_pAnimEffect->Begin();
	m_pAnimEffect->m_pShader->SetUniformData( &viewMat, "VIEW");
	m_pAnimEffect->m_pShader->SetUniformData( &projectionMat, "PROJECTION");
	for( md5Model * pObject : this->m_animObjects)
	{
		pObject->Tick(_time);
		pObject->Render(this->m_pAnimEffect,false);
	}
	m_pAnimEffect->End();
	 */
}