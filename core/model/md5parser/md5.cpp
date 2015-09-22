#include "md5.h"

#include <cstdlib>
#include <memory.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <cctype>

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

namespace model
{
	float calc_quat_w(float x, float y, float z)
	{
		float t = 1.0f - ( x * x ) - ( y * y ) - ( z * z );
		if ( t < 0.0f )
		{
			return 0.0f;
		}
		else
		{
			return -sqrtf(t);
		}
		return 0.0f;
	}
	
	void strrmv(char * _szStr, char * _szKeys)
	{
		int nKey = strlen(_szKeys);
		int displace = 0;
		unsigned i;
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
	
	void strrep(char * _szStr, char * _szKeys, char ch)
	{
		int nKey = strlen(_szKeys);
		unsigned i;
		for(i = 0;i<strlen(_szStr); ++i)
		{
			for(int j = 0;j<nKey;++j)
			{
				if(_szStr[i] == _szKeys[j])
				{
					_szStr[i] = ch;
				}
			}
		}
	}
	
	uint8_t isValidLine( char * _pLine, uint16_t _nLength)
	{
		for(int i = 0;i<_nLength;++i)
		{
			if( isprint(_pLine[i]) )
			{
				if(_pLine[i] == '/')
				{
					return 0;
				}
				else
				{
					return 1;
				}
			}
		}
		// all blank!
		return 0;
	}
	
	char * read_line(IBuffer * _pBuffer)
	{
		static char buffer[512];
		int length ;
again:
		length = 0;
		memset(buffer,0,512);
		while(true)
		{
			int ret = _pBuffer->Read( (int8_t*)buffer + length,1);
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
				if(!isValidLine(buffer,length))
				{
					goto again;
				}
				break;
			}
		}
		buffer[length] = 0;
		return buffer;
	}
	
	IBuffer * read_block_for_key(IBuffer * _pBuffer, const char * _key)
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
		
