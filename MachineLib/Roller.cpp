#include "stdafx.h"
#include "Roller.h"
#include "RotationSink.h"
#include <cmath>
#include <cassert>

using namespace std;


const int insidePulleyRadius = 30;
const int rollerRadius = 5;
CRoller::CRoller()
{
	assert(false); // This shouldn't be running
}

void CRoller::Draw(Gdiplus::Graphics* graphics)
{
	CComponent::Draw(graphics);
}

CRoller::CRoller(int x, int y) : CComponent(x, y)
{
	CComponent::SetImage(L"images/roller.png");
	CComponent::SetCanMove(true);

	Circle(rollerRadius);
	SetCanMove(true);
	mOriginalY = y; // possibly delete

}

CRoller::~CRoller()
{
}

const double PI = 3.14149;
void CRoller::UpdatePosition(double angle)
{
	angle -= .5;
	double amplitude = 20;
	double cosSquaredRadians = cos(angle * 2 * PI * mRand - PI);
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
		src->SetY(GetY());
	}

}

void CRoller::SetSourceRadius(double rad)
{
	mAttached = true;
	mSourceRadius = rad;
}
