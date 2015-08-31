#include <gl/glew.h>
#include "md5Model.h"
#include <string.h>

namespace Graphics
{
	struct weight_struct
	{
		int				m_nNumJointCount;
		ivector4		m_vecJointIndices;
		fvector4		m_vecJointBias;
	};
	// 解析 并 创建mesh相关的 buffer object
	void md5Model::Init( const char * _szMeshFile )
	{
		iBuffer * pBuffer = BufferFromFile(_szMeshFile);
		assert(pBuffer);
		
		model::InitMeshModel( &this->m_meshModel, pBuffer);
		pBuffer->Release();
		// 初始化数据
		m_nNumAnimation = 0;
		m_iActivedAnimID = -1;
		// 分配meshbuffer
		this->m_nNumMeshes = m_meshModel.m_nNumMeshes;
		this->m_pMeshBuffers = new md5MeshBuffer[m_meshModel.m_nNumMeshes];
		// 为每个mesh创建相应的 buffer objects
		md5Mesh * pSubMesh = NULL;
		md5MeshBuffer * pSubMeshBuffer = NULL;
		for(int32_t meshIndex = 0;meshIndex < m_meshModel.m_nNumMeshes; ++meshIndex)
		{
			// 获取子mesh
			pSubMesh = m_meshModel.m_pMeshes + meshIndex;
			pSubMeshBuffer = this->m_pMeshBuffers + meshIndex;
			// 生成纹理
			iBuffer * imageBuffer = BufferFromFile(pSubMesh->m_szTexture);
			if(imageBuffer)
			{
				Image * image = Image::ImageFromPng(imageBuffer);
				if(image)
				{
					pSubMeshBuffer->m_pTexture = TexOGL::CreateTexWidthImage(image,true);
					image->Release();
				}
				imageBuffer->Release();
			}
			else
			{
				pSubMeshBuffer->m_pTexture = TexOGL::CreateChessTex();
			}
			// 创建VAO
			pSubMeshBuffer->m_pVertexArray = Graphics::VertexArray::CreateVertexArray();
			// 创建IBO
			uint32_t bufferSize = 0;
			uint8_t* bufferPtr = NULL;
			bufferSize = pSubMesh->m_nNumTriangles * sizeof(ivector3);
			bufferPtr = (uint8_t *)pSubMesh->m_pTriangles;
			pSubMeshBuffer->m_pIndexBuffer = Graphics::VertexBuffer::CreateBuffer(bufferPtr,bufferSize);
			// 创建UV
			iBuffer * pUVBuffer = GetUVBuffer(pSubMesh);
			bufferSize = pUVBuffer->GetLength();
			bufferPtr = (uint8_t*)pUVBuffer->GetBuffer();
			pSubMeshBuffer->m_pUVBuffer = Graphics::VertexBuffer::CreateBuffer(bufferPtr,bufferSize);
			pUVBuffer->Release();
			// 创建weight
			weight_struct * pWeightElements = new weight_struct[pSubMesh->m_nNumVertices];
			for(int32_t vertIndex = 0; vertIndex<pSubMesh->m_nNumVertices; ++vertIndex)
			{
				md5Vertex * pVert = pSubMesh->m_pVertices + vertIndex;
				md5Weight * pVertWeight = NULL;
				pWeightElements[vertIndex].m_nNumJointCount = pVert->m_nCount>4?4:pVert->m_nCount;

				for(int32_t w = 0; w<pVert->m_nCount && w<4; ++w)
				{
					pVertWeight = pSubMesh->m_pWeights + w + pVert->m_nStart;
					pWeightElements[vertIndex].m_vecJointBias[w] = pVertWeight->m_fBias;
					pWeightElements[vertIndex].m_vecJointIndices[w] = pVertWeight->m_iJointIndex;
				}
			}
			bufferSize = sizeof(weight_struct) * pSubMesh->m_nNumVertices;
			bufferPtr = (uint8_t *)pWeightElements;
			pSubMeshBuffer->m_pWeightBuffer = Graphics::VertexBuffer::CreateBuffer( bufferPtr, bufferSize );
			delete []pWeightElements;
			// 设设置 vao
			pSubMeshBuffer->m_pVertexArray->SetVertexBuffer(2,pSubMeshBuffer->m_pUVBuffer,2,0,0);
			pSubMeshBuffer->m_pVertexArray->SetVertexBufferI(3,pSubMeshBuffer->m_pWeightBuffer,1,sizeof(weight_struct),0,GL_INT);
			pSubMeshBuffer->m_pVertexArray->SetVertexBufferI(4,pSubMeshBuffer->m_pWeightBuffer,4,sizeof(weight_struct),sizeof(int),GL_INT);
			pSubMeshBuffer->m_pVertexArray->SetVertexBuffer(5,pSubMeshBuffer->m_pWeightBuffer,4,sizeof(weight_struct),sizeof(int)*5,GL_FLOAT);
			pSubMeshBuffer->m_pVertexArray->SetIndexBuffer(pSubMeshBuffer->m_pIndexBuffer);
		}
		// 计算逆矩阵
		uint32_t nNumJoints = this->m_meshModel.m_nNumJoints;
		this->m_pUniformBoneMatrices = new matrix_4x4[nNumJoints];
		this->m_pInverseBoneMatrices = new matrix_4x4[nNumJoints];
		for(uint32_t j = 0;j<nNumJoints;++j)
		{
			quat q = m_meshModel.m_pJoints[j].m_quaOrient;
			fvector3 offset = m_meshModel.m_pJoints[j].m_vecOffset;
			matrix_4x4 boneMat = glm::translate( matrix_4x4(1.0),offset) * glm::mat4_cast( q );
			// 求逆矩阵
			m_pInverseBoneMatrices[j] = glm::inverse( boneMat );
		}
		// 计算默认绑定骨骼
		for(int32_t meshIndex = 0;meshIndex < m_meshModel.m_nNumMeshes; ++meshIndex)
		{
			// 获取子mesh
			pSubMesh = m_meshModel.m_pMeshes + meshIndex;
			pSubMeshBuffer = this->m_pMeshBuffers + meshIndex;
			// 创建 buffer
			fvector3 * pBindVertices = new fvector3[ pSubMesh->m_nNumVertices ];
			for(int vertIdx = 0;vertIdx < pSubMesh->m_nNumVertices ;++vertIdx)
			{
				// 累积 weight bias 计算顶点
				glm::vec3 result = glm::vec3(0,0,0);
				md5Vertex* pVert = pSubMesh->m_pVertices + vertIdx;
				for(int weightIdx = pVert->m_nStart; weightIdx < pVert->m_nCount + pVert->m_nStart; ++weightIdx )
				{
					md5Weight* pWeight = pSubMesh->m_pWeights+weightIdx;
					uint32_t iJointIndex = pWeight->m_iJointIndex;
					glm::quat q = m_meshModel.m_pJoints[iJointIndex].m_quaOrient;
					glm::vec3 offset = m_meshModel.m_pJoints[iJointIndex].m_vecOffset;
					result += (offset + q * pWeight->m_vecOffset) * pWeight->m_fBias;
				}
				pBindVertices[vertIdx] = result;
			}
			pSubMeshBuffer->m_pBindposeVertexBuffer = Graphics::VertexBuffer::CreateBuffer( pBindVertices, pSubMesh->m_nNumVertices * sizeof(fvector3) );
			pSubMeshBuffer->m_pVertexArray->SetVertexBuffer(0,pSubMeshBuffer->m_pBindposeVertexBuffer,3,0,0);
			pSubMeshBuffer->m_nNumElement = pSubMesh->m_nNumTriangles * 3;
			delete []pBindVertices;
		}
	}
	
