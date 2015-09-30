#include "owAudio.h"
#include <memory.h>
#include <owcmn/owcmn.h>

namespace ow
{
	
	#define FRAME_BUFFER_TIME_MS 200
	
	size_t owAEVorbisRead( void * _pData, size_t _nElement, size_t _nCount, void * _pFile)
	{
		ow::owBuffer * pBuffer = (ow::owBuffer *)_pFile;
		return pBuffer->Read( _pData, _nCount * _nElement);
	}

	int owAEVorbisSeek( void * _pFile, ogg_int64_t _nOffset, int _flag )
	{
		ow::owBuffer * pBuffer = (ow::owBuffer *)_pFile;
		return pBuffer->Seek( _flag, _nOffset);
	}
	
	long owAEVorbisTell( void * _pFile)
	{
		ow::owBuffer * pBuffer = (ow::owBuffer *)_pFile;
		return pBuffer->GetCurr() - pBuffer->GetBuffer();
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
	}
	
	owVOID owAEBuffer::Release()
	{
		if( Valid() == owTRUE)
		{
			alDeleteBuffers(1, &m_iBuffer);
		}
		memset(this, 0, sizeof(owAEBuffer));
	}
	
	/***************************************************************
	 * 
	 * 
	 * 
	 * ************************************************************/
	 
	owVOID VorbisStruct::Clear()
	{
		// 清除缓冲区
		delete []this->m_pFrameBuffer;
		// 释放OGG文件缓冲
		this->m_pBuffer->Release();
		// 释放OGG文件对象
		ov_clear( &this->m_vorbisFile);
	}
	 
	owINT32 VorbisStruct::Size()
	{
		return ov_raw_total( &this->m_vorbisFile, -1 );
	}
	
	owINT32 VorbisStruct::Tell()
	{
		return ov_raw_tell( &this->m_vorbisFile);
	}
	 
	 owINT32 VorbisStruct::DecodeNextFrame()
	 {
		owINT32 size = 0;
		owINT32 result;
		owINT32 section;
		while(size< this->m_nFrameBufferSize)
		{
			result=ov_read(
			&this->m_vorbisFile,
			this->m_pFrameBuffer+size,
			this->m_nFrameBufferSize-size,
			0,
			2,
			1,
			&section
			);
			// 文件尾
			if(result == 0)
			{
				break;
			}
			// 正常读取
			else if( result > 0)
			{
				size=result+size;
			}
			// 发生错误
			else
			{
				assert( result != OV_HOLE && result != OV_EBADLINK && result != OV_EINVAL);
				break;
			}
		}
		return size;
	 }
	
	owBOOL VorbisStruct::Eof()
	{
		return ( this->Size() == this->Tell() );
	}
	
	owBOOL owAESource::Init()
	{
		__CLEAR_AL_ERROR__
		alGenSources( 1, &m_iSource);
		__CHECK_AL_ERROR__
	}
	
	owBOOL owAESource::Valid()
	{
		return alIsSource( m_iSource);
	}
	
	owVOID owAESource::Release()
	{
		if( Valid() )
		{
			this->m_pBuffer->Release();
			alDeleteSources( 1, &m_iSource );
		}
		memset( this, 0, sizeof( owAESource));
	}

	owVOID owAESource::Pause()
	{
		__CLEAR_AL_ERROR__
		alSourcePause( m_iSource);
		__CHECK_AL_ERROR__
	}

	owVOID owAESource::Play()
	{
		__CLEAR_AL_ERROR__
		alSourcePlay( m_iSource);
		__CHECK_AL_ERROR__
	}

	owVOID owAESource::SetBuffer(owAEBuffer* _pBuffer)
	{
		__CLEAR_AL_ERROR__
		alSourcei( m_iSource, AL_BUFFER, _pBuffer->m_iBuffer);
		this->m_pBuffer = _pBuffer;
		__CHECK_AL_ERROR__
	}

