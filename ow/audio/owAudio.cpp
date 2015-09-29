#include "owAudio.h"
#include <memory.h>

namespace ow
{
	
	/*
  static ov_callbacks OV_CALLBACKS_DEFAULT = {
  (size_t (*)(void *, size_t, size_t, void *))  fread,
  (int (*)(void *, ogg_int64_t, int))           _ov_header_fseek_wrap,
  (int (*)(void *))                             fclose,
  (long (*)(void *))                            ftell
};

 */
	size_t owAEVorbisRead( void * _pData, size_t _nElement, size_t _nCount, void * _pFile)
	{
		ow::IBuffer * pBuffer = (ow::IBuffer *)_pFile;
		return pBuffer->Read( _pData, 1, _nCount);
	}

	int owAEVorbisSeek( void * _pFile, ogg_int64_t _nOffset, int _flag )
	{
		ow::IBuffer * pBuffer = (ow::IBuffer *)_pFile;
		return pBuffer->Seek( _flag, _nOffset);
	}
	
	long owAEVorbisTell( void * _pFile)
	{
		ow::IBuffer * pBuffer = (ow::IBuffer *)_pFile;
		return pBuffer->Tell();
	}
	
	static ov_callbacks OW_CALLBACKS_VORBIS = {
		(size_t (*)(void *, size_t, size_t, void *))  owAEVorbisRead,
		(int (*)(void *, ogg_int64_t, int))           owAEVorbisSeek,
		(int (*)(void *))                             NULL,
		(long (*)(void *))                            owAEVorbisTell
	};
	
	AL_FLOAT_GETTER owAESourceGetter_float = alGetSourcef;
	AL_FLOAT_SETTER owAESourceSetter_float = alSourcef;
	AL_FLOAT_VEC_SETTER owAESourceSetter_vec_float = alSourcefv;
	AL_FLOAT_GETTER owAESourceGetter_vec_float = alGetSourcefv;

	AL_INT32_GETTER owAESourceGetter_int = alGetSourcei;
	AL_INT32_SETTER owAESourceSetter_int = alSourcei;
	AL_INT32_VEC_SETTER owAESourceSetter_vec_int = alSourceiv;
	AL_INT32_GETTER owAESourceGetter_vec_int = alGetSourceiv;

	owVOID owAEBuffer::BufferData(owINT32 _format, const owVOID* _pData, owINT32 _size, owINT32 _freq)
	{
		__CLEAR_AL_ERROR__
		alBufferData( m_iBuffer, _format, _pData, _size, _freq);
		__CHECK_AL_ERROR__
	}

	owINT32 owAEBuffer::GetChannels()
	{
		return this->m_nChannels;
	}

	owINT32 owAEBuffer::GetDepthBits()
	{
		return this->m_nFrequency;
	}

	owINT32 owAEBuffer::GetFrequency()
	{
		return this->m_nFrequency;
	}

	owINT32 owAEBuffer::GetSize()
	{
		return this->m_nSize;
	}

	owBOOL owAEBuffer::Init()
	{
		__CLEAR_AL_ERROR__
		alGenBuffers(1, &this->m_iBuffer);
		__CHECK_AL_ERROR__
		return owTRUE;
	}

	owBOOL owAEBuffer::Valid()
	{
		return alIsBuffer( m_iBuffer);
	}
	
	owAEBuffer::~owAEBuffer()
	{
		if( Valid() == owTRUE)
		{
			alDeleteBuffers(1, &m_iBuffer);
		}
		memset(this, 0, sizeof(owAEBuffer));
	}
	
	owVOID owAESource::SetFloat( float* _pValue, owINT32 _attr)
	{
		alSourcefv( m_iSource, _attr, _pValue);
	}
	
	owVOID owAESource::SetInt( int* _pValue, owINT32 _attr)
	{
		alSourceiv( m_iSource, _attr, _pValue);
	}
	
	owVOID owAESource::GetFloat( float * _pValue, owINT32 _attr)
	{
		alGetSourcefv( m_iSource, _attr, _pValue);
	}
	
	owVOID owAESource::GetInt( int * _pValue, owINT32 _attr)
	{
		alGetSourceiv( m_iSource, _attr, _pValue);
	}
	
	AL_SOURCE_GET_SET_IMP( owAESource, float, PITCH)
	AL_SOURCE_GET_SET_IMP( owAESource, float, GAIN)
	AL_SOURCE_GET_SET_IMP( owAESource, float, MAX_DISTANCE)
	AL_SOURCE_GET_SET_IMP( owAESource, float, ROLLOFF_FACTOR)
	AL_SOURCE_GET_SET_IMP( owAESource, float, REFERENCE_DISTANCE)
	AL_SOURCE_GET_SET_IMP( owAESource, float, MIN_GAIN)
	AL_SOURCE_GET_SET_IMP( owAESource, float, MAX_GAIN)
	AL_SOURCE_GET_SET_IMP( owAESource, float, CONE_OUTER_GAIN)
	AL_SOURCE_GET_SET_IMP( owAESource, float, CONE_INNER_ANGLE)
	AL_SOURCE_GET_SET_IMP( owAESource, float, CONE_OUTER_ANGLE)
	AL_SOURCE_GET_SET_IMP( owAESource, float, SEC_OFFSET)
	AL_SOURCE_GET_SET_IMP( owAESource, float, BYTE_OFFSET)
	
	AL_SOURCE_GET_SET_IMP( owAESource, int, SOURCE_RELATIVE)
	AL_SOURCE_GET_SET_IMP( owAESource, int, SOURCE_TYPE);
	AL_SOURCE_GET_SET_IMP( owAESource, int, LOOPING);
	AL_SOURCE_GET_SET_IMP( owAESource, int, BUFFER);
	AL_SOURCE_GET_SET_IMP( owAESource, int, SOURCE_STATE);
	AL_SOURCE_GET_SET_IMP( owAESource, int, BUFFERS_QUEUED);
	AL_SOURCE_GET_SET_IMP( owAESource, int, BUFFERS_PROCESSED);
	
	AL_SOURCE_GET_SET_VEC_IMP( owAESource, float, POSITION);
	AL_SOURCE_GET_SET_VEC_IMP( owAESource, float, VELOCITY);
	AL_SOURCE_GET_SET_VEC_IMP( owAESource, float, DIRECTION);

}