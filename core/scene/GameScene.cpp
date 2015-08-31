#include "GameScene.h"
#include <model/BasicModel.h>

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
	Graphics::Cube * pCube = NULL;
	Graphics::md5Model * pModel = NULL;
	
	for(int i = 0; i< 9; ++i)
	{
		pCube = (Cube*)Graphics::Cube::CreateCube();
		pModel = new md5Model;
		pModel->Init("./model/hellknight.md5mesh");
		pModel->AddAnimation("./model/idle.md5anim");
		pModel->AddAnimation("./model/attack2.md5anim");
		pModel->AddAnimation("./model/stand.md5anim");
		pModel->AddAnimation("./model/roar.md5anim");
		pModel->ActiveAnim(0);

		glm::vec3 pos = glm::vec3( i%3 * 10 , 0,i / 3 * 10);
		pCube->SetPosition(pos);
		pos.y += 4;
		pModel->SetPosition(pos);
		pModel->ActiveAnim(i%3);
		
		glm::vec3 axis(1,0,0);
		pCube->SetRotation(axis,0.0f);
		pModel->SetRotation(axis,-M_PI/2);
		
		pCube->SetScale(4.0f);
		pModel->SetScale(0.05f);
		this->m_staticObjects.push_back(pCube);
		this->m_animObjects.push_back(pModel);
	}
}

void GameScene::Render(uint64_t _time)
{
	glm::mat4& viewMat = m_pGameCamera->GetViewMatrix();
	glm::mat4& projectionMat = m_pGameCamera->GetProjectionMatrix();
	
	m_pStaticEffect->Begin();
	m_pStaticEffect->m_pShader->SetUniformData( &viewMat, "VIEW");
	m_pStaticEffect->m_pShader->SetUniformData( &projectionMat, "PROJECTION");
	m_pStaticEffect->m_pShader->SetTexture(0,m_pChessTexture);
	for( RenderObjectBase * pObject : this->m_staticObjects)
	{
		pObject->Render(this->m_pStaticEffect,false);
	}
	m_pStaticEffect->End();
	
	
	m_pAnimEffect->Begin();
	m_pAnimEffect->m_pShader->SetUniformData( &viewMat, "VIEW");
	m_pAnimEffect->m_pShader->SetUniformData( &projectionMat, "PROJECTION");
	for( md5Model * pObject : this->m_animObjects)
	{
		pObject->Tick(_time);
		pObject->Render(this->m_pAnimEffect,false);
	}
	m_pAnimEffect->End();
}
