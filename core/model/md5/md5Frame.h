#ifndef __MD5FRAME_H__
#define __MD5FRAME_H__

#include "md5.h"
#include <gl/glew.h>
#include <glm/glm.hpp>
#include <stdint.h>
#include <core/bufferogl.h>
#include <core/texogl.h>
#include <core/effectogl.h>

using namespace model::md5;

namespace Graphics
{
	typedef struct
	{
		uint32_t 						m_nNumVertices;				// 顶点数
		Graphics::VertexArray*			m_pVertexArray;				// 渲染此 Mesh 的 VAO
		// 以下是 顶点数据
		Graphics::VertexBuffer*			m_pBindposeVertexBuffer;	// VAO  ==>  Bindpose vertices（默认绑定的 vertex buffer）
		Graphics::VertexBuffer*			m_pIndexBuffer;				// VAO  ==>  IBO
		Graphics::VertexBuffer*  		m_pUVBuffer;				// VAO  ==>  UV
		Graphics::VertexBuffer*			m_pWeightBuffer;			// VAO  ==>  Weight（权重数据）
		Graphics::TexOGL*				m_pTexture;
	}MD5Mesh,*MD5MeshPtr;

	typedef struct
	{
		// 计算用
		AnimFilePtr						m_pAnimFile;				// 动画信息（插值的时候要从这里面取 四元数 以及 位移信息）
		// 渲染用
		glm::mat4*						m_pInverseBoneMatrices;		// 默认绑定状态的矩阵
		uint16_t						m_nNumMeshes;				// mesh 数量
		// Joint矩阵插值缓存
		JointPtr						m_pJointArrayA;				// 帧1缓存
		JointPtr						m_pJointArrayB;				// 帧2缓存
		// 通过 uniform 数组传递
		glm::mat4*						m_pBoneMatrices;			// 将要渲染的这一帧 对应的 骨骼变换的矩阵~
		// 通过 VAO 传递
		MD5MeshPtr						m_pMeshes;					// mesh 数组
	}MD5Model,*MD5ModelPtr;

	void InitMD5Model( MD5ModelPtr _pModel ,MD5FilePtr _pFile );
	void CalculateAnimMatrices(MD5ModelPtr _pModel, uint64_t animTime);
	void RenderMD5(MD5ModelPtr _pModel, EffectOGL * _pEffect,uint64_t animTime );
};



typedef struct
{
	ow::IBuffer * 			m_pUVBuffer;
	ow::IBuffer * 			m_pIndicesBuffer;
	
	ow::IBuffer *			m_pFinalVertices;
	
	uint32_t			m_nNumVertices;
    uint32_t            m_nNumIndices;
    
    char                m_szTexDiffuse[128];
}SubMesh,*SubMeshPtr,*SubMeshArray;

typedef struct
{
	JointArray			m_pJoints;
	JointArray			m_pJointsNextFrame;
	uint32_t			m_nNumMeshes;
	SubMeshArray	    m_pMeshes;
} MD5Frame, * MD5FramePtr;

void MD5FrameInit(MD5FramePtr _pFrame,MD5FilePtr _pFile);
void MD5FrameDestroy(MD5FramePtr _pFrame);

void GetMD5DefaultFrame(MD5FramePtr _pFrame,MD5FilePtr _pMD5File);
void GetMD5KeyFrame(MD5FramePtr _pFrame,MD5FilePtr _pMD5File,uint32_t _nFrameIndex);

#endif
