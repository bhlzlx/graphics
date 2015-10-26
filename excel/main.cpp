#include <stdio.h>
#include <excel/excel_def.h>

using namespace ow::excel;
using namespace ow;
int main(int argc, char **argv)
{
	owBuffer * excelBuffer = CreateFileBuffer( "table.txt" );
	assert(excelBuffer);
	ow::excel::ExcelHeap::InitHeap();
	ow::excel::ExcelManager_G.Init();
	ExcelManager_G.PushTable(excelBuffer, "Users");
	
	l_Users * pLine = t_Users.GetLineById(0);
	printf("id : %d name: %s sex : %d comment : %s\n", pLine->iID, pLine->szName, pLine->bSex, pLine->szComment);
	system("pause");
	return 0;
}