	owVOID owAESource::Stop()
	{
		__CLEAR_AL_ERROR__
		alSourceStop( m_iSource);
		__CHECK_AL_ERROR__
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

	/***********************************************************
	 * 
	 * 	AEVorbisSource
	 * 
	 * ********************************************************/

	owVOID ow::owAEVorbisSource::FillFirstCycle()
	{
		__CLEAR_AL_ERROR__
		owINT32 size;
		size = this->m_vorbis.DecodeNextFrame();
		alBufferData(
				this->m_vecBuffers[0],
				this->m_vorbis.m_iFormat,
				this->m_vorbis.m_pFrameBuffer,
				size,
				this->m_vorbis.m_pVorbisInfo->rate
				);
		size = this->m_vorbis.DecodeNextFrame();
		alBufferData(
				this->m_vecBuffers[1],
				this->m_vorbis.m_iFormat,
				this->m_vorbis.m_pFrameBuffer,
				size,
				this->m_vorbis.m_pVorbisInfo->rate
				);
		size = this->m_vorbis.DecodeNextFrame();
		alBufferData(
				this->m_vecBuffers[2],
				this->m_vorbis.m_iFormat,
				this->m_vorbis.m_pFrameBuffer,
				size,
				this->m_vorbis.m_pVorbisInfo->rate
				);
		alSourceQueueBuffers( m_iSource,3,&m_vecBuffers[0]);
		__CHECK_AL_ERROR__
	}
	
	owBOOL owAEVorbisSource::UpdateBuffer()
	{
		owINT32  num = 0;
		owINT32  size;
		ALuint bufferarray[3];
		// 取出播放完的buffer
		alGetSourcei(m_iSource,AL_BUFFERS_PROCESSED,&num);
		alSourceUnqueueBuffers(m_iSource,num,&bufferarray[0]);
		// 更新播放完的buffer
		for(int i=0;i<num;i++)
		{
			size=m_vorbis.DecodeNextFrame();
			alBufferData(
				bufferarray[i],
				this->m_vorbis.m_iFormat,
				this->m_vorbis.m_pFrameBuffer,
				size,
				this->m_vorbis.m_pVorbisInfo->rate
				);
		}
		// 将更新的buffer重新装载进source
		alSourceQueueBuffers(m_iSource,num,&bufferarray[0]);
	}

	owVOID ow::owAEVorbisSource::Init(owBuffer* _pBuffer)
	{
		// 从owBuffer读取OGG信息
		owUINT32 error;
		alGenSources( 1, &m_iSource);
		alGenBuffers( 3, &m_vecBuffers[0]);
		error = ov_open_callbacks( _pBuffer, &this->m_vorbis.m_vorbisFile,NULL,0,OW_CALLBACKS_VORBIS);
		if( error != 0)
		{
			assert(false);
			return;
		}
		// 读取信息与注释
		this->m_vorbis.m_pVorbisInfo = ov_info( &this->m_vorbis.m_vorbisFile, -1);
		this->m_vorbis.m_pVorbisComment = ov_comment( &this->m_vorbis.m_vorbisFile, -1);
		// 分析音频 format
		/******************************************************
			这里解释一下代码
			PCM数据大小计算 每秒大小 = 采样率 * 位宽 / 8 * 声道数
			位宽是16,声道数是1即
			rate * 16 / 8 * 1
			即 rate * 2 这是一秒的大小
			250ms对应的大小应该是rate / 2
			所以这里就是rate >> 1,位操作右移一位即可实现除2
			但是最后还有个block对齐,这里因为是单声道,16位,两个字节的对齐
		******************************************************/
		switch(this->m_vorbis.m_pVorbisInfo->channels)
		{
			// 单声道
			case 1:
				this->m_vorbis.m_iFormat=AL_FORMAT_MONO16;
				this->m_vorbis.m_nFrameBufferSize = this->m_vorbis.m_pVorbisInfo->rate * 2 * FRAME_BUFFER_TIME_MS / 1000.0f;
				break;
			// 双声道
			case 2:
				this->m_vorbis.m_iFormat=AL_FORMAT_STEREO16;
				this->m_vorbis.m_nFrameBufferSize = this->m_vorbis.m_pVorbisInfo->rate * 2 * FRAME_BUFFER_TIME_MS * 2 / 1000.0f;
				break;
			// 四声道
			case 4:
				this->m_vorbis.m_iFormat=alGetEnumValue("AL_FORMAT_QUAD16");
				this->m_vorbis.m_nFrameBufferSize = this->m_vorbis.m_pVorbisInfo->rate * 2 * FRAME_BUFFER_TIME_MS * 4 / 1000.0f;
				break;
			// 6声道
			case 6:
				this->m_vorbis.m_iFormat = alGetEnumValue("AL_FORMAT_51CHN16");
				this->m_vorbis.m_nFrameBufferSize = this->m_vorbis.m_pVorbisInfo->rate * 2 * FRAME_BUFFER_TIME_MS * 6 / 1000.0f;
				break;
			default:
				ov_clear(&m_vorbis.m_vorbisFile);
				return;
		}
		this->m_vorbis.m_pFrameBuffer = new owCHAR[ this->m_vorbis.m_nFrameBufferSize];
	}

	owVOID ow::owAEVorbisSource::Pause()
	{
		alSourcePause( m_iSource);
	}

	owVOID ow::owAEVorbisSource::Play()
	{
		alSourcePlay( m_iSource);
	}

	owVOID ow::owAEVorbisSource::Release()
	{
		alDeleteBuffers( 3, &this->m_vecBuffers[0]);
		alDeleteSources( 1, &this->m_iSource);
		this->m_vorbis.Clear();
	}

	owVOID ow::owAEVorbisSource::Stop()
	{
		alSourceStop( m_iSource);
		alDeleteSources(1,&m_iSource);
		alGenSources(1,&m_iSource);
		ov_time_seek(&this->m_vorbis.m_vorbisFile,0);
		FillFirstCycle();
	}
	
	
	owAEBuffer* ow::owAEDevice::CreateBuffer()
	{
		owAEBuffer * pBuffer = new owAEBuffer;
		pBuffer->Init();
		return pBuffer;
	}

	owAESource* ow::owAEDevice::CreateSource()
	{
		owAESource * pSource = new owAESource();
		pSource->Init();
		return pSource;
	}

	owAEVorbisSource* ow::owAEDevice::CreateVorbisSource( ow::owBuffer * _pVorbisBuffer )
	{
		owAEVorbisSource * pVorbisSource = new owAEVorbisSource();
		pVorbisSource->Init( _pVorbisBuffer);
		return pVorbisSource;
	}

	owBOOL ow::owAEDevice::Init()
	{
		__CLEAR_AL_ERROR__
		if(m_pContext == NULL)
		{
			this->m_pDevice = alcOpenDevice( NULL);
			this->m_pContext = alcCreateContext( m_pDevice, NULL);
		}
		__CHECK_AL_ERROR__
		return owTRUE;
	}

	owVOID ow::owAEDevice::Release()
	{
		alcDestroyContext( m_pContext);
		alcCloseDevice( m_pDevice);
		delete this;
	}

}





