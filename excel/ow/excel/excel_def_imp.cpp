#include "excel_def.h"
#include <string.h>

namespace ow
{
	namespace excel
	{
		// 全局变换定义
		excel_manager __excelManager;
		
		// 功能函数定义
		value_type TypeForName( const char * _szTypeName)
		{
			if( strcmp(_szTypeName, "int") == 0)
			{
				return type_int;
			}
			else if(strcmp(_szTypeName, "float") == 0)
			{
				return type_float;
			}
			else if(strcmp(_szTypeName, "char*") == 0)
			{
				return type_string;
			}
			assert(false);
			return type_int;
		}
		
		// 定义存储结构信息初始化方法(表头信息)
		#define TB_DEF_BEGIN( tb_name )\
		void init_##tb_name##_var_def( excel_table_info * pTableInfo )\
		{\
			pTableInfo->m_release_func = NULL;\
			pTableInfo->m_pTable = &t_##tb_name;\
			value_info info;\
			typedef l_##tb_name LineType;
		#define TB_DEF_VAR( type, name )\
			info.vOffset = memptr_cast(&LineType::name);\
			info.vType = TypeForName( #type );\
			pTableInfo->m_typeInfo.push_back(info);
		#define TB_DEF_END() }
		
		#include "excel_meta_def.h"
		#include "excel_undef.h"
		
		// 定义存储结构信息销毁方法
		#define TB_DEF_BEGIN( tb_name )\
		void release_##tb_name##_var_def( excel_table_info * pTableInfo )\
		{\
			pTableInfo->m_release_func = NULL;\
			pTableInfo->m_init_func = NULL;\
			pTableInfo->m_typeInfo.clear();\
			for( l_##tb_name * pLine : t_##tb_name.m_vecLines)\
			{\
				delete pLine;\
			}
		#define TB_DEF_VAR( type, name )
		#define TB_DEF_END() }
		
		#include "excel_meta_def.h"
		#include "excel_undef.h"
		
		#define TB_DEF_BEGIN( tb_name ) \
		l_##tb_name * excel_##tb_name::GetLineByIndex( owUINT32 _index )\
		{\
			if(_index < m_vecLines.size() )\
			{\
				return m_vecLines[_index];\
			}\
			return NULL;\
		}\
		\
		l_##tb_name * excel_##tb_name::GetLineById( owINT32 _id )\
		{\
			size_t offset = 0xffffffff;\
			excel_table_info * pTableInfo = __excelManager.m_tableMap[ #tb_name ];\
			for( const value_info& vf: pTableInfo->m_typeInfo)\
			{\
				if(vf.vType == type_int)\
				{\
					offset = vf.vOffset;\
					break;\
				}\
			}\
			if(offset == 0xffffffff)\
			{\
				assert(0&&"table does not contains a ID column!");\
			}\
			for( l_##tb_name * pLine : m_vecLines)\
			{\
				int id = memdata_get<l_##tb_name, int>((void *)pLine, offset);\
				if(id == _id)\
				{\
					return pLine;\
				}\
			}\
			return NULL;\
		}\
		\
		excel_##tb_name t_##tb_name;
		// 定义表值存储结构
		#define TB_DEF_VAR(type, name)
		#define TB_DEF_END()
		#include "excel_meta_def.h"
		#include "excel_undef.h"
		
		// 初始化表格管理器(表头信息)
		#define TB_DEF_BEGIN( tb_name )\
		szTableName = #tb_name;\
		if( __excelManager.m_tableMap[ szTableName ] == NULL)\
		{\
			excel_table_info * pTableInfo = new excel_table_info();\
			pTableInfo->m_init_func =  init_##tb_name##_var_def;\
			__excelManager.m_tableMap[ szTableName ] = pTableInfo;\
		}\
		__excelManager.m_tableMap[ szTableName ]->m_pTable =  (void *)&t_##tb_name;
		#define TB_DEF_VAR( type, name )
		#define TB_DEF_END()
		void init_excel_manager()
		{
			const char * szTableName = NULL;
		#include "excel_meta_def.h"
		#include "excel_undef.h"
		}
		
		// 销毁表格管理器(表头信息)
		void clear_excel_manager()
		{
			for(auto& p : __excelManager.m_tableMap)
			{
				p.second->m_release_func(p.second);
				delete p.second;
			}
			__excelManager.m_tableMap.clear();
		}
	}
	
}