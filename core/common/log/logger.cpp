#include "logger.h"
#include <cstring>

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

void Logger::Write(const char * szText)
{
    fwrite(szText,1,strlen(szText),this->file);
    fwrite("\n",1,1,this->file);
    fflush(this->file);
}

void Logger::Release()
{
    if(this->file)
        fclose(this->file);
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

