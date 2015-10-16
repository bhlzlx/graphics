#include "md5.h"
#include <cstdlib>
#include <memory.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <glm/glm.hpp>
#include <owcmn/log/logger.h>

#define VERSION_INFO    "MD5Version"
#define NUM_JOINTS      "numJoints"
#define NUM_MESHES      "numMeshes"
#define NUM_WEIGHT      "numweights"
#define NUM_TRIANGLES   "numtris"
#define NUM_VERTS       "numverts"
#define NUM_FRAMES      "numFrames"
#define FRAME_RATE      "frameRate"
#define NUM_ANIM_COMPONENTS "numAnimatedComponents"

#define JOINTS          "joints"
#define MESH            "mesh"
#define SHADER          "shader"
#define VERT            "vert"
#define TRINGLE         "tri"
#define WEIGHT          "weight"
#define HIERARCHY       "hierarchy"
#define BOUNDS          "bounds"
#define BASEFRAME       "baseframe"
#define FRAME           "frame"


#define LINE_LENGTH_MIN 4

using namespace ow;

namespace model
{
	namespace md5
	{
		const int __joint_num_element__ = 8;
		const int __vert_num_element__ = 6;
		const int __tri_num_element__ = 5;
		const int __weight_num_element__ = 7;
		
		struct __joint_access__
		{
			char szName[16];
			char szParentIndex[16];
			char szOffsetX[16];
			char szOffsetY[16];
			char szOffsetZ[16];
			char szOrientX[16];
			char szOrientY[16];
			char szOrientZ[16];
		};
		
		union __joint_read_struct__
		{
			__joint_access__ access;
			char data[__joint_num_element__][16];
		} ;
		
		struct __vert_access__
		{
			char szTypeName[16];
			char szIndex[16];
			char szAddrU[16];
			char szAddrV[16];
			char szWeightBeg[16];
			char szWeightCnt[16];
		};
		
		union __vert_read_struct__
		{
			__vert_access__ access;
			char data[__vert_num_element__][16];
		};
		
		struct __tri_access__
		{
			char szTypeName[16];
			char szIndex[16];
			char szVertA[16];
			char szVertB[16];
			char szVertC[16];
		};
		
		union __tri_read_struct__
		{
			__tri_access__ access;
			char data[__tri_num_element__][16];
		};
		
		struct __weight_access__
		{
			char szTypeName[16];
			char szIndex[16];
			char szJointIndex[16];
			char szBias[16];
			char szPosX[16];
			char szPosY[16];
			char szPosZ[16];
		};
		
		union __weight_read_struct__
		{
			__weight_access__ access;
			char data[__weight_num_element__][16];
		};
		
		/////////////////////////////////////////////////
		//             animation 解析
		/////////////////////////////////////////////////
		
		const int __num_hierarchy_element__ = 4;
		const int __num_bounds_element__ = 6;
		const int __num_frame_element__ = 6;
		
		struct __hierarchy_access__
		{
			char szTypeName[16];
			char szJointIndex[16];
			char szEffectFlag[16];
			char szEffectStartIndex[16];
		};
		
		union __hierarchy_read_struct__
		{
			__hierarchy_access__        access;
			char                        data[__num_hierarchy_element__][16];
		};
		
		struct __bound_access__
		{
			char szVecMinX[16];
			char szVecMinY[16];
			char szVecMinZ[16];
			char szVecMaxX[16];
			char szVecMaxY[16];
			char szVecMaxZ[16];
		};
		
		union __bound_read_struct__
		{
			__bound_access__            access;
			char                        data[__num_bounds_element__][16];
		};
		
		struct __frame_access__
		{
			char szVecOffsetX[16];
			char szVecOffsetY[16];
			char szVecOffsetZ[16];            
			char szVecOrientX[16];
			char szVecOrientY[16];
			char szVecOrientZ[16];
		};
		
		union __frame_read_struct__
		{
			__frame_access__            access;
			char                        data[__num_frame_element__][16];
		};
		
