#include "md5.h"
#include <cmath>
#include <cstdio>
#include <buffer/buffer.h>
#include <memory.h>

namespace ow
{

	bool MD5BufferA::Eof()
	{
		return this->m_pFileBuffer->Eof() && this->m_pFilledBuffer->Eof();
	}

	owUINT32 MD5BufferA::Read(owVOID * _pOut,owUINT32 _nLength)
	{
		if(!this->m_pFileBuffer->Eof())
		{
			owUINT32 ret = m_pFileBuffer->Read(_pOut,_nLength);
			if(ret < _nLength)
			{
				ret += m_pFilledBuffer->Read( (owBYTE*)_pOut + ret, _nLength - ret );
			}
			return ret;
		}
		else
		{
			return m_pFilledBuffer->Read(_pOut,_nLength);
		}
	}

	void MD5BufferA::Release()
	{
		this->m_pFilledBuffer->Release();
		delete this;
	}

	MD5BufferA * MD5BufferA::MD5BufferForData( owBuffer * _pData)
	{
		MD5BufferA * pBuffer = new MD5BufferA();
		pBuffer->m_pFileBuffer = _pData;
		owINT64 filesize =pBuffer->m_pFileBuffer->Size();
		owUINT32 filledSize = calc_md5_fill_n(filesize) + sizeof(owINT64);
		pBuffer->m_pFilledBuffer = CreateMemBuffer(filledSize);
		owBYTE * ptr = pBuffer->m_pFilledBuffer->GetBuffer();
		memset(ptr,0,filledSize);
		*ptr = 0b10000000;
		ptr += filledSize - sizeof(owINT64);
		filesize = filesize * 8;
		memcpy( ptr,&filesize,sizeof(owINT64) );
		
		return pBuffer;
	}

	owUINT32 MD5BufferB::Read(owVOID * _pOut,owUINT32 _nLength)
	{
		if(!this->m_pFileBuffer->Eof())
		{
			owUINT32 ret = m_pFileBuffer->Read(_pOut,_nLength);
			if(ret < _nLength)
			{
				ret += m_pFilledBuffer->Read( (owBYTE*)_pOut + ret, _nLength - ret );
			}
			return ret;
		}
		else
		{
			return m_pFilledBuffer->Read(_pOut,_nLength);
		}
	}

	void MD5BufferB::Release()
	{
		this->m_pFilledBuffer->Release();
		delete this;
	}

	bool MD5BufferB::Eof()
	{
		return this->m_pFileBuffer->Eof() && this->m_pFilledBuffer->Eof();
	}

	MD5BufferB * MD5BufferB::MD5BufferForFile( ow::owFile * _pFile)
	{
		MD5BufferB * pBuffer = new MD5BufferB();
		pBuffer->m_pFileBuffer = _pFile;
		owINT64 filesize =pBuffer->m_pFileBuffer->Size();
		owUINT32 filledSize = calc_md5_fill_n(filesize) + sizeof(owINT64);
		pBuffer->m_pFilledBuffer = CreateMemBuffer(filledSize);
		owBYTE * ptr = pBuffer->m_pFilledBuffer->GetBuffer();
		memset(ptr,0,filledSize);
		*ptr = 0b10000000;
		ptr += filledSize - sizeof(owINT64);
		filesize = filesize * 8;
		memcpy( ptr,&filesize,sizeof(owINT64) );
		
		return pBuffer;
	}
	 
	unsigned char chain_values[] =
	{
		0x01,0x23,0x45,0x67,
		0x89,0xab,0xcd,0xef,
		0xfe,0xdc,0xba,0x98,
		0x76,0x54,0x32,0x10
	};
	 
	owUINT32 T[] =
	{
		0x00000000,
		0xd76aa478,0xe8c7b756,0x242070db,0xc1bdceee,
		0xf57c0faf,0x4787c62a,0xa8304613,0xfd469501,
		0x698098d8,0x8b44f7af,0xffff5bb1,0x895cd7be,
		0x6b901122,0xfd987193,0xa679438e,0x49b40821,
	 
		0xf61e2562,0xc040b340,0x265e5a51,0xe9b6c7aa,
		0xd62f105d,0x02441453,0xd8a1e681,0xe7d3fbc8,
		0x21e1cde6,0xc33707d6,0xf4d50d87,0x455a14ed,
		0xa9e3e905,0xfcefa3f8,0x676f02d9,0x8d2a4c8a,
	 
		0xfffa3942,0x8771f681,0x6d9d6122,0xfde5380c,
		0xa4beea44,0x4bdecfa9,0xf6bb4b60,0xbebfbc70,
		0x289b7ec6,0xeaa127fa,0xd4ef3085,0x04881d05,
		0xd9d4d039,0xe6db99e5,0x1fa27cf8,0xc4ac5665,
	 
		0xf4292244,0x432aff97,0xab9423a7,0xfc93a039,
		0x655b59c3,0x8f0ccc92,0xffeff47d,0x85845dd1,
		0x6fa87e4f,0xfe2ce6e0,0xa3014314,0x4e0811a1,
		0xf7537e82,0xbd3af235,0x2ad7d2bb,0xeb86d391
	};
	 
