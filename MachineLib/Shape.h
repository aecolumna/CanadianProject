#pragma once
#include "Component.h"
#include "RotationSink.h"
#include "RotationSource.h"

class CShape : public CComponent
{
public:
	// you must specify source radius
	CShape();

	CShape(int x, int y);

	virtual ~CShape();

	virtual void UpdateRotation(double angle) override;

	//virtual void UpdateRotation(double angle) override;

	/// Copy constructor/disabled
	CShape(const CShape &) = delete;

	/// Assignment operator/disabled
	void operator=(const CShape &) = delete;

	double GetRadius() { return mRadius; }


	void SetSourceRadius(double rad);

	void SetAttached(bool val) { mAttached = val; }

private:

	CRotationSource mSource;
	CRotationSink mSink;
	double mRadius = 1;
	double mSourceRadius = 1;
	bool mAttached = false;
};