		glm::quat make_quat(float x, float y, float z)
		{
            glm::quat q(0,x,y,z);
            float t = 1.0f - ( q.x * q.x ) - ( q.y * q.y ) - ( q.z * q.z );
            if ( t < 0.0f )
            {
                q.w = 0.0f;
            }
            else
            {
                q.w = -sqrtf(t);
            }
			return q;
		}
		
		void strrmv(char * _szStr, char * _szKeys)
		{
			int nKey = strlen(_szKeys);
			int displace = 0;
			int i;
			for(i = 0;i<strlen(_szStr); ++i)
			{
				bool match = false;
				for(int j = 0;j<nKey;++j)
				{
					if(_szStr[i] == _szKeys[j])
					{
						match = true;
						--displace;
					}
				}
				if(!match)
				{
					_szStr[i + displace] = _szStr[i];
				}
			}
			_szStr[i + displace] = 0;
		}
		// 读一行
		// 自动跳过空行
		// 文件尾返回NULL
		char * read_line(ow::owBuffer * _pBuffer)
		{
			static char buffer[512];
			int length ;
again:
			length = 0;
			memset(buffer,0,512);
			while(true)
			{
				int ret = _pBuffer->Read((unsigned char *)buffer + length,1);
				if(ret == 0 )
				{
					if(length == 0)
						return NULL;
					else
						break;
				}
				++length;
				if(buffer[length - 1] == '\n')
				{
					if(length < LINE_LENGTH_MIN)
					{
						goto again;
					}
					break;
				}
			}
			buffer[length] = 0;
			return buffer;
		}
		// 读一个大括号模块
		ow::owBuffer * read_block_for_key(ow::owBuffer * _pBuffer, const char * _key)
		{
			char * pLine = read_line(_pBuffer);
			// 读key行
			while(true)
			{
				char * ret = strstr(pLine,_key);
				if(ret == NULL)
				{
					pLine = read_line(_pBuffer);
					if(pLine == NULL)
					{
						return NULL;
					}
				}
				else
				{
					break;
				}
			}
			// 找 '}'
			char * pContent = (char * )_pBuffer->GetCurr();
			char * pEnd = strchr(pContent,'}');
			
			owBuffer * pRet = CreateMemBuffer(pEnd - pContent);
			int n_read = _pBuffer->Read(pRet->GetBuffer(),pRet->Size() - 1);
			assert(n_read == pRet->Size() - 1);
			if(n_read != pRet->Size() - 1)
			{
				ow::Logger::GetInstance(NULL)->Write("md5.cpp :: read_block_for_key :: buffer read error!");
			}
			_pBuffer->Seek(SEEK_CUR,1L);            
			return pRet;
		}
		
		bool read_string_for_key(char * _szText ,const char * _szKey, char * _szBuff)
		{
			char * pch;
			pch = strtok (_szText," \t");
			int i = 0;
			while (pch != NULL)
			{
				if(i == 0)
				{
					if(strcmp(_szKey,pch) != 0)
					{
						return false;
					}
					++i;
				}
				else
				{
					strcpy(_szBuff,pch);
					strrmv(_szBuff,"\n\r\"");
					return true;
				}
				pch = strtok (NULL, " \t");
			}
		}
		
		bool  read_value_for_key(char * _szText ,const char * _szKey, int * _pValue)
		{
			char * pch;
			pch = strtok (_szText," \t");
			int i = 0;
			while (pch != NULL)
			{
				if(i == 0)
				{
					if(strcmp(_szKey,pch) != 0)
					{
						return false;
					}
					++i;
				}
				else
				{
					*_pValue = atoi(pch);
					if(*_pValue == 0 && *pch != '0')
					{
						return false;
					}
					return true;
				}
				pch = strtok (NULL, " \t");
			}
			return true;
		}
		
