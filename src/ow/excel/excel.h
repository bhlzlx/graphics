#ifndef __EXCEL_H__
#define __EXCEL_H__

#include <cmn/owcmn.h>
#include <buffer/buffer.h>
#include <memory/memory.h>
#include <vector>
#include <map>

//define EXCEL_USE_UNICODE

namespace ow
{
	namespace excel
	{
		struct ExcelHeap
		{
			static owINT32 CELL_SIZE_MIN;
			static owINT32 CELL_SIZE_MAX;

			static owVOID InitHeap();
			static owVOID ReleaseHeap();

			static owVOID * alloc( owUINT32 _nSize );
			static owVOID dealloc( owVOID * _pPtr );

			static std::vector< ow::SMemPool* > m_vec_pool;
		};

		enum value_type
		{
			type_int = 0,
			type_float,
			type_string
		};

		value_type TypeForName( const char * _szTypeName);

		struct value_info
		{
			value_type		vType;
			owSIZE_T 		vOffset;
		};

		typedef std::vector<value_info> excel_type_info;

		/////////////////////////////////////////////////////////////////////////////
		////                       工具方法
		template< class T>
		size_t memptr_cast(T t)
		{
			union
			{
				T 		v1;
				size_t 	v2;
			} u;
			u.v1 = t;
			return u.v2;
		}

		template <class T>
		T memdata_get( void * ptr, size_t offset)
		{
			char * bytes = reinterpret_cast<char *>(ptr) + offset;
			return *reinterpret_cast<T*>(bytes);
		}

		template <class T>
		void memdata_set( void * ptr, size_t offset, T value)
		{
			*(T*)((owBYTE*)ptr + offset) = value;
		}

		/////////////////////////////////////////////////////////////////////////////////
		////               excel 表格 存储 格式 相关

		struct excel_table_info;

		typedef void (* EXCEL_TABLE_INFO_INIT_FUNC )( excel_table_info * pTypeInfo );
		typedef void (* EXCEL_TABLE_INFO_RELEASE_FUNC )( excel_table_info * pTypeInfo );
		typedef void * ( * EXCEL_TABLE_INSERT_FUNC )( void * _pTable );

		struct excel_table_info
		{
			excel_type_info					m_typeInfo;
			EXCEL_TABLE_INFO_INIT_FUNC		m_init_func;
			EXCEL_TABLE_INFO_RELEASE_FUNC	m_release_func;
			EXCEL_TABLE_INSERT_FUNC			m_insert_func;
			void * 							m_pTable;
		};

		/////////////////////////////////////////////////////////////////////////////////
		////                 excel 表格 管理器
		void init_excel_manager();
		void clear_excel_manager();

		struct excel_manager
		{
			std::map<std::string, excel_table_info *>			m_tableMap;
			excel_manager();
			owBOOL Init();
			owBOOL PushTable( ow::owBuffer * _pBuffer, const char * _szName );
			owBOOL Clear();
			~excel_manager();
		};

	}
}

#endif // __EXCEL_H__