	/*
	unsigned int T(float i)
	{
		double s = sin(i);
		if (s > 0) {
			return 4294967296.f * s;
		}
		else
		{
			return 4294967296.f * -s;
		}
	}
	*/
	 
	const owSIZE_T align_size = 64;
	const owSIZE_T align_mod_size = 56;
	const owSIZE_T align_end_size = sizeof(long long int); //
	 
	unsigned int CLS_32( unsigned int i , unsigned int offset)
	{
		assert(offset < 32 && offset > 0);
		return i<<offset|i>>(32-offset);
	}
	 
	MD5::MD5()
	{
	}
	 
	owUINT32 MD5::F(owUINT32& x,owUINT32& y,owUINT32& z)
	{
		return (x&y)|((~x)&z);
	}
	owUINT32 MD5::G(owUINT32& x,owUINT32& y,owUINT32& z)
	{
		return (x&z)|(y&(~z));
	}
	owUINT32 MD5::H(owUINT32& x,owUINT32& y,owUINT32& z)
	{
		return x^y^z;
	}
	owUINT32 MD5::I(owUINT32& x,owUINT32& y,owUINT32& z)
	{
		return y^(x|(~z));
	}
	 
	void MD5::FF(owUINT32& a,owUINT32& b,owUINT32& c,owUINT32& d,owUINT32& x,owUINT32 y,owUINT32& z)
	{
		a = b+CLS_32(a+F(b,c,d)+x+z,y);
	}
	void MD5::GG(owUINT32& a,owUINT32& b,owUINT32& c,owUINT32& d,owUINT32& x,owUINT32 y,owUINT32& z)
	{
		a = b+CLS_32(a+G(b,c,d)+x+z,y);
	}
	void MD5::HH(owUINT32& a,owUINT32& b,owUINT32& c,owUINT32& d,owUINT32& x,owUINT32 y,owUINT32& z)
	{
		a = b+CLS_32(a+H(b,c,d)+x+z,y);
	}
	void MD5::II(owUINT32& a,owUINT32& b,owUINT32& c,owUINT32& d,owUINT32& x,owUINT32 y,owUINT32& z)
	{
		a = b+CLS_32(a+I(b,c,d)+x+z,y);
	}
	 
