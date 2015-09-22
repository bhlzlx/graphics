#ifndef __MD5_MODEL_PARSER_H__
#define __MD5_MODEL_PARSER_H__

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stdint.h>
#include <buffer/buffer.h>

namespace model
{
#define JOINT_NAME_MAX 128
#define FILENAME_MAX 128
	typedef glm::vec3 	fvector3;
	typedef glm::vec4 	fvector4;
	typedef glm::ivec3 	ivector3;
	typedef glm::ivec4  ivector4;
	typedef glm::mat4   matrix_4x4;
	typedef glm::quat 	quat;
	
	struct md5Joint
	{
		fvector3			m_vecOffset;
		quat   				m_quaOrient;
	};
	
	// mesh文件中的  joint关系数据
	struct md5JointMapA
	{
		char 				m_szName[JOINT_NAME_MAX];
		int32_t 			m_iParentIndex;
	};
	
	struct md5Weight
	{
		int32_t 			m_iJointIndex;
		fvector3			m_vecOffset;
		float				m_fBias;
	};
	
	//
	struct md5Vertex
	{
		// 纹理坐标
		float				m_addr_U;
		float				m_addr_V;
		// weight相关
		int32_t				m_nStart;
		int32_t				m_nCount;
	};
	
	struct md5Mesh
	{
		char 				m_szTexture[FILENAME_MAX];
		
		int32_t				m_nNumVertices;
		int32_t				m_nNumWeight;
		int32_t				m_nNumTriangles;
		
		md5Vertex*			m_pVertices;
		ivector3*			m_pTriangles;
		md5Weight*			m_pWeights;
	};
	
	struct md5MeshModel
	{
		int32_t				m_iVersion;
		int32_t				m_nNumJoints;
		int32_t				m_nNumMeshes;
		
		md5JointMapA*		m_pJointMap;
		md5Joint*			m_pJoints;
		md5Mesh*			m_pMeshes;
	};
	
	// Anim相关的数据结构
	// anim文件中的  joint关系数据
	struct md5JointMapB
	{
		char 				m_szName[JOINT_NAME_MAX];
		char				m_cEffectFlag;
		int32_t				m_iParentIndex;
		int32_t				m_iEffectStart;
	};
	
	struct md5Bound
	{
		fvector3			m_vecMin;
		fvector3			m_vecMax;
	};
	
	struct md5AnimModel
	{
		int32_t 			m_iVersion;
		int32_t				m_nNumFrames;
		int32_t				m_nNumJoints;
		int32_t				m_iFrameRate;
		int32_t				m_nNumAnimateComponents;
		
		md5JointMapB*		m_pJointMap;
		md5Bound*			m_pBounds;
		md5Joint*			m_pBaseFrame;
		md5Joint**			m_pKeyFrames;
	};
	
	void InitMeshModel(md5MeshModel * _pMeshModel, IBuffer * _pBuffer);
	void ClearMeshModel(md5MeshModel * _pMeshModel);
	IBuffer * GetUVBuffer(md5Mesh * _pMesh);
	
	void InitAnimModel(md5AnimModel * _pAnimModel, IBuffer * _pBuffer);
	void ClearAnimModel(md5AnimModel * _pAnimModel);
}

#endif // __MD5_MODEL_PARSER_H__
