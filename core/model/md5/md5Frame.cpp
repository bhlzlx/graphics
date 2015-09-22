#include "md5Frame.h"
#include <memory.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/glm.hpp>
#include <common/log/logger.h>

namespace Graphics
{
	struct __inner_weight_info__
	{
		int weightCnt;
		int jointIdx[4];
		float bias[4];
	};
	
	void InitMD5Model( MD5ModelPtr _pModel ,MD5FilePtr _pFile )
	{
		_pModel->m_pAnimFile = _pFile->m_pAnimFile;
		// 分配meshes
		_pModel->m_nNumMeshes = _pFile->m_pMeshFile->m_nNumMeshes;
		_pModel->m_pMeshes = new Graphics::MD5Mesh[ _pModel->m_nNumMeshes ];
		_pModel->m_pJointArrayA = new Joint[_pFile->m_pMeshFile->m_nNumJoints];
		_pModel->m_pJointArrayB = new Joint[_pFile->m_pMeshFile->m_nNumJoints];
		Graphics::MD5Mesh* pMD5Mesh = NULL;
		for(int i = 0;i<_pModel->m_nNumMeshes;++i)
		{
			// 初始化mesh信息
			pMD5Mesh = _pModel->m_pMeshes + i;
			// 创建 vertex array
			pMD5Mesh->m_pVertexArray = Graphics::VertexArray::CreateVertexArray();
			// 创建 ibo
			uint32_t nIndexBufferSize = _pFile->m_pMeshFile->m_pMeshes[i].m_nNumTriangles * sizeof(Triple<unsigned int>);
			char* pIndexBuffer = (char *)&_pFile->m_pMeshFile->m_pMeshes[i].m_pTringles[0];
			pMD5Mesh->m_pIndexBuffer = Graphics::VertexBuffer::CreateBuffer(pIndexBuffer,nIndexBufferSize);
			 // 创建 uv buffer object
			IBuffer * pUVBuffer = model::md5::GetUVBuffer(&_pFile->m_pMeshFile->m_pMeshes[i]);
			pMD5Mesh->m_pUVBuffer = Graphics::VertexBuffer::CreateBuffer(pUVBuffer->GetBuffer(),pUVBuffer->GetLength());
			pUVBuffer->Release();
			// 创建 weight（权重）相关的 buffer object
			// weight数量[1] - bias[4] - jointindex[4]
			uint32_t nWeightSize = sizeof(__inner_weight_info__) * _pFile->m_pMeshFile->m_pMeshes[i].m_nNumVertices;
			__inner_weight_info__ * pWeightInfos = new __inner_weight_info__[_pFile->m_pMeshFile->m_pMeshes[i].m_nNumVertices];
			// 设计每一个顶点的weight数据
			model::md5::WeightPtr pWeightArray = _pFile->m_pMeshFile->m_pMeshes[i].m_pWeights;
			model::md5::VertexPtr pVerticeArray = _pFile->m_pMeshFile->m_pMeshes[i].m_pVertices;
			// 遍历顶点
			int vertIndex;
			for(vertIndex = 0;vertIndex<_pFile->m_pMeshFile->m_pMeshes[i].m_nNumVertices;++vertIndex)
			{
				model::md5::VertexPtr pVert = pVerticeArray + vertIndex;
				__inner_weight_info__ * pWeight = pWeightInfos + vertIndex;
				// 权重数量
				pWeight->weightCnt = pVert->m_nWeightCount;
				int weightIdStart = pVert->m_nWeightStart;
				// 各权重的比例，以及joint index
				for(int w = 0;w<4;++w)
				{
					model::md5::WeightPtr pw = pWeightArray + weightIdStart + w;
					pWeight->bias[w]= pw->m_fBias;
					pWeight->jointIdx[w] = pw->m_nJointIndex;
				}
			}
			pMD5Mesh->m_pWeightBuffer = Graphics::VertexBuffer::CreateBuffer(pWeightInfos,nWeightSize);
			delete []pWeightInfos;
			// 设设置 vao
			pMD5Mesh->m_pVertexArray->SetVertexBuffer(2,pMD5Mesh->m_pUVBuffer,2,0,0);
			pMD5Mesh->m_pVertexArray->SetVertexBufferI(3,pMD5Mesh->m_pWeightBuffer,1,sizeof(__inner_weight_info__),0,GL_INT);
			pMD5Mesh->m_pVertexArray->SetVertexBufferI(4,pMD5Mesh->m_pWeightBuffer,4,sizeof(__inner_weight_info__),sizeof(int),GL_INT);
			pMD5Mesh->m_pVertexArray->SetVertexBuffer(5,pMD5Mesh->m_pWeightBuffer,4,sizeof(__inner_weight_info__),sizeof(int)*5,GL_FLOAT);
			pMD5Mesh->m_pVertexArray->SetIndexBuffer(pMD5Mesh->m_pIndexBuffer);
		}
		
		uint32_t nNumJoints = _pFile->m_pMeshFile->m_nNumJoints;
		// 创建默认绑定 bone的 逆矩阵
		_pModel->m_pInverseBoneMatrices = new glm::mat4[nNumJoints];
		for(int j = 0;j<nNumJoints;++j)
		{
			glm::quat q = _pFile->m_pMeshFile->m_pJointArray[j].m_quaOrient;
			glm::vec3 offset = _pFile->m_pMeshFile->m_pJointArray[j].m_vecOffset;
			glm::mat4 boneMat = glm::translate( glm::mat4(1.0),offset) * glm::mat4_cast( q );
			// 求逆矩阵
			_pModel->m_pInverseBoneMatrices[j] = glm::inverse( boneMat );
		}
		// 处理默认绑定的顶点位置		
		JointArray pJoints = _pFile->m_pMeshFile->m_pJointArray;
		for(int meshIdx = 0;meshIdx < _pFile->m_pMeshFile->m_nNumMeshes; ++meshIdx)
		{
			// 生成纹理
			pMD5Mesh = _pModel->m_pMeshes + meshIdx;
			IBufferPtr pImageBuffer = BufferFromFile(_pFile->m_pMeshFile->m_pMeshes[meshIdx].m_szTexture);
			if(pImageBuffer)
			{
				Image * image = Image::ImageFromPng(pImageBuffer);
				_pModel->m_pMeshes[meshIdx].m_pTexture = TexOGL::CreateTexWidthImage(image,true);
				image->Release();
				pImageBuffer->Release();
			}
			else
			{
				assert(false);
			}			
			// 创建 mesh vertex buffer
			uint32_t nNumVertices = _pFile->m_pMeshFile->m_pMeshes[meshIdx].m_nNumVertices;
			IBufferPtr pBindPoseBuffer = CreateStandardBuffer( nNumVertices * sizeof(float) * 3);
			glm::vec3 * pVec = (glm::vec3 *)pBindPoseBuffer->GetBuffer();
			// 计算bindpose的顶点坐标
			for(int vertIdx = 0;vertIdx < nNumVertices ;++vertIdx)
			{
				// 累积 weight bias 计算顶点
				glm::vec3 result = glm::vec3(0,0,0);
				VertexPtr pVert = _pFile->m_pMeshFile->m_pMeshes[meshIdx].m_pVertices + vertIdx;
				for(int weightIdx = pVert->m_nWeightStart; weightIdx < pVert->m_nWeightCount + pVert->m_nWeightStart; ++weightIdx )
				{
					WeightPtr pWeight = _pFile->m_pMeshFile->m_pMeshes[meshIdx].m_pWeights+weightIdx;
					uint32_t nJointIndex = pWeight->m_nJointIndex;
					glm::quat q = _pFile->m_pMeshFile->m_pJointArray[nJointIndex].m_quaOrient;
					glm::vec3 offset = _pFile->m_pMeshFile->m_pJointArray[nJointIndex].m_vecOffset;
					result += (offset + q * pWeight->m_vecPos) * pWeight->m_fBias;
				}
				pVec[vertIdx] = result;
			}
			// 创建 vbo
			pMD5Mesh->m_pBindposeVertexBuffer = Graphics::VertexBuffer::CreateBuffer(pVec,pBindPoseBuffer->GetLength());
			pMD5Mesh->m_pVertexArray->SetVertexBuffer(0,pMD5Mesh->m_pBindposeVertexBuffer,3,0,0);
			pMD5Mesh->m_nNumVertices = _pFile->m_pMeshFile->m_pMeshes[meshIdx].m_nNumTriangles * 3;
			pBindPoseBuffer->Release();
		}
		// 为每一帧的matrix数组分配空间
		_pModel->m_pBoneMatrices = new glm::mat4[nNumJoints];
		//_pModel->m_pBoneMatrices = CreateStandardBuffer( sizeof(glm::mat4) * nNumJoints );
		// 解析模型完成
	}
	
