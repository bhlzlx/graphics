#ifndef __OW_STRING_H__
#define __OW_STRING_H__

#include <ctype.h>

namespace ow
{
	void touppercase( char * _szStr, unsigned int _len );	
	void tolowercase( char * _szStr, unsigned int _len );	
	
	uint32_t utf82ucsle( const char* _pUTF8, uint32_t _nDataLen, char* _pUnicode, uint32_t _nBufferSize);
	uint32_t utf82ascii( const char* _pUTF8, uint32_t _nDataLen, char* _pAscii, uint32_t _nBufferSize);
}

#endif