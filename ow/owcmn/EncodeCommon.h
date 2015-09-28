#ifndef __EncodeCommon_H__
#define __EncodeCommon_H__

#include <stdint.h>

uint32_t UTF82Unicode( uint16_t * _pUTF8, uint32_t _nDataLen, uint16_t* _pUnicode, uint32_t _nBufferSize);

#endif // __EncodeCommon_H__