	// 给两帧插值
	void CalculateAnimMatrices(MD5ModelPtr _pModel, unsigned long long _nAnimTime /*m seconds*/)
	{
		uint32_t nFrameRate = _pModel->m_pAnimFile->m_nNumFrameRate;
		uint32_t nNumFrames = _pModel->m_pAnimFile->m_nNumFrames;
		float    nFrameTime = (float)1000 / (float)nFrameRate;
		uint32_t nCycleTime = (float)(nNumFrames - 1)/(float)nFrameRate * 1000.f;
		uint32_t currTime = _nAnimTime  - ((unsigned int)(_nAnimTime / nCycleTime) * nCycleTime);
		uint32_t frame_idx_1 = (unsigned int)(currTime / nFrameTime);
		uint32_t frame_idx_2 = frame_idx_1 + 1;
		
		uint32_t biasTime = currTime - ((unsigned int)(currTime / nFrameTime) * nFrameTime);
		float frameBias = (float)biasTime / (float)nFrameTime;
		
		// 分配joints
		JointArray pJointOutA = _pModel->m_pJointArrayA;
		JointArray pJointOutB = _pModel->m_pJointArrayB;
		
		JointArray pJointInA = _pModel->m_pAnimFile->m_pKeyFrames[frame_idx_1];
		JointArray pJointInB = _pModel->m_pAnimFile->m_pKeyFrames[frame_idx_2];
		// 根骨骼直接赋值
		memcpy(pJointOutA,pJointInA,sizeof(Joint) * _pModel->m_pAnimFile->m_nNumJoints);
		memcpy(pJointOutB,pJointInB,sizeof(Joint) * _pModel->m_pAnimFile->m_nNumJoints);
		// Joint映射表 读父子关系数据
		JointMapPtr jointMap = _pModel->m_pAnimFile->m_pJointMap;
		// 累积骨骼1 的变换
		for(int jointIndex = 1;jointIndex< _pModel->m_pAnimFile->m_nNumJoints;++jointIndex)
		{
			uint32_t parentJointIdx = jointMap[jointIndex].m_nParentIndex;
			JointPtr pJoint = pJointOutA + jointIndex;
			JointPtr pParentJoint = pJointOutA + parentJointIdx;
			pJointOutA[jointIndex].m_vecOffset = pParentJoint->m_vecOffset + pParentJoint->m_quaOrient * pJoint->m_vecOffset;
			pJointOutA[jointIndex].m_quaOrient = pParentJoint->m_quaOrient * pJoint->m_quaOrient;
		}
		// 累积骨骼2 的变换
		for(int jointIndex = 1;jointIndex< _pModel->m_pAnimFile->m_nNumJoints;++jointIndex)
		{
			uint32_t parentJointIdx = jointMap[jointIndex].m_nParentIndex;
			JointPtr pJoint = pJointOutB + jointIndex;
			JointPtr pParentJoint = pJointOutB + parentJointIdx;
			pJointOutB[jointIndex].m_vecOffset = pParentJoint->m_vecOffset + pParentJoint->m_quaOrient * pJoint->m_vecOffset;
			pJointOutB[jointIndex].m_quaOrient = pParentJoint->m_quaOrient * pJoint->m_quaOrient;
		}
		// 将结果插值到 结果矩阵列表
		for(int jointIndex = 0;jointIndex< _pModel->m_pAnimFile->m_nNumJoints;++jointIndex)
		{
			glm::quat q = glm::slerp(pJointOutA[jointIndex].m_quaOrient,pJointOutB[jointIndex].m_quaOrient,frameBias);
			glm::vec3 offset = pJointOutA[jointIndex].m_vecOffset + ( pJointOutB[jointIndex].m_vecOffset - pJointOutA[jointIndex].m_vecOffset ) * frameBias;
			// 生成矩阵
			// 别忘记乘默认绑定位置的逆矩阵
			_pModel->m_pBoneMatrices[jointIndex] = (glm::translate( glm::mat4(1.0) ,offset ) * glm::mat4_cast(q) ) * _pModel->m_pInverseBoneMatrices[jointIndex] ;
		}
	}
	
