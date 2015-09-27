#include <stdio.h>
#include <stdint.h>
#include <owfile/owfile.h>
#include <owZip/owZip.h>
#include <algorithm/md5.h>
#include <package/package_common.h>

using namespace ow;

int main(int argc, char **argv)
{
	
	ow::owNode * rootNode = new owNode;
	
	int32_t nodeNum = ow::owSearchDir( "F:/tdmgcclib/include/", rootNode);
	rootNode->Sort();	
	rootNode->Print( 0 );	
	owCreatePackage( rootNode, nodeNum, "F:/tdmgcclib/include.pkg");
	// write head
	//packageFile->Write()
	
	
/*	ow::owFile * pFile = ow::CreateStdFile("nagisa.png","rb");
	
	ow::owZip zip;
	ow::owFile * zipFile = zip.Compress( pFile, 3);
	
	ow::owFile * zipStdFile = ow::CreateStdFile("zip.bin","wb");

	ow::owMemFile * zipMemFile = (ow::owMemFile *)zipFile;
	zipStdFile->Write( zipMemFile->m_pMemBuffer->GetBuffer(), zipMemFile->m_pMemBuffer->Size());
	zipStdFile->Release();
	zipFile->Release();
	pFile->Release();
	
	 */
	/*ow::owFile * pStdFile = ow::CreateStdFile("zip.bin","rb");
	
	MD5Calc calc;
	calc.Compute( pStdFile);
	
	char md5Message[64];
	calc.GetMD5( &md5Message[0]);
	md5Message[32] = 0;
	printf("md5 : %s", md5Message);
	
	ow::owZip zip;
	ow::owMemFile* memFile = (ow::owMemFile*)zip.Uncompress( pStdFile);
	ow::owFile * orStdFile = ow::CreateStdFile("o.png","wb");
	orStdFile->Write( memFile->m_pMemBuffer->GetBuffer(), memFile->m_pMemBuffer->Size());
	orStdFile->Release();
	memFile->Release();
	pStdFile->Release();
	*/
	rootNode->Release();
	return 0;
}
