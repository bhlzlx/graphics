#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <stack>
#include <string>
#include <queue>
#include <windows.h>
#include <algorithm>

namespace ow
{
	const static int32_t FILETYPE_FILE = 0x0;
	const static int32_t FILETYPE_DIR = 0x1;
	const static int32_t PATH_LENGTH_MAX = 127;
	const static int32_t MD5_VALUE_MAX = 32;
	
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
	};
	
	struct owFileTag
	{
		// 文件目录路径
		char 		m_szFilepath[PATH_LENGTH_MAX];
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
	};
	
	struct owNode
	{
		owNode*		m_pParent;
		
		int32_t		m_iFileType;
		
		std::string m_strNodeName;
		std::string m_strFullpath;
		std::vector<ow::owNode *>\
					m_vecChildren;
					
		void Sort()
		{
			std::sort( m_vecChildren.begin(), m_vecChildren.end() ,
			[](ow::owNode * i ,ow::owNode * j)
			{
				return i->m_iFileType > j->m_iFileType;
			}
			);
		}
					
		void Print( int _nAlignSpace)
		{
			for(int i = 0; i<_nAlignSpace; ++i)
			{
				printf("    ");
			}
			printf("%s \n", m_strFullpath.c_str());
			for( ow::owNode * pNode : m_vecChildren)
			{
				pNode->Print( _nAlignSpace + 1);
			}
		}
		
		void Release()
		{
			for( ow::owNode * pNode : m_vecChildren)
			{
				pNode->Release();
			}
			delete this;
		}
	};
	
	int32_t owSearchDir(const char * _szRoot, owNode * _pRootNode);
	
	bool owCreatePackage( ow::owNode* _pRootNode, const char * _szFilepath);
    
}