#ifndef MD5_H_INCLUDED
#define MD5_H_INCLUDED
 
#include <cassert>
#include <stdint.h>
#include <cstdlib>
#include <buffer/buffer.h>
#include <owfile/owfile.h>
 
const extern size_t align_size;
const extern size_t align_mod_size;
const extern size_t align_end_size; // 8 ×ú 64
typedef uint32_t uint;

struct MD5BufferA
{
	IBuffer *			m_pFileBuffer;
	IBuffer *			m_pFilledBuffer;
	uint32_t Read( int8_t * _pOut, uint32_t _nLength);
	bool Eof();
	void Release();
	
	static MD5BufferA * MD5BufferForData( IBuffer * _pData);
};

struct MD5BufferB
{
	ow::owFile *		m_pFileBuffer;
	IBuffer *			m_pFilledBuffer;
	
	uint32_t Read( int8_t * _pOut, uint32_t _nLength);
	bool Eof();
	void Release();
	static MD5BufferB * MD5BufferForFile( ow::owFile * _pFile);
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
    void Compute( IBuffer * _pData);
	void GetMD5( char * _szBuffer);
	void Compute( ow::owFile * _pFile);
    void Turn( uint * chunk);
};
 
size_t calc_md5_fill_n( size_t nData );
 
#endif // MD5_H_INCLUDED