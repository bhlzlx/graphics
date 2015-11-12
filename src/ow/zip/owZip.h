#ifndef __OW_ZIP_H__
#define __OW_ZIP_H__

#include <file/owfile.h>
#include <zlib.h>

namespace ow
{
	typedef uint8_t byte;
	struct owZip
	{
		owZip();
		~owZip();
		// return a owFileObject for owFileType
		owFile * Compress( owFile * _pFile , int32_t _nlevel );
		// return a IBuffer Ref type, without memory copy
		owBuffer * RefCompress(owFile * _pFile, int32_t _nLevel);
		owFile * Uncompress( owFile * _pFile );

		// 辅助buffer
		owBuffer * m_pInputChunkBuffer;
		owBuffer * m_pOutputChunkBuffer;
		owBuffer * m_pTempBuffer;
	};

}

#endif // __OW_ZIP_H__
