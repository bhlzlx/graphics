#ifndef MD5_H_INCLUDED
#define MD5_H_INCLUDED
 
#include <cassert>
#include <stdint.h>
#include <cstdlib>
#include <buffer/buffer.h>
 
const extern size_t align_size;
const extern size_t align_mod_size;
const extern size_t align_end_size; // 8 ×ú 64
typedef uint32_t uint;

struct MD5Buffer
{
	iBuffer *			m_pFileBuffer;
	iBuffer *			m_pFilledBuffer;
	uint32_t Read( uint8_t * _pOut, uint32_t _nLength);
	bool Eof();
	void Release();
	MD5Buffer * MD5BufferForData(const iBuffer * _pData);
};

struct MD5Calc
{
    char m_helpBuff[128];
 
    uint A,B,C,D;
    uint a,b,c,d;
 
    uint F(uint& x,uint& y,uint& z);
    uint G(uint& x,uint& y,uint& z);
    uint H(uint& x,uint& y,uint& z);
    uint I(uint& x,uint& y,uint& z);
 
    void FF(uint& a,uint& b,uint& c,uint& d,uint& x,uint y,uint& z);
    void GG(uint& a,uint& b,uint& c,uint& d,uint& x,uint y,uint& z);
    void HH(uint& a,uint& b,uint& c,uint& d,uint& x,uint y,uint& z);
    void II(uint& a,uint& b,uint& c,uint& d,uint& x,uint y,uint& z);
    MD5Calc();
    void Compute( iBuffer * _pData);
	void GetMD5( char * _szBuffer);
    void Turn( uint * chunk);
    void PrintMD5();
};
 
size_t calc_md5_fill_n( size_t nData );
 
#endif // MD5_H_INCLUDED