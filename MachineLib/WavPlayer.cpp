/**
 * \file WavPlayer.cpp
 *
 * \author Charles Owen
 */

#include "stdafx.h"

#include <xaudio2.h>
#pragma comment(lib,"xaudio2.lib")

#include "WavPlayer.h"
#include "WavChannel.h"

using namespace std;

/**
 * Class to create a player for audio files. 
 *
 * One object of this type must be instantiated and then
 * used to create audio channels that actually play the audio
 * files.
 */
CWavPlayer::CWavPlayer()
{
	//
	// Initialize XAudio2
	//
	CoInitializeEx(nullptr, COINIT_MULTITHREADED);

	UINT32 flags = 0;
#if (_WIN32_WINNT < 0x0602 /*_WIN32_WINNT_WIN8*/) && defined(_DEBUG)
	flags |= XAUDIO2_DEBUG_ENGINE;
#endif
	HRESULT hr = XAudio2Create(&mIXAudio2, flags);
	if (FAILED(hr))
	{
		AfxMessageBox(L"Failed to initialize XAudio2 engine.");
		CoUninitialize();
		mIXAudio2 = nullptr;
		return;
	}

#if (_WIN32_WINNT >= 0x0602 /*_WIN32_WINNT_WIN8*/) && defined(_DEBUG)
	// To see the trace output, you need to view ETW logs for this application:
	//    Go to Control Panel, Administrative Tools, Event Viewer.
	//    View->Show Analytic and Debug Logs.
	//    Applications and Services Logs / Microsoft / Windows / XAudio2. 
	//    Right click on Microsoft Windows XAudio2 debug logging, Properties, then Enable Logging, and hit OK 
	XAUDIO2_DEBUG_CONFIGURATION debug = { 0 };
	debug.TraceMask = XAUDIO2_LOG_ERRORS | XAUDIO2_LOG_WARNINGS;
	debug.BreakMask = XAUDIO2_LOG_ERRORS;
	mIXAudio2->SetDebugConfiguration(&debug, 0);
#endif

	//
	// Create a mastering voice
	//
	IXAudio2MasteringVoice* pMasteringVoice = nullptr;

	if (FAILED(hr = mIXAudio2->CreateMasteringVoice(&pMasteringVoice)))
	{
		AfxMessageBox(L"Failed to initialize XAudio2 engine.");
		mIXAudio2->Release();
		mIXAudio2 = nullptr;
		CoUninitialize();
		mIXAudio2 = nullptr;
		return;
	}
}

/**
 * Destructor
 */
CWavPlayer::~CWavPlayer()
{
	//
	// Ensure the resources used by the 
	// channels are all cleared, even if 
	// some other object holds a pointer 
	// to a channel.
	//
	for (auto channel : mChannels)
	{
		channel->Kill();
	}

	mChannels.clear();

	if (mIXAudio2 != nullptr)
	{
		mIXAudio2->Release();
		mIXAudio2 = nullptr;
	}
	CoUninitialize();
}


/**
 * Create an audio playback channel associated with this player.
 * \param audiofile Filename for the audio file to play
 * \return Allocated CWavChannel object.
 */
std::shared_ptr<CWavChannel> CWavPlayer::CreateChannel(std::wstring audiofile)
{
	auto channel = make_shared<CWavChannel>(this, audiofile);
	mChannels.push_back(channel);

	return channel;
}
