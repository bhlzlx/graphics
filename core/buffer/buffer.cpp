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
//
//struct StdBuffer:public IBuffer
//{
//    uint8_t * m_pData;
//    uint8_t * m_pCurr;
//    uint8_t * m_pEnd;
//    uint32_t m_iCapacity;
//
//    StdBuffer(const uint8_t * src,uint32_t size)
//       
//    {
//        m_pData = new uint8_t[size + 1];
//        m_pCurr = m_pData;
//        memcpy(m_pData,src,size);
//        m_iCapacity = size;
//        m_pEnd = m_pData + size;
//        m_pData[size] = 0;
//    }
//
//    StdBuffer(uint32_t capacity
//              )
//    {
//        m_pData = new uint8_t[capacity + 1];
//        m_iCapacity = capacity;
//        m_pEnd = m_pData + m_iCapacity;
//        m_pCurr = m_pData;
//        m_pData[capacity] = 0;
//    }
//
//    uint32_t Write(uint8_t * src,uint32_t size)
//    {
//        uint32_t sizeLeft = m_iCapacity - (m_pCurr - m_pData);
//        if(!sizeLeft)
//            return 0;
//        if(size > sizeLeft)
//            size = sizeLeft;
//        memcpy(m_pCurr,src,size);
//        m_pCurr += size;
//        return size;
//    }
//    
//    uint8_t * GetCurr()
//    {
//        return m_pCurr;
//    }
//
//    uint32_t Read(uint8_t * out,uint32_t size)
//    {
//        uint32_t sizeLeft = m_iCapacity - (m_pCurr - m_pData);
//        if(!sizeLeft)
//            return 0;
//        if(size > sizeLeft)
//            size = sizeLeft;
//        memcpy(out,m_pCurr,size);
//        m_pCurr += size;
//        return size;
//    }
//
//    bool Seek(int pos,long offset)
//    {
//        switch(pos)
//        {
//        case SEEK_SET:
//            m_pCurr = m_pData + offset;
//            break;
//        case SEEK_CUR:
//            m_pCurr += offset;
//            break;
//        case SEEK_END:
//            m_pCurr = m_pEnd + offset;
//            break;
//        }
//        if((m_pEnd - m_pCurr) < 0)
//            m_pCurr = m_pEnd;
//        else if(m_pCurr < m_pData)
//            m_pCurr = m_pData;
//
//		return true;
//    }
//
//    uint32_t GetLength()
//    {
//        return m_iCapacity;
//    }
//
//    uint8_t * GetBuffer()
//    {
//        return m_pData;
//    }
//
//    void Release()
//    {
//        m_iCapacity = 0;
//        if(m_pData)
//            delete []m_pData;
//        m_pData = NULL;
//        m_pCurr = NULL;
//        m_pEnd = NULL;
//    }
//	
//	virtual bool Eof()
//	{
//		return m_pCurr >= m_pEnd;
//	}
//};
//
//struct BufferRef :public IBuffer
//{
//	uint8_t * m_pData;
//    uint8_t * m_pCurr;
//    uint8_t * m_pEnd;
//    uint32_t m_iCapacity;
//
//    BufferRef(uint8_t * src,uint32_t size)
//       
//    {
//        m_pData = src;
//        m_pCurr = m_pData;
//        m_iCapacity = size;
//        m_pEnd = m_pData + size;
//    }
//
//    uint32_t Write(uint8_t * src,uint32_t size)
//    {
//        uint32_t sizeLeft = m_iCapacity - (m_pCurr - m_pData);
//        if(!sizeLeft)
//            return 0;
//        if(size > sizeLeft)
//            size = sizeLeft;
//        memcpy(m_pCurr,src,size);
//        m_pCurr += size;
//        return size;
//    }
//    
//    uint8_t * GetCurr()
//    {
//        return m_pCurr;
//    }
//
//    uint32_t Read(uint8_t * out,uint32_t size)
//    {
//        uint32_t sizeLeft = m_iCapacity - (m_pCurr - m_pData);
//        if(!sizeLeft)
//            return 0;
//        if(size > sizeLeft)
//            size = sizeLeft;
//        memcpy(out,m_pCurr,size);
//        m_pCurr += size;
//        return size;
//    }
//
//    bool Seek(int pos,long offset)
//    {
//        switch(pos)
//        {
//        case SEEK_SET:
//            m_pCurr = m_pData + offset;
//            break;
//        case SEEK_CUR:
//            m_pCurr += offset;
//            break;
//        case SEEK_END:
//            m_pCurr = m_pEnd + offset;
//            break;
//        }
//        if((m_pEnd - m_pCurr) < 0)
//            m_pCurr = m_pEnd;
//        else if(m_pCurr < m_pData)
//            m_pCurr = m_pData;
//
//		return true;
//    }
//
//    uint32_t GetLength()
//    {
//        return m_iCapacity;
//    }
//
//    uint8_t * GetBuffer()
//    {
//        return m_pData;
//    }
//
//    void Release()
//    {
//		delete this;
//    }
//	
//	virtual bool Eof()
//	{
//		return m_pCurr >= m_pEnd;
//	}
//};

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
