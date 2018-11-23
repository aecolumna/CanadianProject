/**
 * \file WavChannel.cpp
 *
 * \author Charles Owen
 */

#include "stdafx.h"

#include <xaudio2.h>

#include "WavChannel.h"
#include "WavPlayer.h"

using namespace std;

/**
 * Constructor
 * \param player The player this channel is associated with
 * \param audiofile The filename for the audio file to load into this channel.
 */
CWavChannel::CWavChannel(CWavPlayer *player, std::wstring audiofile) : mPlayer(player)
{
	//
	// Read in the wave file
	//
	HRESULT hr;
	if (FAILED(hr = DirectX::LoadWAVAudioFromFileEx(audiofile.c_str(), mWaveFile, mWaveData)))
	{
		wstring msg = L"Failed reading WAV file: ";
		msg += audiofile;
		AfxMessageBox(msg.c_str());
		return;
	}

	if (FAILED(hr = mPlayer->GetIXAudio()->CreateSourceVoice(&mSourceVoice, mWaveData.wfx)))
	{
		AfxMessageBox(L"Error creating audio source voice");
		return;
	}

	mBuffer = make_shared<XAUDIO2_BUFFER>();

	// Submit the wave sample data using an XAUDIO2_BUFFER structure
	*mBuffer = { 0 };
	mBuffer->pAudioData = mWaveData.startAudio;
	mBuffer->Flags = XAUDIO2_END_OF_STREAM;  // tell the source voice not to expect any data after this buffer
	mBuffer->AudioBytes = mWaveData.audioBytes;

	if (mWaveData.seek)
	{
		AfxMessageBox(L"This platform does not support xWMA or XMA2");
		mSourceVoice->DestroyVoice();
		mSourceVoice = nullptr;
		return;
	}


}

/**
 * Destructor
 */
CWavChannel::~CWavChannel()
{
	Kill();
}


/**
 * Play the audio file on this channel.
 */
void CWavChannel::Play()
{
	if (mSourceVoice != nullptr)
	{
		if (mStarted)
		{
			mSourceVoice->Stop(0);
			mSourceVoice->FlushSourceBuffers();
			mStarted = false;
		}

		HRESULT hr;

		if (FAILED(hr = mSourceVoice->SubmitSourceBuffer(mBuffer.get())))
		{
			AfxMessageBox(L"Error submitting source buffer");
			mSourceVoice->DestroyVoice();
			mSourceVoice = nullptr;
			return;
		}

		mSourceVoice->Start(0);
		mStarted = true;
	}
}

/**
 * Kill all playback on this channel. 
 *
 * This is done prior to destruction if the player is destroyed first.
 */
void CWavChannel::Kill()
{
	if (mSourceVoice != nullptr)
	{
		mSourceVoice->Stop();
		mSourceVoice = nullptr;
	}
}
