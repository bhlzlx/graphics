#ifndef IBUFFER_H
#define IBUFFER_H

#include <stdint.h>

struct iBuffer
{
    virtual uint32_t GetLength()= 0;
    virtual uint8_t * GetCurr() = 0;
    virtual uint8_t * GetBuffer()= 0;
    virtual uint32_t Write(uint8_t * src,uint32_t size)= 0;
    virtual uint32_t Read(uint8_t * out,uint32_t size)= 0;
    virtual bool Seek(int pos,long offset)= 0;
	virtual bool Eof() = 0;

    virtual void Release() = 0;
};

typedef iBuffer *IBufferPtr;

iBuffer * CreateStandardBuffer(uint32_t);
iBuffer * BufferFromFile(const char * szFile);

iBuffer * CreateBufferRef( uint8_t * _pData, uint32_t _nLength);

#endif // IBUFFER_H
