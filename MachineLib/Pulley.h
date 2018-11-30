#pragma once
#include "Component.h"
#include "RotationSink.h"
#include "RotationSource.h"

class CPulley : public CComponent
{
public:
	CPulley();
	CPulley(double radius);
	CPulley(int x, int y, double radius);
	virtual ~CPulley();

	virtual void UpdateRotation(double angle) override;

	/// Copy constructor/disabled
	CPulley(const CPulley &) = delete;

	/// Assignment operator/disabled
	void operator=(const CPulley &) = delete;

	double GetRadius() { return mRadius; }


	void SetSourceRadius(double rad);

private:
	CRotationSource mSource;
	CRotationSink mSink;
	double mRadius = 1;
	double mSourceRadius = 1;
	bool mAttached = false;
};

