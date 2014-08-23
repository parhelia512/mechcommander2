#pragma once
//===========================================================================//
// File:	 Sound DS3DChannel.cpp 											 //
// Contents: Direct Sound Channel											 //
//---------------------------------------------------------------------------//
// Copyright (C) Microsoft Corporation. All rights reserved.                 //
//===========================================================================//

//
// Maximum number of available channels;
//
class DS3DSoundChannel
{
	public:
		LPDIRECTSOUNDBUFFER m_Buffer;
		LPDIRECTSOUND3DBUFFER m_Buffer3D;
		DSBCAPS m_dsbCaps;
		DS3DBUFFER m_Attributes3D;

		float m_fVolume, m_fPanning, m_fFrequency;
		ULONG m_currentProperties;
		ULONG m_oldProperties;
		SoundResource * m_currentSoundResource;
		bool m_true3D;
		bool m_changed;
		bool m_sysPause;

		ULONG m_previousPlayPosition;
		ULONG m_playPosition;

		bool m_bLoopFlag;
	    bool m_fCued;                  // semaphore (stream cued)
		bool m_fPlaying;               // semaphore (stream playing)
		bool m_fPaused;               // semaphore (stream playing)
	    UINT m_cbBufOffset;            // last write position
	    UINT m_nBufLength;             // length of sound buffer in msec
	    UINT m_cbBufSize;              // size of sound buffer in bytes
	    float m_fDuration;              // duration of wave file
		ULONG m_myEnum;
		bool playPending;

		bool bIsDuplicate;
		bool bOnly2D;

		gosAudio_ResourceType m_resourceType;
		char m_resourceName[128];

	public:
		DS3DSoundChannel();
		~DS3DSoundChannel();
		void Reset(ULONG chan);
		void CreateAndLoadBuffer( SoundResource * );
		void CreateStreamBuffer( SoundResource * );
		void CreateBuffer();
		void Play();
		void Pause();
		void Stop();
		void ClearAndFree();
		void PlayStream();
		void PauseStream();
		void StopStream();
		void Cue();
		void WriteWaveData(UINT size);
		ULONG GetMaxWriteSize();
		BOOL ServicePlayList();
		void SetVolume(float f);
		void SetPan(float f);
		void SetFrequency(float f);
		void SetPosition(float x, float y, float z);
		void SetVelocity(float x, float y, float z);
		void SetDistanceMinMax(float min, float max);
		bool IsPlaying();
		ULONG GetBytesPlayed();
		void SpewCaps();
		void ReturnFormattedDebugData( PSTR  dst, ULONG maxlen );
		void SetConeAngles( ULONG min, ULONG max );
		void SetConeOrientation( float x, float y, float z );
		void SetAllParameters();
		void ReleaseCurrent();
};

