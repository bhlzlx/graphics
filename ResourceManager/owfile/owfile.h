#ifndef __OW_FILE_H__
#define __OW_FILE_H__

#include <stdint.h>
#include <stdio.h>
#include <buffer/buffer.h>

namespace ow
{

	struct owFile
	{
		virtual uint32_t Read( int8_t* _ptr, uint32_t _nBytes ) = 0;
		virtual uint32_t Write( int8_t* _ptr, uint32_t _nBytes ) = 0;
		virtual uint32_t Seek( int8_t _flag, int64_t _nOffset) = 0;
		virtual int64_t  Tell() = 0;
		virtual int32_t  Size() = 0;
		virtual bool	 Eof() = 0;
		virtual void Release() = 0;
	};
	
	struct owStdFile:public owFile
	{
		FILE * m_pFile;
		int32_t m_iSize;
		
		uint32_t Read( int8_t* _ptr, uint32_t _nBytes );
		uint32_t Write( int8_t* _ptr, uint32_t _nBytes );
		uint32_t Seek( int8_t _flag, int64_t _nOffset);
		int64_t  Tell();
		int32_t  Size();
		bool Eof();
		void Release();
	};
	
	owFile * CreateStdFile( const char * _szFilepath, const char * _szFlag );
	
	struct owMemFile:public owFile
	{
		IBuffer * 		m_pMemBuffer;
		
		uint32_t Read( int8_t* _ptr, uint32_t _nBytes );
		uint32_t Write( int8_t* _ptr, uint32_t _nBytes );
		uint32_t Seek( int8_t _flag, int64_t _nOffset);
		int64_t Tell();
		int32_t  Size() ;
		void Release();
		bool Eof();
	};
	
	owFile * CreateMemFile( uint32_t _nSize );

}

#endif // __OW_FILE_H__
