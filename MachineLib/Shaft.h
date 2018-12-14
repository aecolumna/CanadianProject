/**
 * \file Shaft.h
 *
 * \author Andres Columna
 *
 * 
 */


#pragma once
#include "Component.h"
#include "RotationSink.h"
#include "RotationSource.h"
#include "Shape.h"
#include "WavChannel.h"


/**
 * Represents a shaft
 */
class CShaft : public CComponent
{
public:
	CShaft();
	virtual void Draw(Gdiplus::Graphics * graphics) override;
	CShaft(int x, int y);
	virtual ~CShaft();

	void UpdatePosition(double angle);

	virtual void UpdateRotation(double angle) override;

	/// Copy constructor/disabled
	CShaft(const CShaft &) = delete;

	/// Assignment operator/disabled
	void operator=(const CShaft &) = delete;

	/// Get the radius of the polygon
	/// \return Double radius
	double GetRadius() { return mRadius; }

	void SetSourceRadius(double rad);

	/// Set audio channel
	/// \param channel Rotation in turns, where 0-1 is one revolution.
	void SetAudioChannel(std::shared_ptr<CWavChannel>& channel) { mWavChannel = channel; }

	/// Set random seed
	/// \param x Rotation in turns, where 0-1 is one revolution.
	void SetRand(double x) { mRand = x; }
	

	


private:
	/// Rotation source
	CRotationSource mSource;
	/// Rotation sink
	CRotationSink mSink;
	/// Radius of our shaft
	double mRadius = 30;
	/// radius of the source of our radius
	double mSourceRadius = 1;
	/// whether shaft is attached
	bool mAttached = false;
	/// the original y value of this
	double mOriginalY = 0; // keep
	/// Play music
	std::shared_ptr<CWavChannel> mWavChannel;
	/// Rand seed
	double mRand = 1.0;

};