		bool ParseJoints(owBuffer * _pBuffer,MeshFilePtr _pMesh)
		{
			JointMapPtr pJointMap = _pMesh->m_pJointMap;
			JointArray pJointArray = _pMesh->m_pJointArray;
			
			char * pLine = NULL;
			__joint_read_struct__ joint_data;
			for(int i = 0;i<_pMesh->m_nNumJoints;++i)
			{                
				memset(&joint_data,0,sizeof(joint_data));
				// 获取一个有效的行
				pLine = read_line(_pBuffer);
				if(!pLine)
				{
					return false;
				}
				// 解析这一行
				char * pch;
				pch = strtok (pLine," \t()\n\r");
				int j = 0;
				while (pch != NULL && j < __joint_num_element__)
				{
					strcpy(&joint_data.data[j][0],pch);
					pch = strtok (NULL, " \t()\n\r");
					++j;
				}
				
				strcpy(pJointMap[i].m_szName,joint_data.access.szName);
				strrmv(pJointMap[i].m_szName,"\n\r\"");
				
				int nIndex = atoi(joint_data.access.szParentIndex);
				pJointMap[i].m_nParentIndex = nIndex;
				
				pJointArray[i].m_vecOffset.x = atof(joint_data.access.szOffsetX);
				pJointArray[i].m_vecOffset.y = atof(joint_data.access.szOffsetY);
				pJointArray[i].m_vecOffset.z = atof(joint_data.access.szOffsetZ);
				float x = atof(joint_data.access.szOrientX);
				float y = atof(joint_data.access.szOrientY);
				float z = atof(joint_data.access.szOrientZ);
				pJointArray[i].m_quaOrient = make_quat(x,y,z);
			}
			return true;
		}
		
		void ParseMesh(owBuffer * _pBuffer ,MeshFilePtr _pMesh,int _index)
		{
			MeshPtr pSubMesh = _pMesh->m_pMeshes + _index;
			char * pLine;
			// 获取纹理
			pLine = read_line(_pBuffer); assert(pLine);
			read_string_for_key(pLine,SHADER,&pSubMesh->m_szTexture[0]);
			// 获取顶点数
			pLine = read_line(_pBuffer); assert(pLine);
			read_value_for_key(pLine,NUM_VERTS,&pSubMesh->m_nNumVertices);
			pSubMesh->m_pVertices = new Vertex[pSubMesh->m_nNumVertices];
			// 解析所有顶点
			__vert_read_struct__ vert_struct;
			for(int i = 0;i<pSubMesh->m_nNumVertices;++i)
			{
				pLine = read_line(_pBuffer);
				char * pch;
				pch = strtok (pLine," \t()\n\r");
				int j = 0;
				while (pch != NULL && j < __vert_num_element__)
				{
					strcpy(&vert_struct.data[j][0],pch);
					pch = strtok (NULL, " \t()\n\r");
					++j;
				}
				pSubMesh->m_pVertices[i].m_addr_U = atof(vert_struct.access.szAddrU);
				pSubMesh->m_pVertices[i].m_addr_V = atof(vert_struct.access.szAddrV);
				pSubMesh->m_pVertices[i].m_nWeightStart = atoi(vert_struct.access.szWeightBeg);
				pSubMesh->m_pVertices[i].m_nWeightCount = atoi(vert_struct.access.szWeightCnt);
			}
			// 获取三角形数
			pLine = read_line(_pBuffer);
			read_value_for_key(pLine,NUM_TRIANGLES,&pSubMesh->m_nNumTriangles);
			pSubMesh->m_pTringles = new Triple<unsigned int>[pSubMesh->m_nNumTriangles];
			// 解析三角形
			__tri_read_struct__ tri_struct;
			for(int i = 0;i<pSubMesh->m_nNumTriangles;++i)
			{
				pLine = read_line(_pBuffer);
				char * pch;
				pch = strtok (pLine," \t()\n\r");
				int j = 0;
				while (pch != NULL && j < __tri_num_element__)
				{
					strcpy(&tri_struct.data[j][0],pch);
					pch = strtok (NULL, " \t()\n\r");
					++j;
				}
				pSubMesh->m_pTringles[i].a = atoi(tri_struct.access.szVertA);
				pSubMesh->m_pTringles[i].b = atoi(tri_struct.access.szVertB);
				pSubMesh->m_pTringles[i].c = atoi(tri_struct.access.szVertC);
			}
			// 获取weight数
			pLine = read_line(_pBuffer);
			read_value_for_key(pLine,NUM_WEIGHT,&pSubMesh->m_nNumWeights);
			pSubMesh->m_pWeights = new Weight[pSubMesh->m_nNumWeights];
			// 解析weight
			__weight_read_struct__ weight_struct;
			for(int i = 0;i<pSubMesh->m_nNumWeights;++i)
			{
				pLine = read_line(_pBuffer);
				char * pch;
				pch = strtok (pLine," \t()\n\r");
				int j = 0;
				while (pch != NULL && j < __weight_num_element__)
				{
					strcpy(&weight_struct.data[j][0],pch);
					pch = strtok (NULL, " \t()\n\r");
					++j;
				}
				int jointIndex = atoi(weight_struct.access.szJointIndex);
				pSubMesh->m_pWeights[i].m_nJointIndex = jointIndex;
				pSubMesh->m_pWeights[i].m_fBias = atof(weight_struct.access.szBias);
				pSubMesh->m_pWeights[i].m_vecPos.x = atof(weight_struct.access.szPosX);
				pSubMesh->m_pWeights[i].m_vecPos.y = atof(weight_struct.access.szPosY);
				pSubMesh->m_pWeights[i].m_vecPos.z = atof(weight_struct.access.szPosZ);
			}
			return;
		}
		
