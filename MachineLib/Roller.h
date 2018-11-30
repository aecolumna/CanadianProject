#pragma once
#include "Component.h"
#include "RotationSink.h"
#include "RotationSource.h"
#include "Shape.h"

class CRoller : public CComponent
{
public:
	CRoller();
	virtual void Draw(Gdiplus::Graphics * graphics) override;
	CRoller(int x, int y);
	virtual ~CRoller();

	void UpdatePosition(double angle);

	virtual void UpdateRotation(double angle) override;

	/// Copy constructor/disabled
	CRoller(const CRoller &) = delete;

	/// Assignment operator/disabled
	void operator=(const CRoller &) = delete;

	double GetRadius() { return mRadius; }

	void SetSourceRadius(double rad);

	void SetRand(double x) { mRand = x; }


private:
	CRotationSource mSource;
	CRotationSink mSink;
	double mRadius = 30;
	double mSourceRadius = 1;
	bool mAttached = false;
	double mOriginalY = 0; // keep
	double mRand = 1.0;
};

