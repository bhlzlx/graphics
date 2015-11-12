#ifndef __OW_AEPLAYER_H__
#define __OW_AEPLAYER_H__

#include "owAudio.h"
#include <pthread.h>
#include <queue>

namespace ow
{

	using namespace std;

	typedef enum
	{
		eAEPlay,
		eAEPause,
		eAEStop,
		eAEUnload,
		eAEDestroy,
		eAESetupSource,
		eAEIdle
	} MSGType;

	struct AEMSG
	{
		MSGType 	type;
		owVOID * 	ptr;
	};

	struct AEMessageQueue;



	struct owAEMusicPlayer
	{
	private:
		ow::owAEVorbisSource * 	m_pMusicSrc;
		pthread_t	    		m_thread_t;
		AEMessageQueue * 		m_pMsgQueue;
		AEMSG			 		m_state;
		
		pthread_cond_t 			m_waitCond;
		pthread_mutex_t 		m_waitMutex;

	private:
		void __Release();
		void __Play();
		void __Pause();
		void __Stop();
		void __Unload();
		void __SetupMusic( void * ptr );

		
	public:
		owAEMusicPlayer(void);
		~owAEMusicPlayer(void);
		bool Init();

		void SetupMusic( ow::owBuffer * _pFileBuffer );
		void Release();
		void Play();
		void Pause();
		void Stop();
		void Unload();
		MSGType GetState();
		
		
		static void * MusicThreadProc(void *);
	};



	struct AEMessageQueue
	{
		std::queue<AEMSG> m_msg_queue;
		pthread_mutex_t   m_msg_mutex;

		AEMSG			  m_state;

		AEMessageQueue();

		void Release();

		void PostMsg(AEMSG & msg);
		bool GetMsg(AEMSG &msg);
	};

}

#endif // __OW_AEPLAYER_H__
