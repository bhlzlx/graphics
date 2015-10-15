#ifndef __APP_AUDIO_MANAGER_H__
#define __APP_AUDIO_MANAGER_H__

#include <audio/owAudio.h>
#include <audio/owAEPlayer.h>
#include <map>
#include <vector>

typedef std::map< owINT32, ow::owAEBuffer* > owAEBufferCache;

typedef std::vector< ow::owAESource* > owAESourceArray;
typedef std::map< owINT32, owAESourceArray *> owAESourceCache;

namespace app
{
	struct AudioCache
	{
		// audio 模块的资源缓冲
		owAEBufferCache			m_bufferCache;		// openal buffer 缓冲
		owAESourceCache			m_sourceCache;		// openal source 对象管理，source可共用同个buffer,所以资源需要分别管理
		
		ow::owAEBuffer * FindBuffer( owINT32 _id );
		owVOID InsertBuffer( owINT32 _id, ow::owAEBuffer * _pBuffer );
		
		ow::owAESource * FindSource( owINT32 _id );
		owVOID InsertSource( owINT32 _id, ow::owAESource * _pSource );

		owVOID Clear();
		
		~AudioCache();
	};
	
	class AudioManager
	{
	public:
		AudioManager();
		~AudioManager();
		
		ow::owAEDevice *		m_pAudioDevice;
		
		ow::owAEMusicPlayer * 	m_pMusicPlayer;
		owINT32 				m_iMusicId;
		AudioCache				m_soundCache;
		
		void PlaySound2D( owINT32 _id, owFLOAT _volume, owBOOL _bLoop = owFALSE );
		void PlaySound3D( owINT32 _id, owFLOAT _x, owFLOAT _y, owFLOAT _z, owFLOAT _volume, owBOOL _bLoop = owFALSE);
		void PlayMusic( owINT32 _id, owFLOAT _volume);
		
		void SetReferenceDistanceMax( owFLOAT _fDistance );
		
		owBOOL Init();
		owVOID Release();
	};
	
	AudioManager * GetAudioManager();

}

#endif // __APP_AUDIO_MANAGER_H__