	void RenderMD5(MD5ModelPtr _pModel, EffectOGL * _pEffect,uint64_t _animTime )
	{
		// 生成插值矩阵
		CalculateAnimMatrices(_pModel,_animTime);
		uint32_t nElement = _pModel->m_pAnimFile->m_nNumJoints;
		_pEffect->m_pShader->SetUniformData(_pModel->m_pBoneMatrices,"BONE_MATRICES",nElement);
		MD5MeshPtr pMesh = NULL;
		for(int meshIdx = 0;meshIdx < _pModel->m_nNumMeshes; ++meshIdx)
		{
			pMesh = _pModel->m_pMeshes + meshIdx;
			// 设置纹理
			_pEffect->m_pShader->SetTexture(0,pMesh->m_pTexture);
			// 设置vao
			pMesh->m_pVertexArray->Bind();
            pMesh->m_pVertexArray->Draw( pMesh->m_nNumVertices );
		}
	}

};

void MD5FrameInit(MD5FramePtr _pFrame,MD5FilePtr _pFile)
{
	_pFrame->m_pJoints = new Joint[_pFile->m_pMeshFile->m_nNumJoints];
	_pFrame->m_pJointsNextFrame = new Joint[_pFile->m_pMeshFile->m_nNumJoints];
	_pFrame->m_pMeshes = new SubMesh[_pFile->m_pMeshFile->m_nNumMeshes];
	_pFrame->m_nNumMeshes = _pFile->m_pMeshFile->m_nNumMeshes;
}

