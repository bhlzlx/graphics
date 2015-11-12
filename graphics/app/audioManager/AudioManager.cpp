#include "AudioManager.h"
#include <cmn/log/logger.h>
#include <cmn/resources.h>
#include <archive/owArchive.h>
#include <excel/excel_def.h>

using namespace ow::excel;
using namespace ow;

namespace app
{
	ow::owFile * SoundFileForId( owINT32 _id )
	{
		l_Sound * pLine = t_Sound.GetLineById( _id);
		if(pLine == NULL)
		{
			return NULL;
		}
		char * path = pLine->szPath;
		owFile * pFile = ow::GetArchive()->Open(path);
		return pFile;
	}

	ow::owFile * MusicFileForId( owINT32 _id )
	{
		l_Music * pLine = t_Music.GetLineById( _id);
		if(pLine == NULL)
		{
			return NULL;
		}
		char * path = pLine->szPath;
		owFile * pFile = ow::GetArchive()->Open(path);
		return pFile;
	}

	/************************************************************
	 *  Audio Cache
	 ***********************************************************/
	ow::owAEBuffer * AudioCache::FindBuffer( owINT32 _id )
	{
		owAEBufferCache::iterator iter = this->m_bufferCache.find( _id );
		if(iter == m_bufferCache.end())
		{
			return NULL;
		}
		else
		{
			return iter->second;
		}
	}

	owVOID AudioCache::InsertBuffer( owINT32 _id, ow::owAEBuffer * _pBuffer )
	{
		m_bufferCache[_id] = _pBuffer;
	}

	ow::owAESource * AudioCache::FindSource( owINT32 _id )
	{
		// 先找有没有此队列，如果有此队列找一下队列里有没有空闲的，有空闲的就返回，没有空闲的就返回NULL
		owAESourceCache::iterator iter = this->m_sourceCache.find( _id );
		if(iter == m_sourceCache.end() )
		{
			return NULL;
		}
		else
		{
			owAESourceArray * sourceArray = iter->second;
			for( ow::owAESource * pSource: *sourceArray)
			{
				int sourceState = pSource->Get_SOURCE_STATE();
				if(sourceState == AL_STOPPED)
				{
					return pSource;
				}
			}
			return NULL;
		}
	}

	owVOID AudioCache::InsertSource( owINT32 _id, ow::owAESource * _pSource )
	{
		// 检查有没有对应的数组对象，如果没有，则需要创建一个对象
		assert( _pSource->Valid() == owTRUE );
		owAESourceCache::iterator iter = this->m_sourceCache.find( _id );
		if(iter == m_sourceCache.end() )
		{
			m_sourceCache[_id] = new owAESourceArray;
			m_sourceCache[_id]->push_back( _pSource);
		}
		else
		{
			iter->second->push_back( _pSource);
		}
	}

	owVOID AudioCache::Clear()
	{
		// 清空source的map
		for( owAESourceCache::value_type & value: m_sourceCache)
		{
			// 释放buffer array
			owAESourceArray * sourceArray = value.second;
			for(owAESourceArray::value_type pSource : *sourceArray)
			{
				// 释放source对象
				pSource->Release();
			}
			sourceArray->clear();
			delete sourceArray;
		}
		m_sourceCache.clear();

		// 清空buffer的map
		for( owAEBufferCache::value_type & value: m_bufferCache )
		{
			// 释放掉buffer数据
			value.second->Release();
		}
		m_bufferCache.clear();
	}

	AudioCache::~AudioCache()
	{
		this->Clear();
	}

	/*************************************************
	 * 	Audio Manager
	 * **********************************************/

	AudioManager::AudioManager()
	{
		m_pAudioDevice = NULL;
		m_pMusicPlayer = NULL;
		m_iMusicId = 0xffffffff;
	}

	AudioManager::~AudioManager()
	{

	}

	void AudioManager::PlaySound2D( owINT32 _id, owFLOAT _volume, owBOOL _bLoop )
	{
		ow::owAESource * pSource = this->m_soundCache.FindSource( _id);
		if(pSource == NULL)
		{
			ow::owAEBuffer * pBuffer = this->m_soundCache.FindBuffer( _id);
			if(pBuffer == NULL)
			{
				ow::owMemFile * pFile = (ow::owMemFile *)SoundFileForId( _id);
				if(pFile == NULL)
				{
					ow::Logger::GetInstance(NULL)->Write("invalid sound id : %d", _id);
					return;
				}
				else
				{
					pBuffer = ow::GetAudioDevice()->CreateBufferVorbis( pFile->m_pMemBuffer);
					m_soundCache.InsertBuffer( _id, pBuffer);
				}
			}
			pSource = ow::GetAudioDevice()->CreateSource();
			pSource->SetBuffer( pBuffer);
			pSource->Set_MIN_GAIN( 0.0f);
			pSource->Set_MAX_GAIN( 10.0f);
			pSource->Set_GAIN( _volume );
			pSource->Set_MAX_DISTANCE( m_pAudioDevice->GetReferenceDistanceMax() );
		}
		owFLOAT vecPos[3];
		ow::GetAudioDevice()->GetListenerPosition(&vecPos[0]);
		pSource->Set_POSITION(&vecPos[0]);
		pSource->Set_LOOPING(_bLoop);
		pSource->Play();
	}