	void md5Model::ActiveAnim( uint32_t _iAnimID )
	{
		if(this->m_nNumAnimation <= _iAnimID)
		{
			return;
		}
		else
		{
			this->m_iActivedAnimID = _iAnimID;
		}
	}	
	// 解析anim添加到anim列表中
	void md5Model::AddAnimation( const char * _szAnimFile)
	{
		if(this->m_nNumAnimation < ANIMATION_MAX)
		{
			iBuffer * pBuffer = BufferFromFile(_szAnimFile);
			assert(pBuffer);
			model::InitAnimModel(&this->m_animModels[m_nNumAnimation],pBuffer);
			m_nNumAnimation++;
		}
		else
		{
			assert(false);
			return;
		}
	}
	
	void md5Model::Tick( long long _animTime )
	{
		if(this->m_iActivedAnimID < 0)
		{	
			return;		
		}
		md5AnimModel * pAnimModel = &this->m_animModels[m_iActivedAnimID];
		
		uint32_t nFrameRate = pAnimModel->m_iFrameRate;
		uint32_t nNumFrames = pAnimModel->m_nNumFrames;
		float    nFrameTime = (float)1000 / (float)nFrameRate;
		uint32_t nCycleTime = (float)(nNumFrames - 1)/(float)nFrameRate * 1000.f;
		uint32_t currTime = _animTime  - ((unsigned int)(_animTime / nCycleTime) * nCycleTime);
		uint32_t frame_idx_1 = (unsigned int)(currTime / nFrameTime);
		uint32_t frame_idx_2 = frame_idx_1 + 1;
		
		uint32_t biasTime = currTime - ((unsigned int)(currTime / nFrameTime) * nFrameTime);
		float frameBias = (float)biasTime / (float)nFrameTime;
		
		md5Joint* pJointOutA = pAnimModel->m_pKeyFrames[frame_idx_1];
		md5Joint* pJointOutB = pAnimModel->m_pKeyFrames[frame_idx_2];

		// 将结果插值到 结果矩阵列表
		for(int jointIndex = 0;jointIndex< pAnimModel->m_nNumJoints;++jointIndex)
		{
			glm::quat q = glm::slerp(pJointOutA[jointIndex].m_quaOrient,pJointOutB[jointIndex].m_quaOrient,frameBias);
			glm::vec3 offset = pJointOutA[jointIndex].m_vecOffset + ( pJointOutB[jointIndex].m_vecOffset - pJointOutA[jointIndex].m_vecOffset ) * frameBias;
			// 生成矩阵
			// 别忘记乘默认绑定位置的逆矩阵
			this->m_pUniformBoneMatrices[jointIndex] = (glm::translate( matrix_4x4(1.0) ,offset ) * glm::mat4_cast(q) )  *this->m_pInverseBoneMatrices[jointIndex] ;
		}
	}
	
