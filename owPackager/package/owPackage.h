#ifndef __OW_PACKAGE_H__
#define __OW_PACKAGE_H__

#include <stdint.h>

static const char VERSION[] = "OWPK"

namespace ow
{
	const static int32_t FILETYPE_FILE = 0x0;
	const static int32_t FILETYPE_DIR = 0x1;
	const static int32_t PATH_LENGTH_MAX = 127;
	const static int32_t MD5_VALUE_MAX = 32;
	
	struct owPackHeader
	{
		int32_t m_iVersion;
		int32_t m_nOffsetContent;
		int32_t m_nFileTags;
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

	class owPackage
	{
	public:
		owPackage();
		~owPackage();

	};

}

#endif // __OW_PACKAGE_H__