		void ParseHierarchy(owBuffer * _pBuffer,AnimFilePtr _pAnim)
		{
			char * pLine = NULL;
			__hierarchy_read_struct__ hierarchy_struct;
			for(int i = 0 ; i<_pAnim->m_nNumJoints; ++i)
			{
				pLine = read_line(_pBuffer);
				if(pLine == 0)
				{
					assert(pLine);
				}
				char * pch;
				pch = strtok (pLine," \t()\n\r");
				int j = 0;
				while (pch != NULL && j < __num_hierarchy_element__)
				{
					strcpy(&hierarchy_struct.data[j][0],pch);
					pch = strtok (NULL, " \t()\n\r");
					++j;
				}
				_pAnim->m_pJointMap[i].m_cEffectFlag = atoi(hierarchy_struct.access.szEffectFlag);
				_pAnim->m_pJointMap[i].m_nEffectStartIndex = atoi(hierarchy_struct.access.szEffectStartIndex);
			}
		}
		
		void ParseBounds(owBuffer * _pBuffer,AnimFilePtr _pAnim)
		{
			char * pLine = NULL;
			__bound_read_struct__ bound_struct;
			for(int i = 0 ; i<_pAnim->m_nNumJoints; ++i)
			{
				pLine = read_line(_pBuffer);
				assert(pLine);
				char * pch;
				pch = strtok (pLine," \t()\n\r");
				int j = 0;
				while (pch != NULL && j < __num_bounds_element__)
				{
					strcpy(&bound_struct.data[j][0],pch);
					pch = strtok (NULL, " \t()\n\r");
					++j;
				}
				_pAnim->m_pBounds[i].m_vecMin.x = atof(bound_struct.access.szVecMinX);
				_pAnim->m_pBounds[i].m_vecMin.y = atof(bound_struct.access.szVecMinY);
				_pAnim->m_pBounds[i].m_vecMin.z = atof(bound_struct.access.szVecMinZ);
				_pAnim->m_pBounds[i].m_vecMax.x = atof(bound_struct.access.szVecMaxX);
				_pAnim->m_pBounds[i].m_vecMax.y = atof(bound_struct.access.szVecMaxY);
				_pAnim->m_pBounds[i].m_vecMax.z = atof(bound_struct.access.szVecMaxZ);
			}
		}
		
