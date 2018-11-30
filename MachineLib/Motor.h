#pragma once
#include "Component.h"


class CMotor : public CComponent
{
public:
	CMotor();
	/// Copy constructor/disabled
	CMotor(const CMotor &) = delete;
	/// Assignment operator/disabled
	void operator=(const CMotor &) = delete;
	virtual ~CMotor();

	CMotor(int x, int y, double radius);

	void Draw(Gdiplus::Graphics * graphics, double angle);
	virtual void UpdateRotation(double angle);

private:
	double mRadius = 1;

};

