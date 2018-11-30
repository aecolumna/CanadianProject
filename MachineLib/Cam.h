#pragma once
#include "Component.h"
#include "RotationSink.h"
#include "RotationSource.h"

class CCam : public CComponent
{
public:
	// you must specify source radius
	CCam();

	CCam(int x, int y);

	virtual ~CCam();

	virtual void UpdateRotation(double angle) override;

	//virtual void UpdateRotation(double angle) override;

	/// Copy constructor/disabled
	CCam(const CCam &) = delete;

	/// Assignment operator/disabled
	void operator=(const CCam &) = delete;

	double GetRadius() { return mRadius; }


	void SetSourceRadius(double rad);

	void SetAttached(bool val) { mAttached = val; }

private:

	CRotationSource mSource;
	CRotationSink mSink;
	double mRadius = 1;
	double mSourceRadius = 1;
	bool mAttached = true;
};



