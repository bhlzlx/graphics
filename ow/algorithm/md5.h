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

namespace ow
{
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

	struct MD5
	{
		char m_helpBuff[128];
	 
		owUINT32 A,B,C,D;
		owUINT32 a,b,c,d;
	 
		owUINT32 F(owUINT32& x,owUINT32& y,owUINT32& z);
		owUINT32 G(owUINT32& x,owUINT32& y,owUINT32& z);
		owUINT32 H(owUINT32& x,owUINT32& y,owUINT32& z);
		owUINT32 I(owUINT32& x,owUINT32& y,owUINT32& z);
	 
		void FF(owUINT32& a,owUINT32& b,owUINT32& c,owUINT32& d,owUINT32& x,owUINT32 y,owUINT32& z);
		void GG(owUINT32& a,owUINT32& b,owUINT32& c,owUINT32& d,owUINT32& x,owUINT32 y,owUINT32& z);
		void HH(owUINT32& a,owUINT32& b,owUINT32& c,owUINT32& d,owUINT32& x,owUINT32 y,owUINT32& z);
		void II(owUINT32& a,owUINT32& b,owUINT32& c,owUINT32& d,owUINT32& x,owUINT32 y,owUINT32& z);
		MD5();
		void Compute( IBuffer * _pData);
		void GetValue( char * _szBuffer);
		void Compute( ow::owFile * _pFile);
		void Turn( owUINT32 * chunk);
	};
	 
	size_t calc_md5_fill_n( size_t nData );
}
#endif // MD5_H_INCLUDED