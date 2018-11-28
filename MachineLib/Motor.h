#pragma once
#include "Component.h"
#include "RotationSource.h"

class CMotor : public CComponent
{
public:
	CMotor();
	/// Copy constructor/disabled
	CMotor(const CMotor &) = delete;
	/// Assignment operator/disabled
	void operator=(const CMotor &) = delete;
	virtual ~CMotor();

	CMotor(int x, int y);

	void Draw(Gdiplus::Graphics * graphics, double angle);

private:
	CRotationSource mSource;
	double mRadius = 1;

};