		void ParseKeyFrame(owBuffer * _pBuffer,JointArray _pKeyFrame,int _nJoints)
		{
			char * pLine = NULL;
			__frame_read_struct__ frame_struct;
            JointPtr _pCurrJoint = NULL;
			for(int i = 0 ; i<_nJoints; ++i)
			{
                _pCurrJoint = &_pKeyFrame[i];
				pLine = read_line(_pBuffer);
				assert(pLine);
				char * pch;
				pch = strtok (pLine," \t()\n\r");
				int j = 0;
				while (pch != NULL && j < __num_frame_element__)
				{
					strcpy(&frame_struct.data[j][0],pch);
					pch = strtok (NULL, " \t()\n\r");
					++j;
				}
				_pCurrJoint->m_vecOffset.x = atof(frame_struct.access.szVecOffsetX);
				_pCurrJoint->m_vecOffset.y = atof(frame_struct.access.szVecOffsetY);
				_pCurrJoint->m_vecOffset.z = atof(frame_struct.access.szVecOffsetZ);
				float x,y,z;
				x = atof(frame_struct.access.szVecOrientX);
				y = atof(frame_struct.access.szVecOrientY);
				z = atof(frame_struct.access.szVecOrientZ);
				_pCurrJoint->m_quaOrient = make_quat(x,y,z);
			}
		}
		
		void ParseMD5( owBuffer * _pMeshBuff, owBuffer * _pAnimBuff ,MD5FilePtr _pMD5File)
		{
			_pMD5File->m_pAnimFile = new AnimFile();
			_pMD5File->m_pMeshFile = new MeshFile();
			
			MeshFilePtr _pMesh = _pMD5File->m_pMeshFile;
			AnimFilePtr _pAnim = _pMD5File->m_pAnimFile;
			
			// 先读取一行
			char * pLine = read_line(_pMeshBuff);
			int md5Version;
			int numJoints;
			int numMeshes;
			// 获取文件头信息
			while(!read_value_for_key(pLine,VERSION_INFO,&md5Version))
			{
				pLine = read_line(_pMeshBuff);
			}
			while(!read_value_for_key(pLine,NUM_JOINTS,&numJoints))
			{
				pLine = read_line(_pMeshBuff);
			}
			while(!read_value_for_key(pLine,NUM_MESHES,&numMeshes))
			{
				pLine = read_line(_pMeshBuff);
			}
			// 设置文件头内容
			_pMesh->m_nVersion = md5Version;
			_pMesh->m_nNumJoints = numJoints;
			_pMesh->m_pJointMap = new JointMap[numJoints];
			_pMesh->m_pJointArray = new Joint[numJoints];
			_pMesh->m_nNumMeshes = numMeshes;
			_pMesh->m_pMeshes = new Mesh[numMeshes];
			// 读取joints信息
			owBuffer * pBuffer = read_block_for_key(_pMeshBuff,JOINTS);
			// 解析joints数据
			ParseJoints(pBuffer,_pMesh);
			pBuffer->Release();
			// 读取mesh数据
			for(int i = 0;i<numMeshes;++i)
			{
				pBuffer = read_block_for_key(_pMeshBuff,MESH);
				ParseMesh(pBuffer,_pMesh,i);
				pBuffer->Release();
			}
			
			// 解析 anim 文件
			// 直接赋值，共用一个joint列表
			_pAnim->m_pJointMap = _pMesh->m_pJointMap;
			
			pLine = read_line(_pAnimBuff);
			while(!read_value_for_key(pLine,VERSION_INFO,&_pAnim->m_nVersion))
			{
				pLine = read_line(_pAnimBuff);
			}
			pLine = read_line(_pAnimBuff);
			while(!read_value_for_key(pLine,NUM_FRAMES,&_pAnim->m_nNumFrames))
			{
				pLine = read_line(_pAnimBuff);
			}
			pLine = read_line(_pAnimBuff);
			while(!read_value_for_key(pLine,NUM_JOINTS,&_pAnim->m_nNumJoints))
			{
				pLine = read_line(_pAnimBuff);
			}
			pLine = read_line(_pAnimBuff);
			while(!read_value_for_key(pLine,FRAME_RATE,&_pAnim->m_nNumFrameRate))
			{
				pLine = read_line(_pAnimBuff);
			}
			pLine = read_line(_pAnimBuff);
			while(!read_value_for_key(pLine,NUM_ANIM_COMPONENTS,&_pAnim->m_nNumAnimatedComponents))
			{
				pLine = read_line(_pAnimBuff);
			}
			_pAnim->m_pBounds = new Bound[_pAnim->m_nNumFrames];
			_pAnim->m_pBaseFrame = new Joint[_pAnim->m_nNumJoints];
			_pAnim->m_pKeyFrames = new JointPtr[_pAnim->m_nNumFrames];
			for(int i = 0;i<_pAnim->m_nNumFrames;++i)
			{
				_pAnim->m_pKeyFrames[i] = new Joint[_pAnim->m_nNumJoints];
			}
			
			pBuffer = read_block_for_key(_pAnimBuff,HIERARCHY);
			ParseHierarchy(pBuffer,_pAnim);
			pBuffer = read_block_for_key(_pAnimBuff,BOUNDS);
			ParseBounds(pBuffer,_pAnim);
			// base frame
			pBuffer = read_block_for_key(_pAnimBuff,BASEFRAME);
			ParseKeyFrame(pBuffer,_pAnim->m_pBaseFrame,_pAnim->m_nNumJoints);
			// key frames
			for(int i = 0;i<_pAnim->m_nNumFrames;++i)
			{
				pBuffer = read_block_for_key(_pAnimBuff,FRAME);
				ParseKeyFrame(pBuffer,_pAnim->m_pKeyFrames[i],_pAnim->m_nNumJoints);
			}
		}
		
