#include "owZip.h"
#include <assert.h>
#include <memory.h>

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
		m_pOutputChunkBuffer->Release();
		m_pInputChunkBuffer->Release();
		m_pTempBuffer->Release();
	}
	
	IBuffer * owZip::RefCompress(owFile * _pFile, int32_t _nLevel)
	{
		_pFile->Seek( SEEK_SET, 0);
		if(_pFile->Eof())
		{
			return NULL;
		}
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
		retCode = deflateInit( &stream, _nLevel);
		
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
		
		
		if(dataSize == 0)
		{
			return NULL;
		}
		else
		{
			IBuffer * pRet = CreateBufferRef( m_pTempBuffer->GetBuffer(), dataSize);
			return pRet;
		}
		return NULL;
	}
	
	owFile * owZip::Compress( owFile * _pFile , int32_t _nlevel)
	{
		_pFile->Seek( SEEK_SET, 0);
		if(_pFile->Eof())
		{
			return NULL;
		}
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
		int retCode;
		z_stream stream;
		_pFile->Seek(SEEK_SET, 0);
		memset(&stream, 0, sizeof(stream));
		
		retCode = inflateInit( &stream);
		
		if(retCode != Z_OK || _pFile->Eof())
		{
			return NULL;
		}
		
		m_pTempBuffer->Seek( SEEK_SET, 0);
		
		while( true )
		{
			stream.avail_in = _pFile->Read( m_pInputChunkBuffer->GetBuffer(), m_pInputChunkBuffer->Size());
			stream.next_in = (Bytef* )m_pInputChunkBuffer->GetBuffer();
			while(stream.avail_in != 0)
			{
				stream.avail_out = m_pOutputChunkBuffer->Size();
				stream.next_out = (Bytef*)m_pOutputChunkBuffer->GetBuffer();
				
				retCode = inflate(&stream, Z_NO_FLUSH);
				
				switch (retCode) 
				{
					case Z_ERRNO:
						if (ferror(stdin))
							fputs("error reading stdin\n", stderr);
						if (ferror(stdout))
							fputs("error writing stdout\n", stderr);
						break;
					case Z_STREAM_ERROR:
						fputs("invalid compression level\n", stderr);
						break;
					case Z_DATA_ERROR:
						fputs("invalid or incomplete deflate data\n", stderr);
						break;
					case Z_MEM_ERROR:
						fputs("out of memory\n", stderr);
						break;
					case Z_VERSION_ERROR:
						fputs("zlib version mismatch!\n", stderr);
				}
				assert( retCode != Z_STREAM_ERROR);
				//switch(ret)				
				int32_t chunkSize = m_pOutputChunkBuffer->Size() - stream.avail_out;
				m_pTempBuffer->Write( m_pOutputChunkBuffer->GetBuffer(), chunkSize);
			}
			if(retCode == Z_STREAM_END)
			{
				break;
			}
		}
		int32_t dataSize = m_pTempBuffer->GetCurr() - m_pTempBuffer->GetBuffer();
		if(dataSize == 0)
		{
			return NULL;
		}
		else
		{
			owFile * pFile = CreateMemFile( dataSize );
			pFile->Write( m_pTempBuffer->GetBuffer(), dataSize);
			return pFile;
		}
		return NULL;
	}


}

