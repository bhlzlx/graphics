#ifndef __EXCEL_DEF_H__
#define __EXCEL_DEF_H__

#include <owcmn/owcmn.h>
#include <vector>
#include <assert.h>
#include <string>
#include <map>

namespace ow
{
	namespace excel
	{
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
		
		/////////////////////////////////////////////////////////////////////////////////
		////               excel 表格 存储 格式 相关
		
		struct excel_table_info;
		
		typedef void (* EXCEL_TABLE_INFO_INIT_FUNC )( excel_table_info * pTypeInfo );
		typedef void (* EXCEL_TABLE_INFO_RELEASE_FUNC )( excel_table_info * pTypeInfo );
		
		struct excel_table_info
		{
			excel_type_info					m_typeInfo;
			EXCEL_TABLE_INFO_INIT_FUNC		m_init_func;
			EXCEL_TABLE_INFO_RELEASE_FUNC	m_release_func;
			void * 							m_pTable;
		};
		
		/////////////////////////////////////////////////////////////////////////////////
		////                 excel 表格 管理器
		void init_excel_manager();
		void clear_excel_manager();
		
		struct excel_manager
		{
			std::map<std::string, excel_table_info *>			m_tableMap;
			excel_manager()
			{
			}
			owBOOL Init()
			{
				init_excel_manager();
				for( auto &p : m_tableMap)
				{
					p.second->m_init_func( p.second );
				}
				return owTRUE;
			}
			
			owBOOL Clear()
			{
				clear_excel_manager();
				return owTRUE;
			}
			
			~excel_manager()
			{
			}
		};
		
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

		template <class T, class S>
		S memdata_get( void * ptr, size_t offset)
		{
			char * bytes = reinterpret_cast<char *>(ptr) + offset;
			return *reinterpret_cast<S*>(bytes);
		}
		/////////////////////////////////////////////////////////////////////////////
		///////                  定义表格行
		#define TB_DEF_BEGIN( tb_name ) struct l_##tb_name{
		#define TB_DEF_VAR( type, name ) type name;
		#define TB_DEF_END() };
		#include "excel_meta_def.h"
		#include "excel_undef.h"
		
		// 定义行存储结构(表头信息)
		#define TB_DEF_BEGIN( tb_name )\
		void init_##tb_name##_var_def( excel_table_info * pTypeInfo );
		#define TB_DEF_VAR( type, name )
		#define TB_DEF_END()		
		#include "excel_meta_def.h"
		#include "excel_undef.h"
		
		/////////////////////////////////////////////////////////////////////////////
		///////                  定义表格对象
		#define TB_DEF_BEGIN( tb_name ) \
		struct excel_##tb_name\
		{\
			excel_##tb_name(){}\
			~excel_##tb_name(){}\
			std::vector<l_##tb_name *> m_vecLines;\
			l_##tb_name * GetLineByIndex( owUINT32 _index );\
			l_##tb_name * GetLineById( owINT32 _id );\
		};\
		extern excel_##tb_name __tb_##tb_name;
		// 定义表值存储结构
		#define TB_DEF_VAR(type, name)
		#define TB_DEF_END()
		#include "excel_meta_def.h"
		#include "excel_undef.h"
		
		// 全局 excel 表格管理器对象
		extern excel_manager __excelManager;
	}
}
	
#endif