		IBuffer * pRet = CreateMemBuffer(pEnd - pContent);
		int n_read = _pBuffer->Read(pRet->GetBuffer(),pRet->Size() - 1);
		assert(n_read == (int32_t)pRet->Size() - 1);
		_pBuffer->Seek(SEEK_CUR,1L);
		return pRet;
	}
	
	void ParseMeshJoints( IBuffer * _pBlockBuff, md5MeshModel* _pMeshModel, uint32_t _nJoints)
	{
		char * pLine = NULL;
		md5Joint * pJoint;
		md5JointMapA * pJointMap;
		for(int jointIdx = 0;jointIdx < _nJoints; ++jointIdx)
		{
			pJoint = _pMeshModel->m_pJoints + jointIdx;
			pJointMap = _pMeshModel->m_pJointMap + jointIdx;
			pLine = read_line(_pBlockBuff);
			uint32_t ret = sscanf(
				pLine,
				"%s %d ( %f %f %f ) ( %f %f %f )",
				pJointMap->m_szName,
				&pJointMap->m_iParentIndex,
				&pJoint->m_vecOffset.x,
				&pJoint->m_vecOffset.y,
				&pJoint->m_vecOffset.z,
				&pJoint->m_quaOrient.x,
				&pJoint->m_quaOrient.y,
				&pJoint->m_quaOrient.z
			);
			pJoint->m_quaOrient.w = calc_quat_w( 
				pJoint->m_quaOrient.x,
				pJoint->m_quaOrient.y,
				pJoint->m_quaOrient.z
			);
			strrmv(pJointMap->m_szName,"\t\" ");
			assert(ret == 8);
		}
	}
	
	void ParseMesh(IBuffer * _pBlockBuff, md5Mesh * _pMesh)
	{
		// 取纹理
		uint32_t ret = 0;
		char * pLine = NULL;
		pLine = read_line(_pBlockBuff);
		ret = sscanf(pLine,
		"%*s %s",
		_pMesh->m_szTexture
		);
		strrmv(_pMesh->m_szTexture,"\"");
		// 取顶点数
		pLine = read_line(_pBlockBuff);
		ret = sscanf(pLine, "%*s %d",&_pMesh->m_nNumVertices);
		_pMesh->m_pVertices = new md5Vertex[_pMesh->m_nNumVertices];
		// 取顶点信息
		for(int vertIndex = 0;vertIndex<_pMesh->m_nNumVertices; ++vertIndex)
		{
			pLine = read_line(_pBlockBuff);
			ret = sscanf(pLine,
				"%*s %*d ( %f %f ) %d %d",
				&_pMesh->m_pVertices[vertIndex].m_addr_U,
				&_pMesh->m_pVertices[vertIndex].m_addr_V,
				&_pMesh->m_pVertices[vertIndex].m_nStart,
				&_pMesh->m_pVertices[vertIndex].m_nCount
				);
			assert(ret == 4);
		}
		// 取三角形数
		pLine = read_line(_pBlockBuff);
		sscanf(pLine,"%*s %d",&_pMesh->m_nNumTriangles);
		_pMesh->m_pTriangles = new ivector3[_pMesh->m_nNumTriangles];
		for(int triangleIndex = 0;triangleIndex<_pMesh->m_nNumTriangles;++triangleIndex)
		{
			pLine = read_line(_pBlockBuff);
			ret = sscanf(pLine,
				"%*s %*d %d %d %d",
				&_pMesh->m_pTriangles[triangleIndex].x,
				&_pMesh->m_pTriangles[triangleIndex].y,
				&_pMesh->m_pTriangles[triangleIndex].z
			);
			assert(ret == 3);
		}
		// 取weight
		pLine = read_line(_pBlockBuff);
		sscanf(pLine,"%*s %d",&_pMesh->m_nNumWeight);
		_pMesh->m_pWeights = new md5Weight[_pMesh->m_nNumWeight];
		for(int weightIndex = 0;weightIndex<_pMesh->m_nNumWeight; ++weightIndex)
		{
			pLine = read_line(_pBlockBuff);
			ret = sscanf(pLine,
				"%*s %*d %d %f ( %f %f %f )",
				&_pMesh->m_pWeights[weightIndex].m_iJointIndex,
				&_pMesh->m_pWeights[weightIndex].m_fBias,
				&_pMesh->m_pWeights[weightIndex].m_vecOffset.x,
				&_pMesh->m_pWeights[weightIndex].m_vecOffset.y,
				&_pMesh->m_pWeights[weightIndex].m_vecOffset.z
			);
			assert(ret == 5);
		}
	}
	
	void InitMeshModel(md5MeshModel * _pMeshModel, IBuffer * _pBuffer)
	{
		char * pLine = NULL;
		int16_t scan_ret = 0;
		// 读取基本数据
		while(scan_ret == 0) 
		{
			pLine = read_line(_pBuffer);
			scan_ret = sscanf(pLine,VERSION_INFO" %d",&_pMeshModel->m_iVersion);
		}
		scan_ret = 0;
		while(scan_ret == 0)
		{
			pLine = read_line(_pBuffer);
			scan_ret = sscanf(pLine,NUM_JOINTS" %d",&_pMeshModel->m_nNumJoints);
		}
		scan_ret = 0;
		while(scan_ret == 0)
		{
			pLine = read_line(_pBuffer);
			scan_ret = sscanf(pLine,NUM_MESHES" %d",&_pMeshModel->m_nNumMeshes);
		}
		// 分配必要的内存空间
		_pMeshModel->m_pJointMap = new md5JointMapA[_pMeshModel->m_nNumJoints];
		_pMeshModel->m_pJoints = new md5Joint[_pMeshModel->m_nNumJoints];
		_pMeshModel->m_pMeshes = new md5Mesh[_pMeshModel->m_nNumMeshes];
		IBuffer * blockBuff;
		// 读取 joint结构map 和 默认绑定的joint骨骼数据		
		blockBuff = read_block_for_key(_pBuffer,JOINTS);
		ParseMeshJoints(blockBuff,_pMeshModel,_pMeshModel->m_nNumJoints);
		// 读取mesh
		for(int meshIdx = 0;meshIdx < _pMeshModel->m_nNumMeshes; ++meshIdx)
		{
			blockBuff = read_block_for_key(_pBuffer,MESH);
			ParseMesh(blockBuff,_pMeshModel->m_pMeshes + meshIdx);
		}
		return ;
	}
	
	void ClearMeshModel(md5MeshModel * _pMeshModel)
	{
		delete []_pMeshModel->m_pJointMap;
		delete []_pMeshModel->m_pJoints;
		for(int meshIdx = 0;meshIdx < _pMeshModel->m_nNumMeshes;++meshIdx)
		{
			delete []_pMeshModel->m_pMeshes[meshIdx].m_pTriangles;
			delete []_pMeshModel->m_pMeshes[meshIdx].m_pVertices;
			delete []_pMeshModel->m_pMeshes[meshIdx].m_pWeights;
		}
	}
	
	void ParseAnimJoints(IBuffer * _pBuffer, md5AnimModel* _pAnimModel)
	{
		char * pLine = NULL;
		uint16_t scan_ret = 0;
		for(int jointIdx = 0; jointIdx < _pAnimModel->m_nNumJoints; ++jointIdx)
		{
			pLine = read_line(_pBuffer);
			scan_ret = sscanf(pLine,
				"%s %d %d %d",
				&_pAnimModel->m_pJointMap[jointIdx].m_szName,
				&_pAnimModel->m_pJointMap[jointIdx].m_iParentIndex,
				&_pAnimModel->m_pJointMap[jointIdx].m_cEffectFlag,
				&_pAnimModel->m_pJointMap[jointIdx].m_iEffectStart
			);
			strrmv(_pAnimModel->m_pJointMap[jointIdx].m_szName,"\"");
			assert(scan_ret == 4);
		}
	}
	
	void ParseAnimBounds(IBuffer * _pBuffer, md5AnimModel* _pAnimModel)
	{
		char * pLine = NULL;
		uint16_t scan_ret = 0;
		for(int boundIdx = 0;boundIdx < _pAnimModel->m_nNumFrames;++boundIdx)
		{
			pLine = read_line(_pBuffer);
			scan_ret = sscanf(pLine,
				"%*s %f %f %f %*s %*s %f %f %f",
				&_pAnimModel->m_pBounds[boundIdx].m_vecMin.x,
				&_pAnimModel->m_pBounds[boundIdx].m_vecMin.y,
				&_pAnimModel->m_pBounds[boundIdx].m_vecMin.z,
				&_pAnimModel->m_pBounds[boundIdx].m_vecMax.x,
				&_pAnimModel->m_pBounds[boundIdx].m_vecMax.y,
				&_pAnimModel->m_pBounds[boundIdx].m_vecMax.z
			);
			assert(scan_ret == 6);
		}
	}
	
	void ParseBaseFrame(IBuffer * _pBuffer, md5Joint * _pJoints, uint16_t _nBones)
	{
		char * pLine = NULL;
		uint16_t scan_ret = 0;
		for(int jointIdx = 0;jointIdx < _nBones;++jointIdx)
		{
			pLine = read_line(_pBuffer);
			scan_ret = sscanf(pLine,
				"%*s %f %f %f %*s %*s %f %f %f",
				&_pJoints[jointIdx].m_vecOffset.x,
				&_pJoints[jointIdx].m_vecOffset.y,
				&_pJoints[jointIdx].m_vecOffset.z,
				&_pJoints[jointIdx].m_quaOrient.x,
				&_pJoints[jointIdx].m_quaOrient.y,
				&_pJoints[jointIdx].m_quaOrient.z
			);
			_pJoints[jointIdx].m_quaOrient.w = calc_quat_w( 
				_pJoints[jointIdx].m_quaOrient.x,
				_pJoints[jointIdx].m_quaOrient.y,
				_pJoints[jointIdx].m_quaOrient.z
			);
			assert(scan_ret == 6);
		}
	}
	
	void ParseKeyFrame(IBuffer * _pBuffer, md5Joint * _pJoints, uint16_t _nBones)
	{
		char * pLine = NULL;
		uint16_t scan_ret = 0;
		float * pPtr = (float *)_pJoints;
		int32_t count = 0;
		for(int jointIdx = 0;jointIdx < _nBones;++jointIdx)
		{
			pLine = read_line(_pBuffer);
			// pLine 为空终止操作
			if(pLine == NULL)
			{
				return;
			}
			scan_ret = sscanf(pLine,
				"%f %f %f %f %f %f",
				pPtr,
				pPtr+1,
				pPtr+2,
				pPtr+3,
				pPtr+4,
				pPtr+5
			);
			pPtr+=scan_ret;
			// 返回数不是确定的~
			count += scan_ret;
		}
		printf("count : %d \n",count);
	}
	
	void InitAnimModel(md5AnimModel * _pAnimModel, IBuffer * _pBuffer)
	{
		char * pLine = NULL;
		uint16_t scan_ret = 0;
		// 读取基本数据
		while(scan_ret == 0) 
		{
			pLine = read_line(_pBuffer);
			scan_ret = sscanf(pLine,VERSION_INFO" %d",&_pAnimModel->m_iVersion);
		}
		scan_ret = 0;
		while(scan_ret == 0)
		{
			pLine = read_line(_pBuffer);
			scan_ret = sscanf(pLine,NUM_FRAMES" %d",&_pAnimModel->m_nNumFrames);
		}
		scan_ret = 0;
		while(scan_ret == 0)
		{
			pLine = read_line(_pBuffer);
			scan_ret = sscanf(pLine,NUM_JOINTS" %d",&_pAnimModel->m_nNumJoints);
		}
		scan_ret = 0;
		while(scan_ret == 0)
		{
			pLine = read_line(_pBuffer);
			scan_ret = sscanf(pLine,FRAME_RATE" %d",&_pAnimModel->m_iFrameRate);
		}
		scan_ret = 0;
		while(scan_ret == 0)
		{
			pLine = read_line(_pBuffer);
			scan_ret = sscanf(pLine,NUM_ANIM_COMPONENTS" %d",&_pAnimModel->m_nNumAnimateComponents);
		}
		// 分配空间
		_pAnimModel->m_pBaseFrame = new md5Joint[_pAnimModel->m_nNumJoints];
		_pAnimModel->m_pBounds = new md5Bound[_pAnimModel->m_nNumFrames];
		_pAnimModel->m_pKeyFrames = new md5Joint*[_pAnimModel->m_nNumFrames];
		// 所有的keyframes只分配一块数据
		md5Joint * pKeyFramesData = new md5Joint[ _pAnimModel->m_nNumJoints * _pAnimModel->m_nNumFrames];
		// 分配指针
		for(int frameIdx = 0;frameIdx < _pAnimModel->m_nNumFrames; ++frameIdx)
		{
			_pAnimModel->m_pKeyFrames[frameIdx] = pKeyFramesData + (frameIdx * _pAnimModel->m_nNumJoints);
		}
		_pAnimModel->m_pJointMap = new md5JointMapB[_pAnimModel->m_nNumJoints];
		// 读取joint map
		IBuffer * blockBuffer = read_block_for_key(_pBuffer,HIERARCHY);
		ParseAnimJoints(blockBuffer,_pAnimModel);
		// bound信息
		blockBuffer = read_block_for_key(_pBuffer,BOUNDS);
		ParseAnimBounds(blockBuffer,_pAnimModel);
		// base frame
		blockBuffer = read_block_for_key(_pBuffer,BASEFRAME);
		ParseBaseFrame(blockBuffer,_pAnimModel->m_pBaseFrame,_pAnimModel->m_nNumJoints);
		// key frames
		md5Joint * pTempJoints = new md5Joint[_pAnimModel->m_nNumJoints];
		for(int frameIdx = 0;frameIdx < _pAnimModel->m_nNumFrames; ++frameIdx)
		{
			blockBuffer = read_block_for_key(_pBuffer,FRAME);
			ParseKeyFrame(blockBuffer,pTempJoints,_pAnimModel->m_nNumJoints);
			// 复制base frame然后替换
			memcpy( _pAnimModel->m_pKeyFrames[frameIdx], _pAnimModel->m_pBaseFrame, sizeof(md5Joint) * _pAnimModel->m_nNumJoints );
			// 替换			
			float * pWritePtr = (float *)_pAnimModel->m_pKeyFrames[frameIdx];			
			for(int jointIndex = 0; jointIndex < _pAnimModel->m_nNumJoints; ++jointIndex)
			{
				float * pReadPtr = ((float *)pTempJoints) + _pAnimModel->m_pJointMap[jointIndex].m_iEffectStart;
				uint32_t replaceFlag = _pAnimModel->m_pJointMap[jointIndex].m_cEffectFlag;
				for(int bit = 0;bit<6;bit++)
				{
					if( 0x1<<bit & replaceFlag)
					{
						pWritePtr[bit] = *pReadPtr;
						pReadPtr++;
					}
				}
				pWritePtr+=7;
				// 计算四元数的w
				_pAnimModel->m_pKeyFrames[frameIdx][jointIndex].m_quaOrient.w = calc_quat_w(
					_pAnimModel->m_pKeyFrames[frameIdx][jointIndex].m_quaOrient.x,
					_pAnimModel->m_pKeyFrames[frameIdx][jointIndex].m_quaOrient.y,
					_pAnimModel->m_pKeyFrames[frameIdx][jointIndex].m_quaOrient.z
				);
				// 建立骨骼，累积四元数以及位移
				int parentJointIndex = _pAnimModel->m_pJointMap[jointIndex].m_iParentIndex;
				if(parentJointIndex >= 0 )
				{
					md5Joint * pJoint = &_pAnimModel->m_pKeyFrames[frameIdx][jointIndex];
					md5Joint * pParentJoint = &_pAnimModel->m_pKeyFrames[frameIdx][parentJointIndex];
					pJoint->m_vecOffset = pParentJoint->m_vecOffset + pParentJoint->m_quaOrient * pJoint->m_vecOffset;
					pJoint->m_quaOrient = pParentJoint->m_quaOrient * pJoint->m_quaOrient;
				}
			}
		}
		delete []pTempJoints;
	}
	
	void ClearAnimModel(md5AnimModel * _pAnimModel)
	{
		delete []_pAnimModel->m_pBaseFrame;
		delete []_pAnimModel->m_pBounds;
		delete []_pAnimModel->m_pJointMap;
		delete []_pAnimModel->m_pKeyFrames;
	}
	
	/*
	 * utils
	 * */
	 IBuffer * GetUVBuffer(md5Mesh * _pMesh)
	 {
		unsigned int nUVSize = _pMesh->m_nNumVertices * 2 * sizeof(float);
		IBuffer* pRet  = CreateMemBuffer(nUVSize);
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