	void AudioManager::PlaySound3D( owINT32 _id, owFLOAT _x, owFLOAT _y, owFLOAT _z, owFLOAT _volume, owBOOL _bLoop )
	{
		ow::owAESource * pSource = this->m_soundCache.FindSource( _id);
		if(pSource == NULL)
		{
			ow::owAEBuffer * pBuffer = this->m_soundCache.FindBuffer( _id);
			if(pBuffer == NULL)
			{
				owFile* pFile = SoundFileForId( _id);
				if(pFile == NULL)
				{
					ow::Logger::GetInstance(NULL)->Write("invalid sound id : %d", _id);
					return;
				}
				else
				{
					pBuffer = ow::GetAudioDevice()->CreateBufferVorbis( pFile->GetBuffer());
					m_soundCache.InsertBuffer( _id, pBuffer);
				}
			}
			pSource = ow::GetAudioDevice()->CreateSource();
			pSource->SetBuffer( pBuffer);
			pSource->Set_MIN_GAIN( 0.0f);
			pSource->Set_MAX_GAIN( 10.0f);
			pSource->Set_GAIN( _volume );
			pSource->Set_MAX_DISTANCE( m_pAudioDevice->GetReferenceDistanceMax() );
		}
		owFLOAT vecPos[3] = { _x, _y, _z };
		pSource->Set_POSITION(&vecPos[0]);
		pSource->Set_LOOPING(_bLoop);
		pSource->Play();
	}

	void AudioManager::SetReferenceDistanceMax( owFLOAT _fDistance )
	{
		this->m_pAudioDevice->SetReferneceDistanceMax( _fDistance);
	}

	void AudioManager::PlayMusic( owINT32 _id, owFLOAT _volume )
	{
		// 判断当前音乐播放状态
		if(m_iMusicId == _id)
		{
			if(m_pMusicPlayer->GetState() == ow::eAEPlay )
			{
				return;
			}
			else
			{
				m_pMusicPlayer->Play();
			}
		}
		else
		{
			ow::owMemFile * pFile = (ow::owMemFile *)MusicFileForId( _id );
			if(pFile)
			{
				ow::owBuffer * strongBuffer = ow::CreateMemBuffer( pFile->GetBuffer()->Size());
				strongBuffer->Write( pFile->GetBuffer()->GetBuffer(), pFile->GetBuffer()->Size() );
				strongBuffer->Seek( SEEK_SET, 0);
				pFile->Release();
				this->m_pMusicPlayer->SetupMusic( strongBuffer );
				this->m_pMusicPlayer->Play();
				m_iMusicId = _id;
			}
			else
			{
				ow::Logger::GetInstance(NULL)->Write("invalid music id : %d", _id);
			}
		}
	}

	owBOOL AudioManager::Init()
	{
		this->m_pAudioDevice = ow::GetAudioDevice();
		if(m_pAudioDevice == NULL)
		{
			return owFALSE;
		}
		m_pAudioDevice->SetReferneceDistanceMax( 100.0f );
		this->m_pMusicPlayer = new ow::owAEMusicPlayer();
		m_pMusicPlayer->Init();
		m_iMusicId = 0xffffffff;
		return owTRUE;
	}

	owVOID AudioManager::Release()
	{
		/*
		 * m_pMusicPlayer调用的方法全部都是异步的，
		 * 但是 m_pAudioDevice 却是同步的，就是说m_pAudioDevice执行完，
		 * m_pMusicPlayer还没销毁，因为导致内存泄漏，但是一般程序退出才会执行此处
		 * 所以，不需要特别在意，最完美的方法是将audiodevice也改为异步的
		 * audio 相关的销毁了再终止程序
		 */
		if(m_pMusicPlayer)
		{
			m_pMusicPlayer->Release();
		}
		if(m_pAudioDevice)
		{
			m_pAudioDevice->Release();
		}
		delete this;
	}

	AudioManager * __AudioManager = NULL;

	AudioManager * GetAudioManager()
	{
		if( __AudioManager == NULL)
		{
			__AudioManager = new AudioManager();
			if( __AudioManager->Init() != owTRUE)
			{
				__AudioManager->Release();
				__AudioManager = NULL;
			}
		}
		return __AudioManager;
	}

}
