#ifndef __PACKAGE_CMN_H__
#define __PACKAGE_CMN_H__

#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <stack>
#include <string>
#include <queue>
#include <windows.h>
#include <algorithm>
#include <owcmn/owcmn.h>

#define  FILETYPE_FILE  0x0
#define  FILETYPE_DIR  0x1
#define  PATH_LENGTH_MAX  127
#define  FILENAME_LENGTH_MAX  63
#define  MD5_VALUE_MAX  32

namespace ow
{
	struct owPackHeader
	{
		// 版本号
		uint32_t m_iVersion;
		// 正文开始偏移
		int32_t m_nContentOffset;
		// 文件数量
		int32_t m_nFileTags;
		// 空文件数量
		int32_t m_nEmptyFileTags;
	} __attribute__((aligned(4)));

	struct owFileTag
	{
	    // 文件目录路径
	    char 		m_szFileName[FILENAME_LENGTH_MAX + 1];
	    // 是文件还是目录
	    int32_t		m_iFileType;
	    //  在文件中的偏移
	    int32_t 	m_nDataOffset;
	    // 资源包中的大小，如果是目录代表目录里占用大小
	    int32_t 	m_nBytes;
	    // 压缩前大小（目录这一项是0）
	    int32_t 	m_nOrigBytes;
	    // md5较验码 byte[32], 以数据形式存储，使用memcmp比较
	    int8_t		m_md5[32];
	} __attribute__((aligned(4)));

	struct owNodeW
	{
		owNodeW*		m_pParent;
		int32_t 		m_iIndexId;
		int32_t			m_iFileType;
		std::string 	m_strNodeName;
		std::string 	m_strFullpath;
		
		std::vector<ow::owNodeW *>\
						m_vecChildren;
		void Sort();

		void Print( int _nAlignSpace);

		void Release();
	};

	struct owNodeR
	{
		owINT32			m_iNodeID;
		owINT32*		m_pChildrenNodes;
	};

	int32_t owSearchDir(const char * _szRoot, owNodeW * _pRootNode);
	owBOOL owCreatePackage( ow::owNodeW* _pRootNode, owINT32 _nNodeNum, const owCHAR * _szFilepath);

}

#endif