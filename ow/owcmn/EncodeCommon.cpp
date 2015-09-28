#include "EncodeCommon.h"
#include <iconv.h>
#include <assert.h>

uint32_t UTF82Unicode( uint16_t * _pUTF8, uint32_t _nDataLen, uint16_t* _pUnicode, uint32_t _nBufferSize)
{
	// utf8转unicode内码大小极端情况下内存占用是原来的2倍
	assert(_nDataLen*2 <= _nBufferSize);
	
	uint32_t char_count = 0;
	iconv_t conv = iconv_open("UCS-2LE", "UTF-8");
	uint32_t origSize = _nBufferSize;
	if(conv == iconv_t(-1))
	{
		return 0;
	}
	uint32_t error = 0;
	error = iconv(conv,(char**)&_pUTF8,&_nDataLen,(char **)&_pUnicode,&_nBufferSize);
	if(error == -1)
	{
		iconv_close(conv);
		return 0;
	}
	char_count =  (origSize - _nBufferSize) / sizeof(uint16_t);
	return char_count;
}