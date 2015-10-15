#include "logger.h"
#include <cstring>
#include <owcmn/resources.h>
#include <assert.h>

namespace ow
{

	Logger * Logger::LOGGER = NULL;

	Logger::Logger()
	{
		this->file = NULL;
	}

	Logger::~Logger()
	{
		
	}
	/*
	void Logger::Write(const char * szText)
	{
		fwrite(szText,1,strlen(szText),this->file);
		fwrite("\n",1,1,this->file);
		fflush(this->file);
	}
	*/
	void Logger::Write( const char * _szFormat, ...)
	{
		owSIZE_T args[10];
		memset(&args[0], 0, sizeof(args));
		va_list argptr;  
		va_start(argptr, _szFormat);//初始化变元指针
		for(int argn = 0; argn < 10; argn++)
		{
			args[argn] = va_arg(argptr, owSIZE_T);
			if( strcmp(argptr, "") == 0 )
			{
				break;
			}
		}
		va_end(argptr);
		
		owCHAR * buff = resource::AllocString();
		owINT32 ret = sprintf(buff, _szFormat, args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9] );
		assert(ret < resource::STRING_LENGTH_MAX);
		const char * error = "fatal error : sprintf() access out of bounds!";
		if(ret >= resource::STRING_LENGTH_MAX)
		{
			fwrite( error,1,strlen(error),this->file);
			fwrite("\r\n",1,2,this->file);
		}
		fwrite(buff,1,strlen(buff),this->file);
		fwrite("\r\n",1,2,this->file);
		fflush(file);
	}

	void Logger::Release()
	{
			fclose(this->file);
		if(this->file)
		delete this;
	}

	Logger * Logger::GetInstance(const char * szFilepath)
	{
		if(Logger::LOGGER != NULL)
		{
			return Logger::LOGGER;
		}
		FILE * file = NULL;
		
		if(szFilepath == NULL)
			file = fopen("./log.txt","wb+");
		else
			file = fopen(szFilepath,"wb+");
			
		if(file == NULL)
		{
			printf("\n could not create logger for file : %s \n",szFilepath);
			return NULL;
		}
		Logger * pLogger = new Logger();
		Logger::LOGGER = pLogger;
		pLogger->file = file;
		return pLogger;
	}
}

