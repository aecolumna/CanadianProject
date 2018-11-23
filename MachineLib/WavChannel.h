/**
 * \file WavChannel.h
 * Class that represents one channel that can play WAV files.
 */

#pragma once

#include <memory>
#include <string>
#include <vector>

#include "WAVFileReader.h"

class CWavPlayer;
struct IXAudio2SourceVoice;
struct XAUDIO2_BUFFER;

/**
 * Class that represents one channel that can play WAV files.
 */
class CWavChannel
{
public:
	CWavChannel(CWavPlayer *player, std::wstring audiofile);
	~CWavChannel();

	/** \brief Default constructor disabled */
	CWavChannel() = delete;
	/** \brief Copy constructor disabled */
	CWavChannel(const CWavChannel &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CWavChannel &) = delete;

	void Play();
	void Kill();

private:
	/// The player we are associated with
	CWavPlayer *mPlayer;

	/// Voice that will play this audio.
	IXAudio2SourceVoice* mSourceVoice = nullptr;

	/// The underlying audio samples for the wave we are playing
	std::unique_ptr<uint8_t[]> mWaveFile;

	/// Data that describes the WAVE file we are playing 
	DirectX::WAVData mWaveData;

	/// The audio streaming buffer
	std::shared_ptr<XAUDIO2_BUFFER> mBuffer;

	/// True if playback has been started
	bool mStarted = false;
};