	void MD5::Turn(owUINT32 * chunk)
	{
		//
		a = A;
		b = B;
		c = C;
		d = D;
	 
		FF(a,b,c,d,chunk[0],7,T[1]);FF(d,a,b,c,chunk[1],12,T[2]);FF(c,d,a,b,chunk[2],17,T[3]);FF(b,c,d,a,chunk[3],22,T[4]);
		FF(a,b,c,d,chunk[4],7,T[5]);FF(d,a,b,c,chunk[5],12,T[6]);FF(c,d,a,b,chunk[6],17,T[7]);FF(b,c,d,a,chunk[7],22,T[8]);
		FF(a,b,c,d,chunk[8],7,T[9]);FF(d,a,b,c,chunk[9],12,T[10]);FF(c,d,a,b,chunk[10],17,T[11]);FF(b,c,d,a,chunk[11],22,T[12]);
		FF(a,b,c,d,chunk[12],7,T[13]);FF(d,a,b,c,chunk[13],12,T[14]);FF(c,d,a,b,chunk[14],17,T[15]);FF(b,c,d,a,chunk[15],22,T[16]);
		//
		GG(a,b,c,d,chunk[1],5,T[17]);GG(d,a,b,c,chunk[6],9,T[18]);GG(c,d,a,b,chunk[11],14,T[19]);GG(b,c,d,a,chunk[0],20,T[20]);
		GG(a,b,c,d,chunk[5],5,T[21]);GG(d,a,b,c,chunk[10],9,T[22]);GG(c,d,a,b,chunk[15],14,T[23]);GG(b,c,d,a,chunk[4],20,T[24]);
		GG(a,b,c,d,chunk[9],5,T[25]);GG(d,a,b,c,chunk[14],9,T[26]);GG(c,d,a,b,chunk[3],14,T[27]);GG(b,c,d,a,chunk[8],20,T[28]);
		GG(a,b,c,d,chunk[13],5,T[29]);GG(d,a,b,c,chunk[2],9,T[30]);GG(c,d,a,b,chunk[7],14,T[31]);GG(b,c,d,a,chunk[12],20,T[32]);
		//
		HH(a,b,c,d,chunk[5],4,T[33]);HH(d,a,b,c,chunk[8],11,T[34]);HH(c,d,a,b,chunk[11],16,T[35]);HH(b,c,d,a,chunk[14],23,T[36]);
		HH(a,b,c,d,chunk[1],4,T[37]);HH(d,a,b,c,chunk[4],11,T[38]);HH(c,d,a,b,chunk[7],16,T[39]);HH(b,c,d,a,chunk[10],23,T[40]);
		HH(a,b,c,d,chunk[13],4,T[41]);HH(d,a,b,c,chunk[0],11,T[42]);HH(c,d,a,b,chunk[3],16,T[43]);HH(b,c,d,a,chunk[6],23,T[44]);
		HH(a,b,c,d,chunk[9],4,T[45]);HH(d,a,b,c,chunk[12],11,T[46]);HH(c,d,a,b,chunk[15],16,T[47]);HH(b,c,d,a,chunk[2],23,T[48]);
		//
		II(a,b,c,d,chunk[0],6,T[49]); II(d,a,b,c,chunk[7],10,T[50]); II(c,d,a,b,chunk[14],15,T[51]);II(b,c,d,a,chunk[5],21,T[52]);
		II(a,b,c,d,chunk[12],6,T[53]);II(d,a,b,c,chunk[3],10,T[54]); II(c,d,a,b,chunk[10],15,T[55]);II(b,c,d,a,chunk[1],21,T[56]);
		II(a,b,c,d,chunk[8],6,T[57]); II(d,a,b,c,chunk[15],10,T[58]);II(c,d,a,b,chunk[6], 15,T[59]); II(b,c,d,a,chunk[13],21,T[60]);
		II(a,b,c,d,chunk[4],6,T[61]); II(d,a,b,c,chunk[11],10,T[62]);II(c,d,a,b,chunk[2], 15,T[63]); II(b,c,d,a,chunk[9],21,T[64]);
	 
		A += a;
		B += b;
		C += c;
		D += d;
	}
	 
	 
	void MD5::GetValue( char * _szBuffer)
	{
		owUINT32 array[] = {A,B,C,D};
		for(owUINT32 i = 0;i<sizeof(array);i++)
		{
			unsigned char cc = *(((unsigned char *)array)+i);
			char cell[2];
			sprintf(cell,"%02x",cc);
			_szBuffer[i*2] = cell[0];
			_szBuffer[i*2+1] = cell[1];
		}
		_szBuffer[32] = 0;
	}
	 
	owSIZE_T calc_md5_fill_n( owSIZE_T nData )
	{
		if(nData & (align_size-1))
		{
			unsigned int t = (nData + align_size - 1) & ~(align_size-1);
			if (t - align_end_size > nData)
			{
				return  t - align_end_size - nData;
			}
			else
			{
				return t + align_mod_size;
			}
		}
		else //  64a￥–°μ’ ±
		{
			return align_mod_size;
		}
	}

	void MD5::Compute( owBuffer * _pData)
	{
		A = *(owUINT32*)chain_values;
		B = *((owUINT32*)chain_values + 1);
		C = *((owUINT32*)chain_values + 2);
		D = *((owUINT32*)chain_values + 3);
		
		MD5BufferA * pMD5Buffer = MD5BufferA::MD5BufferForData(_pData);
		int8_t buff[64];
		while(!pMD5Buffer->Eof())
		{
			pMD5Buffer->Read(buff,64);
			this->Turn((owUINT32 *)&buff[0]);
		}
		pMD5Buffer->Release();
	}


	void MD5::Compute( ow::owFile * _pFile)
	{
		_pFile->Seek(SEEK_SET, 0);
		A = *(owUINT32*)chain_values;
		B = *((owUINT32*)chain_values + 1);
		C = *((owUINT32*)chain_values + 2);
		D = *((owUINT32*)chain_values + 3);
		
		MD5BufferB * pMD5Buffer = MD5BufferB::MD5BufferForFile(_pFile);
		int8_t buff[64];
		while(!pMD5Buffer->Eof())
		{
			pMD5Buffer->Read(buff,64);
			this->Turn((owUINT32 *)&buff[0]);
		}
		pMD5Buffer->Release();
	}

}