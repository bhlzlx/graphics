#include <stdio.h>
#include <excel/excel_def.h>

using namespace ow::excel;
using namespace ow;
int main(int argc, char **argv)
{
	owBuffer * excelBuffer = CreateFileBuffer( "User.txt" );
	assert(excelBuffer);
	ow::excel::ExcelHeap::InitHeap();
	ow::excel::ExcelManager_G.Init();
	ExcelManager_G.PushTable(excelBuffer, "User");
	
	l_User * pLine = t_User.GetLineById(0);
	printf("id : %d name: %s sex : %d comment : %s\n", pLine->nID, pLine->szName, pLine->iAge, pLine->szComment);
	system("pause");
	return 0;
}
