#include "buffer.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <assert.h>

namespace ow
{
	MemBuffer::MemBuffer()
	{
		this->m_nCapacity = 0;
		this->m_pCurr = this->m_pData = this->m_pEnd = NULL;
	}
	
	MemBuffer::MemBuffer( const owVOID * _pSrc, owINT32 & _nSize)
	{
		m_pData = (owBYTE *)malloc( _nSize + 1);
		memcpy(m_pData, _pSrc, _nSize);
		m_pData[_nSize] = 0x00;
		m_pCurr = m_pData;
		m_pEnd = m_pData + _nSize;
		m_nCapacity = _nSize;
	}
	
	MemBuffer::MemBuffer( const owINT32& _nSize)
	{
		m_pData = (owBYTE *)malloc( _nSize + 1);
		m_pCurr = m_pData;
		m_pEnd = m_pData + _nSize;
		m_nCapacity = _nSize;
	}
	
	owSIZE_T MemBuffer::Size()
	{
		return m_nCapacity;
	}
	
	owINT32 MemBuffer::Seek( owINT8 _flag, owINT32 _offset)
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
		
		return 1;
	}
	
	owINT32 MemBuffer::Read( owVOID* _pOut, owINT32 _nSize)
	{
		owINT32 sizeLeft = m_pEnd - m_pCurr;
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
	
	owINT32 MemBuffer::Resize( owINT32 _nSize)
	{
		assert( static_cast<owSIZE_T>(_nSize) > this->m_nCapacity);
		owINT32 currOffset = m_pCurr - m_pData;
		this->m_pData = (owBYTE *)realloc( m_pData, _nSize + 1);
		assert( m_pData );
		
		m_pData[_nSize] = 0x0;
		m_nCapacity = _nSize;
		m_pCurr = m_pData + currOffset;
		m_pEnd = m_pData + _nSize;
		
		return 0;
	}
	
	owINT32 MemBuffer::Write( const owVOID* _pIn, owINT32 _nSize)
	{
		owINT32 sizeLeft = m_pEnd - m_pCurr;
		while(sizeLeft < _nSize)
		{
			Resize( m_nCapacity * 2);
			sizeLeft = m_pEnd - m_pCurr;
		}
		memcpy(m_pCurr, _pIn, _nSize);
		m_pCurr += _nSize;
		return _nSize;
	}
	
	owBOOL MemBuffer::Eof()
	{
		if(m_pCurr>=m_pEnd)
		{
			return true;
		}
		return false;
	}
	
	owBYTE* MemBuffer::GetCurr()
	{
		return m_pCurr;
	}
	
	owBYTE* MemBuffer::GetBuffer()
	{
		return m_pData;
	}

	owVOID MemBuffer::Release()
	{
		free( m_pData);
		this->m_nCapacity = 0;
		this->m_pCurr = this->m_pData = this->m_pEnd = NULL;
		delete this;
	}
	
	MemBuffer::~MemBuffer()
	{
		return ;
	}
	
		owBufferRef::owBufferRef( owVOID * _pSrc, owINT32 & _nSize)
		{
			m_pData = static_cast<owBYTE*>(_pSrc);
			m_pCurr = m_pData;
			m_pEnd = m_pData + _nSize;
			m_nCapacity = _nSize;
		}
		
		owSIZE_T owBufferRef::Size()
		{
			return m_nCapacity;
		}
		
		owINT32 owBufferRef::Seek( owINT8 _flag, owINT32 _offset)
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
			
			return 1;
		}
		
		owINT32 owBufferRef::Read( owVOID* _pOut, owINT32 _nSize)
		{
			owINT32 sizeLeft = m_pEnd - m_pCurr;
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
		
		owINT32 owBufferRef::Write( owVOID* _pIn, owINT32 _nSize)
		{
			owINT32 sizeLeft = m_pEnd - m_pCurr;
			if(sizeLeft < _nSize)
			{
				memcpy(m_pCurr, _pIn, sizeLeft);
				return sizeLeft;
			}
			memcpy(m_pCurr, _pIn, _nSize);
			m_pCurr += _nSize;
			return _nSize;
		}
		
		owBOOL owBufferRef::Eof()
		{
			if(m_pCurr>=m_pEnd)
			{
				return true;
			}
			return false;
		}
		
		owBYTE* owBufferRef::GetCurr()
		{
			return m_pCurr;
		}
		
		owBYTE* owBufferRef::GetBuffer()
		{
			return m_pData;
		}

		owVOID owBufferRef::Release()
		{
			delete this;
		}
		
		owBufferRef::~owBufferRef()
		{
			return ;
		}

	struct MemBufferRef:public MemBuffer
	{
		MemBufferRef( owVOID* _pSrc, owINT32& _nSize)
		{
			m_pData = (owBYTE*)_pSrc;
			m_pCurr = m_pData;
			m_pEnd = m_pData + _nSize;
			m_nCapacity = _nSize;
		}
		
		owINT32 Resize( owINT32 _nSize)
		{
			assert( false );
			return -1;
		}
		
		owVOID Release()
		{
			delete this;
		}
		
		~MemBufferRef()
		{
			
		}
		
	};

	MemBuffer * CreateMemBuffer(owINT32 _nSize)
	{
		return new MemBuffer(_nSize);
	}

}

