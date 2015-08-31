#include "BasicModel.h"
#include <math.h>

namespace Graphics
{
	const float __cube[8 * 36] =
	{
        // 1 ��
		-1,1,-1,	0,1,0, 0,1,
		-1,1,1,		0,1,0, 0,0,
		1,1,1,		0,1,0, 1,0,

		-1,1,-1,	0,1,0, 0,1,
		1,1,1,		0,1,0, 1,0,
		1,1,-1,		0,1,0, 1,1,
        // 2 ǰ
		-1,1,1,		0,0,1, 0,1,
		-1,-1,1,	0,0,1, 0,0,
		1,-1,1,		0,0,1, 1,0,

		-1,1,1,		0,0,1, 0,1,
		1,-1,1,		0,0,1, 1,0,
		1,1,1,		0,0,1, 1,1,
        // 3 ��
		-1,-1,1,	0,-1,0, 0,1,
		-1,-1,-1,	0,-1,0, 0,0,
		1,-1,-1,	0,-1,0, 1,0,

		-1,-1,1,	0,-1,0, 0,1,
		1,-1,-1,	0,-1,0, 1,0,
		1,-1,1,     0,-1,0, 1,1,
        // 4 ��
		1,1,-1,     0,0,-1, 0,1,
		1,-1,-1,	0,0,-1, 0,0,
		-1,-1,-1,	0,0,-1, 1,0,

		1,1,-1,     0,0,-1, 0,1,
		-1,-1,-1,	0,0,-1, 1,0,
		-1,1,-1,	0,0,-1, 1,1,
        // 5 ��
		1,1,1,		1,0,0,	0,1,
		1,-1,1,		1,0,0,	0,0,
		1,-1,-1,	1,0,0,	1,0,

		1,1,1,		1,0,0,	0,1,
		1,-1,-1,	1,0,0,	1,0,
		1,1,-1,		1,0,0,	1,1,
        // 6 ��
		-1,1,-1,	-1,0,0,	0,1,
		-1,-1,-1,	-1,0,0,	0,0,
		-1,-1,1,	-1,0,0,	1,0,

		-1,1,-1,	-1,0,0,	0,1,
		-1,-1,1,	-1,0,0,	1,0,
		-1,1,1,		-1,0,0,	1,1
	};
	
	const float __plane[8 * 6] =
	{
	    -1,0,-1,	0,1,0, 0,1,
		-1,0,1,		0,1,0, 0,0,
		1,0,1,		0,1,0, 1,0,

		-1,0,-1,	0,1,0, 0,1,
		1,0,1,		0,1,0, 1,0,
		1,0,-1,		0,1,0, 1,1
	};
	
	void DrawWiredFrame( EffectOGL * _pEffect, VertexArray * _pVertexArray, uint32_t _nNumVert )
	{
		int renderMode;
		glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);    
		glPolygonOffset(-0.2,-0.2);
		glEnable(GL_POLYGON_OFFSET_LINE);
		renderMode = 1;
		_pEffect->m_pShader->SetUniformData(&renderMode,"RENDER_MODE");
		static glm::vec4 wiredframe_color = glm::vec4(1.0,1.0,1.0,1.0);
		_pEffect->m_pShader->SetUniformData(&wiredframe_color,"WIREDFRAME_COLOR");
		
		_pVertexArray->Draw(36);
		
		glPolygonOffset(0,0);
		glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
		glDisable(GL_POLYGON_OFFSET_LINE);
	}
	
	void RenderObjectBase::SetScale(float _scale)
	{
		m_fScale = _scale;
		m_matrix = glm::translate( glm::mat4(1.0f),this->m_vOffset ) * glm::mat4_cast( this->m_qRotation ) * glm::scale( glm::mat4(1.0),glm::vec3(m_fScale,m_fScale,m_fScale));
	}
	
	void RenderObjectBase::SetPosition( glm::vec3 & _position )
	{
		this->m_vOffset = _position;
		m_matrix = glm::translate( glm::mat4(1.0f),this->m_vOffset ) * glm::mat4_cast( this->m_qRotation ) * glm::scale( glm::mat4(1.0),glm::vec3(m_fScale,m_fScale,m_fScale));
	}
	
	void RenderObjectBase::SetRotation(glm::vec3 & _axis, float _angle)
	{
		float sinAngle;
		_angle *= 0.5f;
		glm::vec3 vn(_axis);
		glm::normalize(vn);
		sinAngle = sin(_angle);
		this->m_qRotation.x = (vn.x * sinAngle);
		this->m_qRotation.y = (vn.y * sinAngle);
		this->m_qRotation.z = (vn.z * sinAngle);
		this->m_qRotation.w = cos(_angle);
		
		m_matrix = glm::translate( glm::mat4(1.0f),this->m_vOffset ) * glm::mat4_cast( this->m_qRotation ) * glm::scale( glm::mat4(1.0),glm::vec3(m_fScale,m_fScale,m_fScale));
	}

	void Cube::Render(EffectOGL * _pEffect,uint8_t _wiredFrame)
	{
		int renderMode = 0;
        glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
		_pEffect->m_pShader->SetUniformData(&m_matrix,"MODEL");
		_pEffect->m_pShader->SetUniformData(&renderMode,"RENDER_MODE");
		m_pVertexArray->Bind();
		m_pVertexArray->Draw(36);
		if(_wiredFrame)
		{
			DrawWiredFrame(_pEffect,m_pVertexArray,36);
		}
	}
	
	void Cube::Release()
	{
		m_pVertexBuffer->Release();
		m_pVertexArray->Release();
		delete this;
	}
	
	RenderObjectBase * Cube::CreateCube()
	{
		Cube * pCube = new Cube;
		pCube->m_pVertexArray = Graphics::VertexArray::CreateVertexArray();
		pCube->m_pVertexBuffer = Graphics::VertexBuffer::CreateBuffer( __cube,sizeof(__cube));
		pCube->m_pVertexArray->SetVertexBuffer(0,pCube->m_pVertexBuffer,3,(sizeof(float) * 8),0,GL_FLOAT);
		pCube->m_pVertexArray->SetVertexBuffer(1,pCube->m_pVertexBuffer,3,(sizeof(float) * 8),sizeof(float) * 3,GL_FLOAT);
		pCube->m_pVertexArray->SetVertexBuffer(2,pCube->m_pVertexBuffer,2,(sizeof(float) * 8),sizeof(float) * 6,GL_FLOAT);
		return pCube;
	}
}