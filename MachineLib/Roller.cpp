#include "stdafx.h"
#include "Roller.h"
#include "RotationSink.h"
#include <cmath>
CRoller::CRoller()
{
}

CRoller::CRoller(double radius)
{
	CComponent::Circle(radius);
	CComponent::SetImage(L"images/rollerL.png");
	CComponent::SetCanMove(true);
}

CRoller::CRoller(int x, int y) : CComponent(x, y)
{
	CComponent::SetImage(L"images/roller.png");
	CComponent::SetCanMove(true);
	int insidePulleyRadius = 30;
	Circle(5);
	SetCanMove(true);
	mOriginalY = y;
}


CRoller::~CRoller()
{
}

const double PI = 3.14149;
void CRoller::UpdatePosition(double angle)
{
	double amplitude = 10;
	double cosSquaredRadians = cos(angle * 2 * PI);
	cosSquaredRadians = cosSquaredRadians * cosSquaredRadians;
	double newHeight = mOriginalY - 10 * cosSquaredRadians;
	SetY(newHeight);
}
void CRoller::UpdateRotation(double angle)
{
	/*
		The rotation is straight from the frame count!
		Multiply times the speed here maybe?
	*/

	// get angle-distance from Sink!
	double rawAngle = GetSink()->GetRotation();
	double actualAngle;
	if (true)
	{
		actualAngle = rawAngle / mRadius;
	}
	else
	{
		actualAngle = rawAngle / mSourceRadius;
	}

	CComponent::SetRotation(actualAngle);
	UpdatePosition(actualAngle);

	/// Turn angle into Y movement, somehow!

	std::vector<CRotationSink*> vec = GetSource()->GetSinks();
	for (auto src : vec)
	{
		src->SetRotation(mRadius * actualAngle);
	}

	//GetSource()->SetRotation(mRadius * actualAngle);
}

void CRoller::SetSourceRadius(double rad)
{
	mAttached = true;
	mSourceRadius = rad;
}
