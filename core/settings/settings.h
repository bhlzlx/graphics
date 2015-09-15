#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <stdint.h>
#include <map>
#include <string>
#include <buffer/buffer.h>

namespace phantom
{
	typedef std::map< std::string, std::string> Conf_string;
	typedef std::map< std::string, float> Conf_float;
	typedef std::map< std::string, int> Conf_int;
	
	struct Config
	{
		Conf_string 	m_strings;
		Conf_float 		m_floats;
		Conf_int		m_ints;
		
		uint8_t Init( iBuffer * _pBuffer);
		
		int& GetIntValue( const char * _szKey);
		std::string& GetStringValue( const char * _szKey);
		float& GetFloatValue( const char * _szKey);
	};
	
	Config& GetSettings();
}

#endif // __CONFIG_H__