#pragma once
#include "Component.h"
#include "RotationSink.h"
#include "RotationSource.h"

class CRoller : public CComponent
{
public:
	CRoller();
	CRoller(double radius);
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

private:
	CRotationSource mSource;
	CRotationSink mSink;
	double mRadius = 30;
	double mSourceRadius = 1;
	bool mAttached = false;
	double mOriginalY = 0;
};

