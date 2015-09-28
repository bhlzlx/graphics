#ifndef LOGGER_H
#define LOGGER_H

#include <cstdio>

namespace ow
{

class Logger
{
    public:
    
    void Write(const char * szText);
    void Release();
    
    static Logger * GetInstance( const char * szFilepath );
    static Logger * LOGGER;
    
    ~Logger();
    private:
    Logger();
    
    private:
        FILE * file;
};

}

#endif // LOGGER_H
