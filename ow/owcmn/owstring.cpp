#include <iconv.h>
#include <ctype.h>
#include <assert.h>
#include <iconv.h>

namespace ow
{
	void touppercase( char * _szStr, unsigned int _len )
	{
		for(unsigned int i = 0; i<_len; ++i)
		{
			_szStr[i] = ::toupper( _szStr[i] );
		}
	}
	
	void tolowercase( char * _szStr, unsigned int _len )
	{
		for(unsigned int i = 0; i<_len; ++i)
		{
			_szStr[i] = ::tolower( _szStr[i] );
		}
	}
	
	
	uint32_t utf82ucsle(char* _pUTF8, uint32_t _nDataLen, char* _pUnicode, uint32_t _nBufferSize)
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
		int32_t error = 0;
		error = iconv(conv,&_pUTF8,&_nDataLen,&_pUnicode,&_nBufferSize);
		iconv_close(conv);

		if(error == -1)
		{
			return 0;
		}
		char_count =  (origSize - _nBufferSize) / sizeof(uint16_t);
		return char_count;
	}
}