void MD5FrameDestroy(MD5FramePtr _pFrame)
{
	delete []_pFrame->m_pJoints;// = new Joint[_pFile->m_pMeshFile->m_nNumJoints];
	delete []_pFrame->m_pJointsNextFrame;// = new Joint[_pFile->m_pMeshFile->m_nNumJoints];
	delete []_pFrame->m_pMeshes;// = new SubMesh[_pFile->m_pMeshFile->m_nNumMeshes];
	_pFrame->m_nNumMeshes = 0;//_pFile->m_pMeshFile->m_nNumMeshes;
}

void GetMD5DefaultFrame(MD5FramePtr _pFrame,MD5FilePtr _pMD5File)
{
	// 分配joints
	_pFrame->m_pJoints = new Joint[_pMD5File->m_pMeshFile->m_nNumJoints];
	JointArray pJoints = _pMD5File->m_pMeshFile->m_pJointArray;
	// 复制joint信息
	memcpy(_pFrame->m_pJoints,pJoints,sizeof(Joint) * _pMD5File->m_pMeshFile->m_nNumJoints );
	
	uint32_t numMeshes = _pMD5File->m_pMeshFile->m_nNumMeshes;
	_pFrame->m_nNumMeshes = numMeshes;
	_pFrame->m_pMeshes = new SubMesh[numMeshes];
	// ¼ÆËãËùÓÐµÄmesh
	for (int i = 0;i < numMeshes ;++i)
	{
		// È¡µÃmeshÖ¸Õë
		SubMeshPtr pMesh = _pFrame->m_pMeshes + i;
		MeshPtr pOrigMesh = _pMD5File->m_pMeshFile->m_pMeshes + i;
		VertexPtr  pOrigVertices = pOrigMesh->m_pVertices;

		uint32_t numVertices = pOrigMesh->m_nNumVertices;
		uint32_t numTriangles = pOrigMesh->m_nNumTriangles;		
		uint32_t numWeight = pOrigMesh->m_nNumWeights;
		pMesh->m_nNumIndices = numTriangles * 3;
		pMesh->m_nNumVertices = numVertices;
		// 三个buffer
		// index buffer 和 uv buffer 是固定的，关键是这个vertex buffer是动态计算的
		pMesh->m_pIndicesBuffer = GetIndexBuffer(pOrigMesh);
		pMesh->m_pUVBuffer = GetUVBuffer(pOrigMesh);
		// 纹理路径
        strcpy(pMesh->m_szTexDiffuse,pOrigMesh->m_szTexture);
		
		VertexPtr pVertex = NULL;
		// 分配vertex buffer 空间
		pMesh->m_pFinalVertices = CreateStandardBuffer( numVertices * sizeof(float) * 3);
		for(int j = 0; j<numVertices; ++j)
		{
			pVertex = pOrigVertices + j;
			// ´¦Àímesh¶¥µãÎ»ÖÃ
			WeightPtr pWeight = NULL;
			glm::vec3 result(0,0,0);
			for(int k = pVertex->m_nWeightStart;k<pVertex->m_nWeightCount + pVertex->m_nWeightStart;++k)
			{
				pWeight = pOrigMesh->m_pWeights + k;
				uint32_t nJointIndex = pWeight->m_nJointIndex;
				glm::quat q = _pFrame->m_pJoints[nJointIndex].m_quaOrient;
				glm::vec3 offset = _pFrame->m_pJoints[nJointIndex].m_vecOffset;
                result += (offset + q * pWeight->m_vecPos) * pWeight->m_fBias;
			}
			glm::vec3 * pFinalVertices = (glm::vec3 *)pMesh->m_pFinalVertices->GetBuffer();
			pFinalVertices[j] = result;
		}
	}
}

