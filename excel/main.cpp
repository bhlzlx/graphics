#include <stdio.h>
#include <excel/excel_def.h>
#include <iostream>
#include <wchar.h>
using namespace ow::excel;
using namespace ow;
int main(int argc, char **argv)
{
	owBuffer * excelBuffer = CreateFileBuffer( "table.txt");
	ow::excel::ExcelHeap::InitHeap();
	ow::excel::__excelManager.Init();
	__excelManager.PushTable(excelBuffer,"Users");
	ow::excel::excel_table_info * pTableInfo = ow::excel::__excelManager.m_tableMap["Users"];
	for(auto& typeInfo : pTableInfo->m_typeInfo )
	{
		printf("type info : %d\n", typeInfo.vType);
		printf("offset info : %d\n", typeInfo.vOffset);
	}
	printf("table lines : %d \n",t_Users.m_vecLines.size());
	l_Users * pLine = t_Users.GetLineById(0);
	printf("id : %d name: %s sex : %d comment : %s\n", pLine->iID, pLine->szName, pLine->bSex, pLine->szComment);
	system("pause");
	return 0;
}
