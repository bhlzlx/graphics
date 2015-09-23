#ifndef IBuffer_H
#define IBuffer_H

#include <stdint.h>

struct IBuffer
{
	virtual int32_t 	Size() = 0;
	virtual void 		Seek( int8_t _flag, int32_t _offset) = 0;
	virtual int32_t		Read( int8_t* _pOut, uint32_t _nSize) = 0;
	virtual int32_t		Write( int8_t* _pIn, int32_t _nSize) = 0;
	virtual bool 		Eof() = 0;
	
	virtual int8_t* 	GetCurr() = 0;
	virtual int8_t* 	GetBuffer() = 0;
	
	virtual void 		Release() = 0;
};

IBuffer * CreateMemBuffer(int32_t);
IBuffer * BufferFromFile(const char * szFile);
IBuffer * CreateBufferRef( int8_t * _pData, int32_t _nLength);

#endif // IBuffer_H