void GetMD5KeyFrame(MD5FramePtr _pFrame,MD5FilePtr _pMD5File,uint32_t _mSeconds)
{
	uint32_t nFrameRate = _pMD5File->m_pAnimFile->m_nNumFrameRate;
	uint32_t nNumFrames = _pMD5File->m_pAnimFile->m_nNumFrames;
	float    nFrameTime = (float)1000 / (float)nFrameRate;
	uint32_t nCycleTime = (float)(nNumFrames - 1)/(float)nFrameRate * 1000.f;
	uint32_t currTime = _mSeconds  - ((unsigned int)(_mSeconds / nCycleTime) * nCycleTime);
	uint32_t frame_idx_1 = (unsigned int)(currTime / nFrameTime);
	uint32_t frame_idx_2 = frame_idx_1 + 1;
	
	uint32_t biasTime = currTime - ((unsigned int)(currTime / nFrameTime) * nFrameTime);
	float frameBias = (float)biasTime / (float)nFrameTime;
	
	// 分配joints
	JointArray pJoints = _pMD5File->m_pAnimFile->m_pKeyFrames[frame_idx_1];
	JointArray pJointsSecond = _pMD5File->m_pAnimFile->m_pKeyFrames[frame_idx_2];
	// 复制joint信息
	memcpy(_pFrame->m_pJoints,		   pJoints				,sizeof(Joint) * _pMD5File->m_pMeshFile->m_nNumJoints );
	memcpy(_pFrame->m_pJointsNextFrame,pJointsSecond		,sizeof(Joint) * _pMD5File->m_pMeshFile->m_nNumJoints );
	// Joint映射表 读父子关系数据
	JointMapPtr jointMap = _pMD5File->m_pMeshFile->m_pJointMap;
	// 累积骨骼1 的变换
	for(int jointIndex = 1;jointIndex< _pMD5File->m_pMeshFile->m_nNumJoints;++jointIndex)
	{
		uint32_t parentJointIdx = jointMap[jointIndex].m_nParentIndex;
		JointPtr pJoint = _pFrame->m_pJoints + jointIndex;
		JointPtr pParentJoint = _pFrame->m_pJoints + parentJointIdx;
		pJoint->m_vecOffset = pParentJoint->m_vecOffset + pParentJoint->m_quaOrient * pJoint->m_vecOffset;
		pJoint->m_quaOrient = pParentJoint->m_quaOrient * pJoint->m_quaOrient;
		glm::normalize(pJoint->m_quaOrient);
	}
	// 累积骨骼2 的变换
	for(int jointIndex = 1;jointIndex< _pMD5File->m_pMeshFile->m_nNumJoints;++jointIndex)
	{
		uint32_t parentJointIdx = jointMap[jointIndex].m_nParentIndex;
		JointPtr pJoint = _pFrame->m_pJointsNextFrame + jointIndex;
		JointPtr pParentJoint = _pFrame->m_pJointsNextFrame + parentJointIdx;
		pJoint->m_vecOffset = pParentJoint->m_vecOffset + pParentJoint->m_quaOrient * pJoint->m_vecOffset;
		pJoint->m_quaOrient = pParentJoint->m_quaOrient * pJoint->m_quaOrient;
		glm::normalize(pJoint->m_quaOrient);
	}
	
	uint32_t numMeshes = _pMD5File->m_pMeshFile->m_nNumMeshes;
	assert(_pFrame->m_nNumMeshes == numMeshes);
	// ¼ÆËãËùÓÐµÄmesh
	for (int i = 0;i < numMeshes ;++i)
	{
		// È¡µÃmeshÖ¸Õë
		SubMeshPtr pMesh = _pFrame->m_pMeshes + i;
		MeshPtr pOrigMesh = _pMD5File->m_pMeshFile->m_pMeshes + i;
		VertexPtr  pOrigVertices = pOrigMesh->m_pVertices;
		uint32_t numVertices = pOrigMesh->m_nNumVertices;
		uint32_t numTriangles = pOrigMesh->m_nNumTriangles;
		uint32_t numWeight = pOrigMesh->m_nNumWeights;
		pMesh->m_nNumIndices = numTriangles * 3;
		pMesh->m_nNumVertices = numVertices;
		// 三个buffer
		// index buffer 和 uv buffer 是固定的，关键是这个vertex buffer是动态计算的
		pMesh->m_pIndicesBuffer = GetIndexBuffer(pOrigMesh);
		pMesh->m_pUVBuffer = GetUVBuffer(pOrigMesh);
		// 纹理路径
        strcpy(pMesh->m_szTexDiffuse,pOrigMesh->m_szTexture);
		
		VertexPtr pVertex = NULL;
		// 分配vertex buffer 空间
		pMesh->m_pFinalVertices = CreateStandardBuffer( numVertices * sizeof(float) * 3);
		for(int j = 0; j<numVertices; ++j)
		{
			pVertex = pOrigVertices + j;
			// ´¦Àímesh¶¥µãÎ»ÖÃ
			WeightPtr pWeight = NULL;
			glm::vec3 result(0,0,0);
			for(int k = pVertex->m_nWeightStart;k<pVertex->m_nWeightCount + pVertex->m_nWeightStart;++k)
			{
				pWeight = pOrigMesh->m_pWeights + k;
				uint32_t nJointIndex = pWeight->m_nJointIndex;
				glm::quat q = glm::slerp(_pFrame->m_pJoints[nJointIndex].m_quaOrient,_pFrame->m_pJointsNextFrame[nJointIndex].m_quaOrient,frameBias);
				glm::vec3 offset = _pFrame->m_pJoints[nJointIndex].m_vecOffset + ( _pFrame->m_pJointsNextFrame[nJointIndex].m_vecOffset - _pFrame->m_pJoints[nJointIndex].m_vecOffset ) * frameBias;
                result += (offset + q * pWeight->m_vecPos) * pWeight->m_fBias;
			}
			glm::vec3 * pFinalVertices = (glm::vec3 *)pMesh->m_pFinalVertices->GetBuffer();
			pFinalVertices[j] = result;
		}
	}
}
/*
void CreateMotion(MD5FramePtr _pFrame,MD5FilePtr _pMD5File,uint32_t _nFrameIndex)
{
	// 分配joints
	JointArray pJoints = _pMD5File->m_pAnimFile->m_pKeyFrames[_nFrameIndex];
	_pFrame->m_pJoints = new Joint[_pMD5File->m_pMeshFile->m_nNumJoints];
	// 复制joint信息
	memcpy(_pFrame->m_pJoints,pJoints,sizeof(Joint) * _pMD5File->m_pMeshFile->m_nNumJoints );
	// Joint映射表 读父子关系数据
	JointMapPtr jointMap = _pMD5File->m_pMeshFile->m_pJointMap;
	// 累积结点位置
	for(int jointIndex = 1;jointIndex< _pMD5File->m_pMeshFile->m_nNumJoints;++jointIndex)
	{
		uint32_t parentJointIdx = jointMap[jointIndex].m_nParentIndex;
		JointPtr pJoint = _pFrame->m_pJoints + jointIndex;
		JointPtr pParentJoint = _pFrame->m_pJoints + parentJointIdx;
		pJoint->m_vecOffset = pParentJoint->m_vecOffset + pParentJoint->m_quaOrient * pJoint->m_vecOffset;
		pJoint->m_quaOrient = pParentJoint->m_quaOrient * pJoint->m_quaOrient;
		glm::normalize(pJoint->m_quaOrient);
	}
	
	uint32_t numMeshes = _pMD5File->m_pMeshFile->m_nNumMeshes;
	_pFrame->m_nNumMeshes = numMeshes;
	_pFrame->m_pMeshes = new SubMesh[numMeshes];
	// ¼ÆËãËùÓÐµÄmesh
	for (int i = 0;i < numMeshes ;++i)
	{
		// È¡µÃmeshÖ¸Õë
		SubMeshPtr pMesh = _pFrame->m_pMeshes + i;
		MeshPtr pOrigMesh = _pMD5File->m_pMeshFile->m_pMeshes + i;
		VertexPtr  pOrigVertices = pOrigMesh->m_pVertices;
		uint32_t numVertices = pOrigMesh->m_nNumVertices;
		uint32_t numTriangles = pOrigMesh->m_nNumTriangles;
		uint32_t numWeight = pOrigMesh->m_nNumWeights;
		pMesh->m_nNumIndices = numTriangles * 3;
		pMesh->m_nNumVertices = numVertices;
		// 三个buffer
		// index buffer 和 uv buffer 是固定的，关键是这个vertex buffer是动态计算的
		pMesh->m_pIndicesBuffer = GetIndexBuffer(pOrigMesh);
		pMesh->m_pUVBuffer = GetUVBuffer(pOrigMesh);
		// 纹理路径
        strcpy(pMesh->m_szTexDiffuse,pOrigMesh->m_szTexture);
		
		VertexPtr pVertex = NULL;
		// 分配vertex buffer 空间
		pMesh->m_pFinalVertices = CreateStandardBuffer( numVertices * sizeof(float) * 3);
		for(int j = 0; j<numVertices; ++j)
		{
			pVertex = pOrigVertices + j;
			// ´¦Àímesh¶¥µãÎ»ÖÃ
			WeightPtr pWeight = NULL;
			glm::vec3 result(0,0,0);
			for(int k = pVertex->m_nWeightStart;k<pVertex->m_nWeightCount + pVertex->m_nWeightStart;++k)
			{
				pWeight = pOrigMesh->m_pWeights + k;
				uint32_t nJointIndex = pWeight->m_nJointIndex;
				glm::quat q = _pFrame->m_pJoints[nJointIndex].m_quaOrient;
				glm::vec3 offset = _pFrame->m_pJoints[nJointIndex].m_vecOffset;
                result += (offset + q * pWeight->m_vecPos) * pWeight->m_fBias;
			}
			glm::vec3 * pFinalVertices = (glm::vec3 *)pMesh->m_pFinalVertices->GetBuffer();
			pFinalVertices[j] = result;
		}
	}
}

/*
 * 			int         m_nVersion;
			int         m_nNumFrames;
			int         m_nNumJoints;
			int         m_nNumFrameRate;
			int         m_nNumAnimatedComponents;
			// 和 mesh 共用的 joints 数组~
			JointPtr    m_pJoints;
			// 每帧的包围盒
			BoundPtr    m_pBounds;
			// 默认关键帧
			KeyFrameJointPtr \
						m_pBaseFrame;
			// 关键帧列表
			KeyFrameJointPtr* \
						m_pKeyFrames;
 */
