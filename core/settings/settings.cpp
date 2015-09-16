#include "settings.h"
#include <string.h>
#include <cstdio>
#include <cassert>

namespace ow
{
	uint8_t isValidLine( char * _pLine, uint16_t _nLength)
	{
		for(int i = 0;i<_nLength;++i)
		{
			if( isprint(_pLine[i]) )
			{
				if(_pLine[i] == '/')
				{
					return 0;
				}
				else
				{
					return 1;
				}
			}
		}
		// all blank!
		return 0;
	}
	
	char * read_line(iBuffer * _pBuffer)
	{
		static char buffer[512];
		int length ;
again:
		length = 0;
		memset(buffer,0,512);
		while(true)
		{
			int ret = _pBuffer->Read((unsigned char *)buffer + length,1);
			if(ret == 0 )
			{
				if(length == 0)
					return NULL;
				else
					break;
			}
			++length;
			if(buffer[length - 1] == '\n')
			{
				if(!isValidLine(buffer,length))
				{
					goto again;
				}
				break;
			}
		}
		buffer[length] = 0;
		return buffer;
	}
	
	iBuffer * read_config_block(iBuffer * _pBuffer)
	{
		char * pLine = read_line(_pBuffer);
		if(pLine == NULL)
		{
			return NULL;
		}
		// 找 ';'
		uint8_t * pContent = _pBuffer->GetCurr();
		uint8_t * pEnd = (uint8_t*)strchr((char*)pContent,';');
		int32_t nLen = pEnd - pContent - 1;
		iBuffer *pRet = CreateBufferRef( pContent, nLen);
		_pBuffer->Seek(SEEK_CUR,nLen + 4);
		return pRet;
	}
	
	uint8_t Settings::Init( iBuffer *_pBuffer)
	{
		iBuffer * bufferRef = (iBuffer*)0;
		while(bufferRef = read_config_block(_pBuffer) )
		{
			char * pLine = read_line( bufferRef );
			char ch;
			int32_t ret = 0;
			ret = sscanf(pLine,"< %c >",&ch);
			assert(ret != 0);
			
			char keybuffer[32];
			
			if(ch == 'S')
			{
				char stringvalue[128];
				while( pLine = read_line(bufferRef))
				{
					sscanf(pLine,"%s = %s", &keybuffer[0], &stringvalue[0]);
					this->m_strings[keybuffer] = stringvalue;
				}
			}
			else if(ch == 'F')
			{
				float value;
				while( pLine = read_line(bufferRef))
				{
					sscanf(pLine, "%s = %f", &keybuffer[0], &value);
					this->m_floats[keybuffer] = value;
				}
			}
			else if(ch == 'I')
			{
				int value;
				while( pLine = read_line(bufferRef))
				{
					sscanf(pLine, "%s = %d", &keybuffer[0], &value);
					this->m_ints[keybuffer] = value;
				}
			}
		}
	}
	
	Settings __setttings;
	
	Settings& GetSettings()
	{
		return __setttings;
	}
}


float& ow::Settings::GetFloatValue(const char* _szKey)
{
	Conf_float::iterator iter = m_floats.find(_szKey);
	if(iter == m_floats.end())
	{
		assert(false && "empty key-value");
		static float v = 0.0f;
		return v;
	}
	return this->m_floats[_szKey];
}

int& ow::Settings::GetIntValue(const char* _szKey)
{
	Conf_int::iterator iter = m_ints.find(_szKey);
	if(iter == m_ints.end())
	{
		assert(false && "empty key-value");
		static int v = -1;
		return v;
	}
	return this->m_ints[_szKey];
}

std::string& ow::Settings::GetStringValue(const char* _szKey)
{
	Conf_string::iterator iter = m_strings.find(_szKey);
	if(iter == m_strings.end())
	{
		assert(false && "empty key-value");
		static std::string v = "";
		return v;
	}
	return this->m_strings[_szKey];
}
