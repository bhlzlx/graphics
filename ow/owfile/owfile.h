#ifndef __OW_FILE_H__
#define __OW_FILE_H__

#include <owcmn/owcmn.h>
#include <stdio.h>
#include <buffer/buffer.h>

namespace ow
{

	struct owFile
	{
		virtual owSIZE_T Read( owVOID* _ptr, owINT32 _nBytes ) = 0;
		virtual owSIZE_T Write( owVOID* _ptr, owINT32 _nBytes ) = 0;
		virtual owINT32  Seek( owINT32 _flag, owINT32 _nOffset) = 0;
		virtual owSIZE_T Tell() = 0;
		virtual owSIZE_T Size() = 0;
		virtual owBOOL	 Eof() = 0;
		virtual owVOID Release() = 0;
		virtual ~owFile(){};
	};
	
	struct owStdFile:public owFile
	{
		FILE* 		m_pFile;
		owSIZE_T 	m_iSize;
		
		owSIZE_T Read( owVOID* _ptr, owINT32 _nBytes );
		owSIZE_T Write( owVOID* _ptr, owINT32 _nBytes );
		owINT32  Seek( owINT32 _flag, owINT32 _nOffset);
		owSIZE_T Tell();
		owSIZE_T Size();
		owBOOL	 Eof();
		owVOID Release();
		
		~owStdFile();
	};
	
	owFile * CreateStdFile( const char * _szFilepath, const char * _szFlag );
	
	struct owMemFile:public owFile
	{
		owBuffer * 		m_pMemBuffer;
		
		owSIZE_T Read( owVOID* _ptr, owINT32 _nBytes );
		owSIZE_T Write( owVOID* _ptr, owINT32 _nBytes );
		owINT32  Seek( owINT32 _flag, owINT32 _nOffset);
		owSIZE_T Tell();
		owSIZE_T Size();
		owBOOL	 Eof();
		owVOID Release();
		
		~owMemFile();
	};
	
	owFile * CreateMemFile( owINT32 _nSize );

}

#endif // __OW_FILE_H__
