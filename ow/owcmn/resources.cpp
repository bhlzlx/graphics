#include "resources.h"
#include <assert.h>
#include <owfile/owfile.h>
#include <excel/excel_def.h>
#include <buffer/buffer.h>
#include <archive/owArchive.h>

#define PACKAGE_PATH 			"package.pkg"
#define PREFERENCE_PATH			"config.txt"

using namespace ow;

namespace resource
{
	ow::owPackage*	 __package = NULL;
	ow::SMemPool*	 __stringPool = NULL;
	
	const owINT32 STRING_LENGTH_MAX = 1024;
	
	void Init()
	{
		// 初始化excel模块
		ow::excel::ExcelHeap::InitHeap();
		ow::excel::ExcelManager_G.Init();
		// 初始化字符串池
		__stringPool = new ow::SMemPool(8,RESOURCE_STRING_LENGTH_MAX);
		// 初始化配置文件
		ow::owArchive * archive = ow::GetArchive();
		owFile * excelFile = archive->Open( "./mb/preference.txt" );
		assert(excelFile);
		ow::excel::ExcelManager_G.PushTable(excelFile->GetBuffer(), "Preference");
		excelFile->Release();
		excelFile = archive->Open( "./mb/Music.txt" );
		assert(excelFile);
		ow::excel::ExcelManager_G.PushTable(excelFile->GetBuffer(), "Music");
		excelFile->Release();
		excelFile = archive->Open( "./mb/Sound.txt" );
		assert(excelFile);
		ow::excel::ExcelManager_G.PushTable(excelFile->GetBuffer(), "Sound");
		excelFile->Release();
	}

	void Release()
	{
		if(__stringPool)
		{
			delete __stringPool;
			__stringPool = NULL;
		}
		
		if(__package)
		{
			__package->Release();
			__package = NULL;
		}
	}
	
	ow::owPackage * GetPackage()
	{
		return __package;
	}
	
	owCHAR * AllocString()
	{
		return (owCHAR *)__stringPool->Alloc(1);
	}
	
	void ReleaseString( owVOID * _string)
	{
		__stringPool->Recycle( _string);
	}
}