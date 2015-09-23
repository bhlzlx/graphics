#include "owfile.h"

namespace ow
{

	uint32_t owStdFile::Read( int8_t* _ptr, uint32_t _nBytes )
	{
		return fread( _ptr, 1, _nBytes, m_pFile);
	}

	uint32_t owStdFile::Write( int8_t* _ptr, uint32_t _nBytes )
	{
		return fwrite( _ptr, 1, _nBytes, m_pFile);
	}

	uint32_t owStdFile::Seek( int8_t _flag, int64_t _nOffset)
	{
		return fseek( m_pFile, _nOffset, _flag);
	}

	int64_t owStdFile::Tell() 
	{
		return ftell( m_pFile);
	}
	
	int32_t owStdFile::Size()
	{
		return m_iSize;
	}

	void owStdFile::Release()
	{
		fclose(m_pFile);
		delete this;
	}
	
	bool owStdFile::Eof()
	{
		return feof( m_pFile);
	}
	
	owFile * CreateStdFile( const char * _szFilepath, const char * _szFlag )
	{
		FILE * file = fopen( _szFilepath, _szFlag);
		if(file == NULL) return NULL;
		

		
		owStdFile * pStdFile = new owStdFile();
		
		fseek(file,0,SEEK_END);
		pStdFile->m_iSize = ftell( file);
		fseek(file,0,SEEK_SET);
		
		pStdFile->m_pFile = file;
		return pStdFile;
	}	
	
	uint32_t owMemFile::Read( int8_t* _ptr, uint32_t _nBytes )
	{
		return this->m_pMemBuffer->Read( _ptr, _nBytes);
	}
	
	uint32_t owMemFile::Write( int8_t* _ptr, uint32_t _nBytes )
	{
		return this->m_pMemBuffer->Write( _ptr, _nBytes);
	}
	
	uint32_t owMemFile::Seek( int8_t _flag, int64_t _nOffset)
	{
		m_pMemBuffer->Seek( _flag, _nOffset);
		return 0;
	}
	
	int64_t owMemFile::Tell()
	{
		return m_pMemBuffer->GetCurr() - m_pMemBuffer->GetBuffer();
	}
	
	int32_t owMemFile::Size()
	{
		return m_pMemBuffer->Size();
	}
	
	bool owMemFile::Eof()
	{
		return m_pMemBuffer->Eof();
	}
	
	void owMemFile::Release()
	{
		m_pMemBuffer->Release();
		delete this;
	}
	
	owFile * CreateMemFile( uint32_t _nSize )
	{
		owMemFile * pMemFile = new owMemFile();
		pMemFile->m_pMemBuffer = CreateMemBuffer( _nSize);
		return pMemFile;
	}


}