	void md5Model::Render( EffectOGL * _pEffect, uint8_t _wiredframe )
	{
		int renderMode = 0;
        glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
		_pEffect->m_pShader->SetUniformData(&m_matrix,"MODEL");
        _pEffect->m_pShader->SetUniformData(&renderMode,"RENDER_MODE");
		bool succeed = true;
		succeed = _pEffect->m_pShader->SetUniformData(this->m_pUniformBoneMatrices,"BONE_MATRICES[0]",this->m_meshModel.m_nNumJoints);
		if(!succeed)
		{
			_pEffect->m_pShader->SetUniformData(this->m_pUniformBoneMatrices,"BONE_MATRICES",this->m_meshModel.m_nNumJoints);
		}
		for(int meshIdx = 0; meshIdx<this->m_nNumMeshes; ++meshIdx)
		{
			md5MeshBuffer * pMeshBuffer = &this->m_pMeshBuffers[meshIdx];
			_pEffect->m_pShader->SetTexture(0, pMeshBuffer->m_pTexture);
			pMeshBuffer->m_pVertexArray->Bind();
			pMeshBuffer->m_pVertexArray->Draw( pMeshBuffer->m_nNumElement );
		}
        if(_wiredframe)
        {
            glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);    
            glPolygonOffset(-0.2,-0.5);
            glEnable(GL_POLYGON_OFFSET_LINE);
            renderMode = 1;
            _pEffect->m_pShader->SetUniformData(&renderMode,"RENDER_MODE");
            static glm::vec4 wiredframe_color = glm::vec4(1.0,0.0,0.0,1.0);
            _pEffect->m_pShader->SetUniformData(&wiredframe_color,"WIREDFRAME_COLOR");
			for(int meshIdx = 0; meshIdx<this->m_nNumMeshes; ++meshIdx)
			{
				md5MeshBuffer * pMeshBuffer = &this->m_pMeshBuffers[meshIdx];
				_pEffect->m_pShader->SetTexture(0, pMeshBuffer->m_pTexture);
				pMeshBuffer->m_pVertexArray->Bind();
				pMeshBuffer->m_pVertexArray->Draw( pMeshBuffer->m_nNumElement );
			}
            glPolygonOffset(0,0);
            glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
            glDisable(GL_POLYGON_OFFSET_LINE);
        }
	}
	
	void md5Model::Deinit()
	{
		for(int animIdx = 0;animIdx < m_nNumAnimation; ++animIdx)
		{
			model::ClearAnimModel( &m_animModels[animIdx] );
		}
		model::ClearMeshModel( &m_meshModel );
		delete []this->m_pInverseBoneMatrices;
		delete []this->m_pUniformBoneMatrices;
		for(int meshId = 0; meshId <m_nNumMeshes; ++meshId)
		{
			this->m_pMeshBuffers[meshId].m_pBindposeVertexBuffer->Release();
			this->m_pMeshBuffers[meshId].m_pIndexBuffer->Release();
			this->m_pMeshBuffers[meshId].m_pTexture->Release();
			this->m_pMeshBuffers[meshId].m_pUVBuffer->Release();
			this->m_pMeshBuffers[meshId].m_pWeightBuffer->Release();
			this->m_pMeshBuffers[meshId].m_pVertexArray->Release();
		}
		delete []this->m_pMeshBuffers;
	}
	
	void md5Model::Release()
	{
		Deinit();
	}
}

