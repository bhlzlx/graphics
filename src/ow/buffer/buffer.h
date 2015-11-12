#ifndef __OW_BUFFER_H__
#define __OW_BUFFER_H__

#include <cmn/owcmn.h>

namespace ow
{
	struct owBuffer
	{
		virtual owSIZE_T 	Size() = 0;
		virtual owINT32		Seek( owINT8 _flag, owINT32 _offset) = 0;
		virtual owINT32		Read( owVOID* _pOut, owINT32 _nSize) = 0;
		virtual owINT32		Write( const owVOID* _pIn, owINT32 _nSize) = 0;
		/* return 0 if success, or return -1 if failed */
		virtual owINT32 	Resize( owINT32 _nSize) = 0;
		virtual owBOOL 		Eof() = 0;
		virtual owBYTE* 	GetCurr() = 0;
		virtual owBYTE* 	GetBuffer() = 0;
		virtual owVOID 		Release() = 0;
		virtual ~owBuffer(){};
	};

	struct owBufferRef
	{
		// 指针
		owBYTE*		m_pData;
		owBYTE*		m_pCurr;
		owBYTE*		m_pEnd;
		// 容量
		owSIZE_T	m_nCapacity;

		owBufferRef( owVOID * _pSrc, owINT32 & _nSize);
		owSIZE_T Size();
		owINT32 Seek( owINT8 _flag, owINT32 _offset);
		owINT32 Read( owVOID* _pOut, owINT32 _nSize);
		owINT32 Write( owVOID* _pIn, owINT32 _nSize);
		owBOOL Eof();

		owBYTE* GetCurr();
		owBYTE* GetBuffer();
		owVOID Release();
		~owBufferRef();
	};

	owBuffer * CreateMemBuffer( owINT32 );
	owBuffer * CreateFileBuffer( const owCHAR * szFile);
	owBuffer * CreateBufferRef( owVOID * _pData, owINT32 _nLength);
	owBufferRef CreateBufferRef2( owVOID * _pData, owINT32 _nLength);
}



#endif // __OW_BUFFER_H__
