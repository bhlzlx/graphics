#include <stdio.h>
#include <stdint.h>
#include <owfile/owfile.h>
#include <owZip/owZip.h>
#include <algorithm/md5.h>
#include <package/package_common.h>
#include <package/owPackage.h>
#include <settings/settings.h>
#include <owcmn/ResourcePool.h>

using namespace ow;

int main(int argc, char **argv)
{
	InitResourcePool();
	owBOOL ret = ow::GetPreference().Init("./preference.pref");
	if(ret == owFALSE)
	{
		return -1;
	}
	
	owINT32 pack_type = ow::GetPreference().GetIntValue("PACK_TYPE");
	if(pack_type == 0 )
	{
		ow::owNodeW * rootNode = new owNodeW;
		owINT32 nodeNum = ow::owSearchDir( ow::GetPreference().GetStringValue("PACK_DIR").c_str(), rootNode);
		if(nodeNum == 0)
		{
			printf("invalid directory : %s \n", ow::GetPreference().GetStringValue("PACK_DIR").c_str());
			system("pause");
			return -1;
		}
		rootNode->Sort();
		rootNode->Print(0);
		owBOOL succeed = owCreatePackage( rootNode, nodeNum, ow::GetPreference().GetStringValue("TARGET_PACK").c_str());
		if(succeed == owTRUE)
		{
			printf("create package succeed~\n");
		}
		else
		{
			printf("create package failed~\n");
		}
		rootNode->Release();
	}
	else
	{
		owPackage package;
		ret = package.Init( ow::GetPreference().GetStringValue("TARGET_PACK").c_str());
		if(ret == owFALSE)
		{
			return -1;
		}
		owFile * file = package.Open( ow::GetPreference().GetStringValue("TEST_FILE").c_str() );		
		if( file == NULL)
		{
			printf("error : File Does Not Exist ! ");
		}
		file->Release();
	}
	ReleaseResourcePool();
	system("pause");
}
