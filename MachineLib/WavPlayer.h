/**
 * \file WavPlayer.h
 * 
 * Class that plays WAV files. Unique in that it can play many at a time.
 */

#pragma once

#include <memory>
#include <string>
#include <vector>

class CWavChannel;
struct IXAudio2;

/**
 * Class that plays WAV files. Unique in that it can play many at a time.
 *
 * Call CreateChannel with an .wav audio filename to set the file to create
 * a channel that can play a sound.
 */
class CWavPlayer
{
public:
	CWavPlayer();
	virtual ~CWavPlayer();

	/** \brief Copy constructor disabled */
	CWavPlayer(const CWavPlayer &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CWavPlayer &) = delete;

	std::shared_ptr<CWavChannel> CreateChannel(std::wstring audiofile);

	/// Get a pointer to the underlying IXAudio2 object
	/// \return Pointer to IXAudio2 object
	IXAudio2 *GetIXAudio() { return mIXAudio2; }

private:
	/// The IXAudio2 object
	IXAudio2 *mIXAudio2 = nullptr;

	/// All installed audio channels
	std::vector<std::shared_ptr<CWavChannel>> mChannels;
};

