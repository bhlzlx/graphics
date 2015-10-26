#ifndef __EXCEL_DEF_H__
#define __EXCEL_DEF_H__

#include <owcmn/owcmn.h>
#include <vector>
#include <assert.h>
#include <string>
#include <map>
#include "excel.h"

namespace ow
{
	namespace excel
	{
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
		extern excel_##tb_name t_##tb_name;
		// 定义表值存储结构
		#define TB_DEF_VAR(type, name)
		#define TB_DEF_END()
		#include "excel_meta_def.h"
		#include "excel_undef.h"
		
		// 全局 excel 表格管理器对象
		extern excel_manager ExcelManager_G;
	}
}
	
#endif