#ifndef MD5_H_INCLUDED
#define MD5_H_INCLUDED
 
#include <cassert>
#include <stdint.h>
#include <cstdlib>
#include <buffer/buffer.h>
#include <owfile/owfile.h>
 
const extern owSIZE_T align_size;
const extern owSIZE_T align_mod_size;
const extern owSIZE_T align_end_size; // 8 ×ú 64

namespace ow
{
	struct MD5BufferA
	{
		owBuffer *			m_pFileBuffer;
		owBuffer *			m_pFilledBuffer;
		owUINT32 Read( owVOID * _pOut, owUINT32 _nLength);
		bool Eof();
		void Release();
		
		static MD5BufferA * MD5BufferForData( owBuffer * _pData);
	};

	struct MD5BufferB
	{
		ow::owFile *		m_pFileBuffer;
		ow::owBuffer *			m_pFilledBuffer;
		
		owUINT32 Read( owVOID * _pOut, owUINT32 _nLength);
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
		void Compute( owBuffer * _pData);
		void GetValue( owCHAR * _szBuffer);
		void Compute( ow::owFile * _pFile);
		void Turn( owUINT32 * chunk);
	};
	 
	owSIZE_T calc_md5_fill_n( owSIZE_T nData );
}
#endif // MD5_H_INCLUDED