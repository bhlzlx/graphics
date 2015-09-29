#include <al/al.h>
#include <al/alc.h>
#include <vorbis/vorbisfile.h>
#include <vorbis/vorbisenc.h>
#include <ogg/ogg.h>
#include <owcmn/owcmn.h>
#include <assert.h>
#include <owfile/owfile.h>

#define __CLEAR_AL_ERROR__ \
	alGetError();
#define __CHECK_AL_ERROR__ \
	assert ( alGetError() == AL_NO_ERROR );
	
typedef void (* AL_FLOAT_SETTER )(ALuint, ALenum, ALfloat);
typedef void (* AL_FLOAT_GETTER )(ALuint, ALenum, ALfloat *);
typedef void (* AL_INT32_SETTER )(ALuint, ALenum, ALint);
typedef void (* AL_INT32_GETTER )(ALuint, ALenum, ALint *);
typedef void (* AL_INT32_VEC_SETTER )(ALuint, ALenum, const ALint *);
typedef void (* AL_FLOAT_VEC_SETTER )(ALuint, ALenum, const ALfloat *);

	
#define AL_SOURCE_GET_SET_DEF( TYPE, PARAM ) \
	TYPE Get_##PARAM(); \
	owVOID Set_##PARAM( TYPE );

#define AL_SOURCE_GET_SET_IMP( SPACE , TYPE, PARAM )\
	TYPE SPACE::Get_##PARAM(){ \
		static TYPE value;\
		owAESourceGetter_##TYPE( m_iSource, AL_##PARAM, &value);\
		return value;\
	}\
	owVOID SPACE::Set_##PARAM( TYPE value){\
		owAESourceSetter_##TYPE(m_iSource, AL_##PARAM, value);\
	}\
	
#define AL_SOURCE_GET_SET_VEC_DEF( TYPE, PARAM ) \
	owVOID Get_##PARAM( TYPE * ); \
	owVOID Set_##PARAM( TYPE * );

#define AL_SOURCE_GET_SET_VEC_IMP( SPACE , TYPE, PARAM )\
	owVOID SPACE::Get_##PARAM( TYPE * _pValue){\
		owAESourceSetter_vec_##TYPE( m_iSource, AL_##PARAM, _pValue);\
	}\
	owVOID SPACE::Set_##PARAM( TYPE * _pValue){\
		owAESourceGetter_vec_##TYPE( m_iSource, AL_##PARAM, _pValue);\
	}\

namespace ow	
{	
	struct owAEBuffer
	{
		owUINT32		m_iBuffer;
		owINT32 		m_nDepthBit;
		owINT32 		m_nChannels;
		owINT32 		m_nSize;
		owINT32 		m_nFrequency;
		
		owBOOL Init();
		owVOID BufferData( 
					owINT32 _format, 
					const owVOID * _pData, 
					owINT32 _size, 
					owINT32 _freq 
					);
		owBOOL Valid();
		
		owINT32 GetFrequency();
		owINT32 GetDepthBits();
		owINT32 GetChannels();
		owINT32 GetSize();
		~owAEBuffer();
	};	
	
	struct owAESource
	{
		owUINT32		m_iSource;
		owAEBuffer		m_pBuffer;
		
		owBOOL Init();
		
		owVOID Play();
		owVOID Stop();
		owVOID Pause();
		owVOID SetBuffer( owAEBuffer * _pBuffer );
		
		owVOID SetFloat( float* _pValue, owINT32 _attr);
		owVOID SetInt( int* _pValue, owINT32 _attr);
		owVOID GetFloat( float * _pValue, owINT32 _attr);
		owVOID GetInt( int * _pValue, owINT32 _attr);
		
		AL_SOURCE_GET_SET_DEF( float, PITCH)
		AL_SOURCE_GET_SET_DEF( float, GAIN)
		AL_SOURCE_GET_SET_DEF( float, MAX_DISTANCE)
		AL_SOURCE_GET_SET_DEF( float, ROLLOFF_FACTOR)
		AL_SOURCE_GET_SET_DEF( float, REFERENCE_DISTANCE)
		AL_SOURCE_GET_SET_DEF( float, MIN_GAIN)
		AL_SOURCE_GET_SET_DEF( float, MAX_GAIN)
		AL_SOURCE_GET_SET_DEF( float, CONE_OUTER_GAIN)
		AL_SOURCE_GET_SET_DEF( float, CONE_INNER_ANGLE)
		AL_SOURCE_GET_SET_DEF( float, CONE_OUTER_ANGLE)
		AL_SOURCE_GET_SET_DEF( float, SEC_OFFSET)
		AL_SOURCE_GET_SET_DEF( float, BYTE_OFFSET)
		
		AL_SOURCE_GET_SET_DEF( int, SOURCE_RELATIVE)
		AL_SOURCE_GET_SET_DEF( int, SOURCE_TYPE);
		AL_SOURCE_GET_SET_DEF( int, LOOPING);
		AL_SOURCE_GET_SET_DEF( int, BUFFER);
		AL_SOURCE_GET_SET_DEF( int, SOURCE_STATE);
		AL_SOURCE_GET_SET_DEF( int, BUFFERS_QUEUED);
		AL_SOURCE_GET_SET_DEF( int, BUFFERS_PROCESSED);
		
		AL_SOURCE_GET_SET_VEC_DEF( float, POSITION);
		AL_SOURCE_GET_SET_VEC_DEF( float, VELOCITY);
		AL_SOURCE_GET_SET_VEC_DEF( float, DIRECTION);
	};
	
	struct VorbisStruct
	{
		// vorbis数据源
		ow::IBuffer			m_pBuffer;
		// vorbis对象
		OggVorbis_File		m_pVorbisFile;
		// vorbis文件信息
		vorbis_info*		m_pVorbisInfo;
		// vorbis脚注
	    vorbis_comment*		m_pVorbisComment;
		// AL 格式
		owINT32				m_iFormat;
		// PCM 解码数据缓冲区
		owBYTE*				m_pFrameBuffer;
	};
	
	struct owAEVorbisSource
	{
		owUINT32		m_vecBuffers[3];	// 三个buffer轮循
		owUINT32		m_iSource;			// source 对象
		VorbisStruct	m_vorbis;
		
		owVOID Init( IBuffer * _pBuffer);
		owVOID Play();
		owVOID Stop();
		owVOID Pause();
		owVOID Release();
	private:
		owVOID FillFirstCycle();
	}
	
	struct owAEDevice
	{
		static ALCdevice *			m_pDevice;
		static ALCcontext *			m_pContext;
		
		
	}
	
};