		void ClearMesh( MeshFilePtr _pMesh)
		{
			delete []_pMesh->m_pJointMap;
			delete []_pMesh->m_pJointArray;
			for(int i = 0;i<_pMesh->m_nNumMeshes;++i)
			{
				delete []_pMesh->m_pMeshes[i].m_pVertices;
				delete []_pMesh->m_pMeshes[i].m_pTringles;
				delete []_pMesh->m_pMeshes[i].m_pWeights;
			}
			delete []_pMesh->m_pMeshes;
		}
		
		void ClearAnim(AnimFilePtr _pAnim)
		{  
			delete []_pAnim->m_pBounds;
			delete []_pAnim->m_pBaseFrame;
			for(int i = 0;i<_pAnim->m_nNumFrames;++i)
			{
				delete []_pAnim->m_pKeyFrames[i];
			}
			delete []_pAnim->m_pKeyFrames;
		}
		
		void ClearMD5( MD5FilePtr _pMD5File )
		{
			ClearMesh(_pMD5File->m_pMeshFile);
			ClearAnim(_pMD5File->m_pAnimFile);
			_pMD5File->m_pAnimFile = NULL;
			_pMD5File->m_pMeshFile = NULL;
		}
		
		owBuffer * GetIndexBuffer( MeshPtr _pMesh )
		{
			owBuffer* pRet = CreateMemBuffer(_pMesh->m_nNumTriangles * sizeof(Triple<unsigned int>));
			memcpy(pRet->GetBuffer(),&_pMesh->m_pTringles[0],pRet->Size());
			return pRet;
		}
		
		owBuffer * GetUVBuffer( MeshPtr _pMesh )
		{
			unsigned int nUVSize = _pMesh->m_nNumVertices * 2 * sizeof(float);
			owBuffer* pRet  = CreateMemBuffer(nUVSize);
			glm::vec2 * pVec = (glm::vec2*)pRet->GetBuffer();
			for(int i = 0;i<_pMesh->m_nNumVertices;++i)
			{
				pVec->x = _pMesh->m_pVertices[i].m_addr_U;
				pVec->y = _pMesh->m_pVertices[i].m_addr_V;
				++pVec;
			}
			return pRet;
		}
	}
}

