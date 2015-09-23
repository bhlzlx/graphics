#include "owZip.h"
#include <assert.h>

namespace ow
{

	/*
       CHUNK is simply the buffer size for feeding data to and pulling data from the zlib routines. 
	   Larger buffer sizes would be more efficient, especially for inflate(). 
	   If the memory is available, buffers sizes on the order of 128K or 256K bytes should be used.
	*/
	const int32_t CHUNK_SIZE = 256 * 1024; // 256K
	const int32_t MINIMUM_BUFFER_SIZE = 512 * 1024; // 512KB
	
	owZip::owZip()
	{
		this->m_pOutputChunkBuffer = CreateMemBuffer( CHUNK_SIZE );
		this->m_pInputChunkBuffer = CreateMemBuffer( CHUNK_SIZE );
		this->m_pTempBuffer = CreateMemBuffer( MINIMUM_BUFFER_SIZE );
	}

	owZip::~owZip()
	{
		
	}
	
	owFile * owZip::Compress( owFile * _pFile , int32_t _nlevel)
	{
		// 保证有充足的压缩空间
		if(_pFile->Size() > m_pTempBuffer->Size())
		{
			m_pTempBuffer->Resize( _pFile->Size());
		}
		m_pTempBuffer->Seek( SEEK_SET, 0);
		
		int retCode;
		int flush;
		
		z_stream stream;
		
		stream.zalloc = Z_NULL;
		stream.zfree = Z_NULL;
		stream.opaque = Z_NULL;
		retCode = deflateInit( &stream, _nlevel);
		
		while( true )
		{
			stream.avail_in = _pFile->Read( m_pInputChunkBuffer->GetBuffer(), m_pInputChunkBuffer->Size() );
			stream.next_in = (Bytef*)m_pInputChunkBuffer->GetBuffer();
			flush = _pFile->Eof()?Z_FINISH : Z_NO_FLUSH;
			while( stream.avail_in != 0 )
			{
				stream.avail_out = (uint32_t)m_pOutputChunkBuffer->Size();
				stream.next_out = (Bytef*)m_pOutputChunkBuffer->GetBuffer();
				retCode = deflate( &stream, flush);
				assert(retCode != Z_STREAM_ERROR);
				
				int32_t chunkSize = m_pOutputChunkBuffer->Size() - stream.avail_out;
				// m_pTempBuffer 大小会自动增长
				m_pTempBuffer->Write( m_pOutputChunkBuffer->GetBuffer(), chunkSize);
			}
			
			assert(stream.avail_in == 0);
			if(flush == Z_FINISH)
			{
				break;
			}
		}
		
		int32_t dataSize = m_pTempBuffer->GetCurr() - m_pTempBuffer->GetBuffer();
		
		owFile * file = CreateMemFile( dataSize);
		file->Write( m_pTempBuffer->GetBuffer(), dataSize);
		return file;
	}
	
	owFile * owZip::Uncompress( owFile * _pFile )
	{
		return NULL;
	}


}

