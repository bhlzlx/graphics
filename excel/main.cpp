#include <stdio.h>
#include <excel/excel_def.h>

using namespace ow::excel;

int main(int argc, char **argv)
{
	ow::excel::ExcelHeap::InitHeap();
	ow::excel::__excelManager.Init();
	ow::excel::excel_table_info * pTableInfo = ow::excel::__excelManager.m_tableMap["Index"];
	for(auto& typeInfo : pTableInfo->m_typeInfo )
	{
		printf("type info : %d\n", typeInfo.vType);
		printf("offset info : %d\n", typeInfo.vOffset);
	}
	
	l_Index mainLine;
	mainLine.iID = 0;
	mainLine.fValue = 0.0f;
	mainLine.szString = NULL;
	
	l_Authors * pAuthor = t_Authors.GetLineById(0);
	l_Index * line = t_Index.GetLineById(0);
	printf("id : %d, value : %f line %p %p", mainLine.iID, mainLine.fValue, line, pAuthor);
	return 0;
}