/*
void GetMD5KeyFrame(MD5FramePtr pFrame, MD5FilePtr pMD5File, int _nIndex)
{
    
    AnimFilePtr pAnimFile = pMD5File->m_pAnimFile;
    MeshFilePtr pMeshFile = pMD5File->m_pMeshFile;
    if(_nIndex >= pAnimFile->m_nNumFrames) 
    {
        return ;
    }
    // ÏÈ½âÎöjoints¾ØÕó
	pFrame->m_pJointOffset = new glm::vec3[pMD5File->m_pMeshFile->m_nNumJoints];
    pFrame->m_pJointOrients = new glm::quat[pMD5File->m_pMeshFile->m_nNumJoints];
    pFrame->m_pTransMats = new glm::mat4[pMD5File->m_pMeshFile->m_nNumJoints];
    
	Graphics::MD5::JointPtr pJoints = pMD5File->m_pMeshFile->m_pJoints;
    //KeyFrameJointPtr _pBaseFrame = pAnimFile->m_pBaseFrame;
    KeyFrameJointPtr pCurrFrame = pAnimFile->m_pKeyFrames[_nIndex];
    
    for(int i = 0;i<pMD5File->m_pMeshFile->m_nNumJoints;++i)
    {
        pJoints[i].m_quaOrient = pCurrFrame[i].m_quatRotation;
        pJoints[i].m_vecOffset = pCurrFrame[i].m_vecTranslate;
    }
    
    // // ¼ÆËã½Úµã¾ØÕó
	for (int i = 0;i<pMD5File->m_pMeshFile->m_nNumJoints;++i)
	{
        pFrame->m_pJointOrients[i] = pJoints->m_quaOrient; 
		pFrame->m_pJointOffset[i] =  pJoints->m_vecOffset;
		++pJoints;
	}
    
	// ¼ÆËãÀÛ»ý¾ØÕó ¸ù½áµã²»ÐèÒªÀÛ»ý£¬×Ó½áµãµÄË÷Òý±È¸¸½áµã´ó£¬ËùÒÔÏÈËã¸¸½áµãµÄÀÛ»ý¾ØÕó£¬×Ó½áµã ³Ë¡¡Ò»´Î¸¸½áµãµÄ¾ØÕó¾ÍÐÐÁË
	pJoints = pMD5File->m_pMeshFile->m_pJoints;
	for (int i = 1;i<pMD5File->m_pMeshFile->m_nNumJoints;++i)
	{
		int parentIndex = pJoints[i].m_pParentIndex;
        pFrame->m_pJointOffset[i] += pFrame->m_pJointOrients[parentIndex] * pFrame->m_pJointOffset[i];
        pFrame->m_pJointOrients[i] = pFrame->m_pJointOrients[parentIndex] * pFrame->m_pJointOrients[i];
        glm::normalize(pFrame->m_pJointOrients[i]);
	}
	// ¼ÆËãµãµÄÎ»ÖÃ
	uint32_t numMeshes = pMD5File->m_pMeshFile->m_nNumMeshes;
	pFrame->m_nNumMeshes = numMeshes;
	pFrame->m_pMeshes = new SubMesh[numMeshes];
	// ¼ÆËãËùÓÐµÄmesh
	for (int i = 0;i < numMeshes ;++i)
	{
		// È¡µÃmeshÖ¸Õë
		SubMeshPtr pMesh = pFrame->m_pMeshes + i;
		MeshPtr pOrigMesh = pMD5File->m_pMeshFile->m_pMeshes + i;
		VertexPtr  pOrigVertices = pOrigMesh->m_pVertices;

		uint32_t numVertices = pOrigMesh->m_nNumVertices;
		uint32_t numTriangles = pOrigMesh->m_nNumTriangles;		
		uint32_t numWeight = pOrigMesh->m_nNumWeights;
		// ´¦Àíindices
		pMesh->m_pIndices = new uint32_t [numTriangles * 3];		
		pMesh->m_pUVs = new glm::vec2[numVertices];
		pMesh->m_pVertices = new glm::vec3[numVertices];
        pMesh->m_nNumVertices = numVertices;
        pMesh->m_nNumIndices = numTriangles * 3;
        strcpy(pMesh->m_szTexDiffuse,pOrigMesh->m_szTexture);
		assert(sizeof(uint32_t) * 3 == sizeof(Triple<unsigned int>));
		// ´¦Àíindex £¬ Ö±½ÓÊ¹ÓÃmemcpy¸´ÖÆ¹ýÀ´£¬×¢ÒâÀàÐÍ±ØÐë¶¼ÊÇ unsigned int
		memcpy(pMesh->m_pIndices,pOrigMesh->m_pTringles,numTriangles * sizeof(Triple<unsigned int>));
		// ±éÀú¶¥µã£¬´¦ÀíuvºÍ¶¥µãÎ»ÖÃ
		VertexPtr pVertex = NULL;
		for(int j = 0; j<numVertices; ++j)
		{
			pVertex = pOrigVertices + j;
			// ´¦Àíuv
			pMesh->m_pUVs[j].x = pOrigMesh->m_pVertices[j].m_addr_U;
			pMesh->m_pUVs[j].y = 1 - pOrigMesh->m_pVertices[j].m_addr_V;
			// ´¦Àímesh¶¥µãÎ»ÖÃ
			WeightPtr pWeight = NULL;
			glm::vec3 result(0,0,0); // ¶¥µãÎ»ÖÃÀÛ¼ÓÖµ
			for(int k = pVertex->m_nWeightStart;k<pVertex->m_nWeightCount + pVertex->m_nWeightStart;++k)
			{
				pWeight = pOrigMesh->m_pWeights + k;
				glm::quat q = pFrame->m_pJointOrients[pWeight->m_nJointIndex];
                result += (pFrame->m_pJointOffset[pWeight->m_nJointIndex] + q * pWeight->m_vecPos) * pWeight->m_fBias;
			}
			pMesh->m_pVertices[j] = result;      
            static char message[128];
            sprintf(message,"vec : %f %f %f ---- %f %f \n",result.x,result.y,result.z,pMesh->m_pUVs[j].x,pMesh->m_pUVs[j].y);
            phantom::Logger::GetInstance(NULL)->Write(message);
		}
	}
}
*/