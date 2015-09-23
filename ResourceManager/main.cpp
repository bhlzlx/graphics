#include <stdio.h>
#include <owfile/owfile.h>
#include <owZip/owZip.h>

int main(int argc, char **argv)
{
	ow::owFile * pFile = ow::CreateStdFile("hellknight.png","rb");
	
	ow::owZip zip;
	ow::owFile * zipFile = zip.Compress( pFile, 9);
	
	ow::owFile * zipStdFile = ow::CreateStdFile("zip.bin","wb+");
	ow::owMemFile * zipMemFile = (ow::owMemFile *)zipFile;
	zipStdFile->Write( zipMemFile->m_pMemBuffer->GetBuffer(), zipMemFile->m_pMemBuffer->Size());
	zipStdFile->Release();
	zipFile->Release();
	pFile->Release();
	return 0;
}
