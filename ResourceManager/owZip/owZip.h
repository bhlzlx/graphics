#ifndef __OW_ZIP_H__
#define __OW_ZIP_H__

#include <owfile/owfile.h>
#include <zlib.h>

namespace ow
{
	typedef uint8_t byte;
	struct owZip
	{
		owZip();
		~owZip();
		
		owFile * Compress( owFile * _pFile , int32_t _nlevel );
		owFile * Uncompress( owFile * _pFile );
		
		// 辅助buffer
		IBuffer * m_pInputChunkBuffer;
		IBuffer * m_pOutputChunkBuffer;
		IBuffer * m_pTempBuffer;
	};

}

#endif // __OW_ZIP_H__
