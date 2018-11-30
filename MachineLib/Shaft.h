#pragma once
#include "Component.h"
#include "RotationSink.h"
#include "RotationSource.h"
#include "Shape.h"
#include "WavChannel.h"

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

	double GetRadius() { return mRadius; }

	void SetSourceRadius(double rad);

	void SetAudioChannel(std::shared_ptr<CWavChannel>& channel) { mWavChannel = channel; }

	void SetRand(double x) { mRand = x; }
	

	


private:
	CRotationSource mSource;
	CRotationSink mSink;
	double mRadius = 30;
	double mSourceRadius = 1;
	bool mAttached = false;
	double mOriginalY = 0; // keep
	std::shared_ptr<CWavChannel> mWavChannel;
	double mRand = 1.0;

};

