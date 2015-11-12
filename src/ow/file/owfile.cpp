#include "owfile.h"

namespace ow
{

	owSIZE_T owStdFile::Read( owVOID* _ptr, owINT32 _nBytes )
	{
		return fread( _ptr, 1, _nBytes, m_pFile);
	}

	owSIZE_T owStdFile::Write( owVOID* _ptr, owINT32 _nBytes )
	{
		return fwrite( _ptr, 1, _nBytes, m_pFile);
	}

	owINT32 owStdFile::Seek( owINT32 _flag, owINT32 _nOffset)
	{
		return fseek( m_pFile, _nOffset, _flag);
	}

	owSIZE_T owStdFile::Tell() 
	{
		return ftell(m_pFile);
	}
	
	owSIZE_T owStdFile::Size()
	{
		return m_iSize;
	}

	void owStdFile::Release()
	{
		fclose(m_pFile);
		delete this;
	}
	
	owBOOL owStdFile::Eof()
	{
		return feof( m_pFile);
	}
	
	owBuffer * owStdFile::GetBuffer()
	{
		return this->m_pMemBuffer;
	}
	
	owStdFile::~owStdFile()
	{
		fclose(m_pFile);
		m_pMemBuffer->Release();
	}
	
	owFile * CreateStdFile( const owCHAR * _szFilepath, const owCHAR * _szFlag )
	{
		FILE * file = fopen( _szFilepath, _szFlag);
		if(file == NULL) return NULL;
		
		owStdFile * pStdFile = new owStdFile();
		
		fseek(file,0,SEEK_END);
		pStdFile->m_iSize = ftell( file);
		fseek(file,0,SEEK_SET);
		
		pStdFile->m_pFile = file;
		pStdFile->m_pMemBuffer= CreateMemBuffer( pStdFile->m_iSize);
		long pos = ftell(pStdFile->m_pFile);
		fseek(pStdFile->m_pFile, 0, SEEK_SET);
		fread(pStdFile->m_pMemBuffer->GetBuffer(), 1, pStdFile->m_iSize, pStdFile->m_pFile);
		fseek(pStdFile->m_pFile, 0, SEEK_SET);
		return pStdFile;
	}	
	
	owSIZE_T owMemFile::Read( owVOID* _ptr, owINT32 _nBytes )
	{
		return this->m_pMemBuffer->Read( _ptr, _nBytes);
	}
	
	owSIZE_T owMemFile::Write( owVOID* _ptr, owINT32 _nBytes )
	{
		return this->m_pMemBuffer->Write( _ptr, _nBytes);
	}
	
	owINT32 owMemFile::Seek( owINT32 _flag, owINT32 _nOffset)
	{
		m_pMemBuffer->Seek( _flag, _nOffset);
		return 0;
	}
	
	owSIZE_T owMemFile::Tell()
	{
		return m_pMemBuffer->GetCurr() - m_pMemBuffer->GetBuffer();
	}
	
	owSIZE_T owMemFile::Size()
	{
		return m_pMemBuffer->Size();
	}
	
	owBOOL owMemFile::Eof()
	{
		return m_pMemBuffer->Eof();
	}
	
	owVOID owMemFile::Release()
	{
		m_pMemBuffer->Release();
		delete this;
	}
	
	owFile * CreateMemFile( owINT32 _nSize )
	{
		owMemFile * pMemFile = new owMemFile();
		pMemFile->m_pMemBuffer = CreateMemBuffer( _nSize);
		return pMemFile;
	}
	
	owBuffer *owMemFile::GetBuffer()
	{
		return this->m_pMemBuffer;
	}
	
	owMemFile::~owMemFile()
	{
		
	}

}

