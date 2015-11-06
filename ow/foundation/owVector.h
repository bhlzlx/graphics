#ifndef __OW_VECTOR_H__
#define __OW_VECTOR_H__

namespace ow
{
	template< class T>
	struct owVector
	{
		T *		m_pData;
		size_t  m_nCapacity;
		size_t  m_nSize;
		
		owVector();
		void push_back( T & _value);
		void pop_back();
		T& at( size_t _index)const;
		void clear();
		~owVector();
	};

	template< class T>
	owVector<T>::owVector()
	{
		this->m_pData = nullptr;
		this->m_nCapacity = 0;
		this->m_nSize = 0;
	}

	template< class T>
	void owVector<T>::push_back( T& value)
	{
		if(this->m_nCapacity <= this->m_nSize)
		{
			this->m_pData = (T*)realloc( m_pData, this->m_nCapacity * 2);
			assert(m_pData);
			this->m_nCapacity*=2;
		}
		this->m_pData[ this->m_nSize ] = value;
		++this->m_nSize;
	}
	
	template< class T>
	void owVector<T>::pop_back()
	{
		this->m_nSize--;
	}
	
	template<class T>
	T& owVector<T>::at( size_t _index)const
	{
		return m_pData[_index];
	}
	
	template<class T>
	owVector<T>::~owVector()
	{
		free(m_pData);
	}
}

#endif