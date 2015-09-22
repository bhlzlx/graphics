#ifndef __MD5_PARSER_H__
#define __MD5_PARSER_H__

#include <stdint.h>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <buffer/buffer.h>

namespace model
{
	namespace md5
	{
		// joint 数据，包括位移 + 旋转四元数
		typedef struct
		{
			glm::vec3       m_vecOffset;
			glm::quat       m_quaOrient;
		} Joint,*JointPtr,*JointArray;
		
		typedef struct
		{
			char            m_szName[32];
			int				m_nParentIndex;
			char            m_cEffectFlag;
			int             m_nEffectStartIndex;
		} JointMap,*JointMapPtr;
		
		// Weight
		typedef struct
		{
			int				m_nJointIndex;
			float       	m_fBias;
			glm::vec3   	m_vecPos;
		}Weight,*WeightPtr,*WeightArray;
		
		// Vertex
		typedef struct
		{
			float 			m_addr_U;
			float 			m_addr_V;
			int   			m_nWeightStart;
			int   			m_nWeightCount;
		}Vertex,*VertexPtr,*VertexArray;
		
		// Mesh
		template <class type>
		struct Triple
		{
			type a;
			type b;
			type c;
		};
		
		typedef Triple<unsigned int>  *TriangleArray;
		
		typedef struct
		{
			char            		m_szTexture[128];
			int            	 		m_nNumVertices; 
			int             		m_nNumWeights;
			int             		m_nNumTriangles;
			
			VertexArray     		m_pVertices;
			TriangleArray		    m_pTringles;
			WeightArray     		m_pWeights;
		}Mesh,*MeshPtr,*MeshArray;
		
		// MeshFile
		typedef struct 
		{
			int						m_nVersion;		// 版本号
			unsigned				m_nNumJoints;	// 骨骼数
			unsigned				m_nNumMeshes;	// mesh数量
			
			JointMapPtr    			m_pJointMap;	// Joint骨骼结构组织信息
			JointArray				m_pJointArray;	// 默认Joint数组数据			
			MeshArray     			m_pMeshes;		// Mesh数组
		}MeshFile,*MeshFilePtr;
		
		typedef struct 
		{
			glm::vec3   			m_vecMin;
			glm::vec3				m_vecMax;
		}Bound, *BoundPtr,*BoundArray;
		
		typedef struct
		{
			int         			m_nVersion;		// 版本
			int         			m_nNumFrames;	// 帧数
			int         			m_nNumJoints;	// 骨骼数
			int         			m_nNumFrameRate;// 帧率
			int         			m_nNumAnimatedComponents;// 动画元素数量
			
			JointMapPtr    			m_pJointMap;	// 和 mesh 共用的 joints 数组~
			BoundArray    			m_pBounds;		// 包围盒数组			
			JointArray		  		m_pBaseFrame;	// BaseFrame
			JointArray*				m_pKeyFrames;	// 关键帧数组
		}AnimFile, * AnimFilePtr;
		
		typedef struct
		{
			MeshFile*         m_pMeshFile;
			AnimFile*         m_pAnimFile;
		}MD5File, *MD5FilePtr;
		
		void ParseMD5( IBuffer * _pMeshBuff, IBuffer * _pAnimBuff ,MD5FilePtr _pMD5File);
		void ClearMD5( MD5FilePtr _pMD5File );
		
		IBuffer * GetIndexBuffer(  MeshPtr _pMesh );
		IBuffer * GetUVBuffer(  MeshPtr _pMesh );
		IBuffer * GetBindPoseVertices(MeshPtr _pMesh);
	}
}

#endif // __MD5_PARSER_H__
