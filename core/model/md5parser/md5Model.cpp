#include <gl/glew.h>
#include "md5Model.h"

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
		// 分配meshbuffer
		this->m_nNumMeshes = m_meshModel.m_nNumMeshes;
		this->m_pMeshBuffers = new md5MeshBuffer[m_meshModel.m_nNumMeshes];
		// 计算插值所需缓冲
		this->m_pTJointsA = new md5Joint[m_meshModel.m_nNumJoints];
		this->m_pTJointsB = new md5Joint[m_meshModel.m_nNumJoints];
		// 为每个mesh创建相应的 buffer objects
		md5Mesh * pSubMesh = NULL;
		md5MeshBuffer * pSubMeshBuffer = NULL;
		for(int32_t meshIndex = 0;meshIndex < m_meshModel.m_nNumMeshes; ++meshIndex)
		{
			// 获取子mesh
			pSubMesh = m_meshModel.m_pMeshes + meshIndex;
			pSubMeshBuffer = this->m_pMeshBuffers + meshIndex;
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
				pWeightElements[vertIndex].m_nNumJointCount = pVert->m_nCount;
				for(int32_t w = 0; w<pVert->m_nCount; ++w)
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
		this->m_pInverseBoneMatrices = new matrix_4x4[nNumJoints];
		for(uint32_t j = 0;j<nNumJoints;++j)
		{
			quat q = m_meshModel.m_pJoints[j].m_quaOrient;
			fvector3 offset = m_meshModel.m_pJoints[j].m_vecOffset;
			matrix_4x4 boneMat = glm::translate( matrix_4x4(1.0),offset) * glm::mat4_cast( q );
			// 求逆矩阵
			m_pInverseBoneMatrices[j] = glm::inverse( boneMat );
		}
		
	}
	
	// 解析anim添加到anim列表中
	void md5Model::AddAnimation( const char * _szAnimFile)
	{
		
	}
}

