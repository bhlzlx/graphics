#include "buffer.h"
#include <cstdio>
#include <string.h>

struct MemBuffer:public IBuffer
{
	int8_t*		m_pData;
	int8_t*		m_pCurr;
	int8_t*		m_pEnd;
	
	int32_t		m_nCapacity;
	
	MemBuffer()
	{
		this->m_nCapacity = 0;
		this->m_pCurr = this->m_pData = this->m_pEnd = NULL;
	}
	
	MemBuffer( const int8_t* _pSrc, int32_t& _nSize)
	{
		m_pData = new int8_t[_nSize + 1];
		memcpy(m_pData, _pSrc, _nSize);
		m_pData[_nSize] = 0x00;
		m_pCurr = m_pData;
		m_pEnd = m_pData + _nSize + 1;
		m_nCapacity = _nSize;
	}
	
	MemBuffer( const int32_t& _nSize)
	{
		m_pData = new int8_t[_nSize + 1];
		m_pCurr = m_pData;
		m_pEnd = m_pData + _nSize + 1;
		m_nCapacity = _nSize;
	}
	
	int32_t Size()
	{
		return m_nCapacity;
	}
	
	void Seek( int8_t _flag, int32_t _offset)
	{
		switch(_flag)
        {
        case SEEK_SET:
            m_pCurr = m_pData + _offset;
            break;
        case SEEK_CUR:
            m_pCurr += _offset;
            break;
        case SEEK_END:
            m_pCurr = m_pEnd + _offset;
            break;
        }
		
        if((m_pEnd - m_pCurr) < 0)
		{
            m_pCurr = m_pEnd;
		}
        else if(m_pCurr < m_pData)
		{
            m_pCurr = m_pData;
		}
	}
	
	int32_t Read( int8_t* _pOut, uint32_t _nSize)
	{
		uint32_t sizeLeft = m_pEnd - m_pCurr;
        if(!sizeLeft)
		{
            return 0;
		}
        if(_nSize > sizeLeft)
		{
            _nSize = sizeLeft;
		}
        memcpy(_pOut,m_pCurr,_nSize);
        m_pCurr += _nSize;
        return _nSize;
	}
	
	int32_t Write( int8_t* _pIn, int32_t _nSize)
	{
		uint32_t sizeLeft = m_pEnd - m_pCurr;
        if(!sizeLeft)
		{
            return 0;
		}
        if(_nSize > sizeLeft)
		{
            _nSize = sizeLeft;
		}
        memcpy(m_pCurr, _pIn, _nSize);
        m_pCurr += _nSize;
        return _nSize;
	}
	
	bool Eof()
	{
		if(m_pCurr>=m_pEnd)
		{
			return true;
		}
		return false;
	}
	
	int8_t* GetCurr()
	{
		return m_pCurr;
	}
	
	int8_t* GetBuffer()
	{
		return m_pData;
	}

	void Release()
	{
		delete []m_pData;
		this->m_nCapacity = 0;
		this->m_pCurr = this->m_pData = this->m_pEnd = NULL;
		delete this;
	}
};

struct MemBufferRef:public MemBuffer
{
	MemBufferRef( int8_t* _pSrc, int32_t& _nSize)
	{
		m_pData = _pSrc;
		m_pCurr = m_pData;
		m_pEnd = m_pData + _nSize + 1;
		m_nCapacity = _nSize;
	}
	
	void Release()
	{
		delete this;
	}
};

IBuffer * CreateMemBuffer(int32_t _nSize)
{
    return new MemBuffer(_nSize);
}

IBuffer * BufferFromFile(const char * _szFile)
{
	FILE * file = fopen(_szFile,"rb");

    if(!file)
	{
        return NULL;
	}
    fseek(file,0,SEEK_END);
    long fileLen = ftell(file);
    fseek(file,0,SEEK_SET);
    MemBuffer * buffer = new MemBuffer(fileLen);
    fread(buffer->m_pData,1,fileLen,file);
    fclose(file);
    return buffer;
}

IBuffer * CreateBufferRef( int8_t * _pData, int32_t _nLength)
{
	return new MemBufferRef(_pData, _nLength);
}
