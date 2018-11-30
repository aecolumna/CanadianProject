#include "stdafx.h"
#include "Shaft.h"
#include "RotationSink.h"
#include <cmath>
#include <cassert>


using namespace std;


const int insidePulleyRadius = 30;
const int ShaftRadius = 5;
CShaft::CShaft()
{
	assert(false); // This shouldn't be running
}

void CShaft::Draw(Gdiplus::Graphics* graphics)
{
	CComponent::Draw(graphics);
}

CShaft::CShaft(int x, int y) : CComponent(x, y)
{

	CComponent::SetCanMove(true);

	int size = 150;
	Rectangle(-2.5, -5, 5, 100);
	CComponent::SetImage(L"images/mallet.png");
	SetCanMove(true);
	mOriginalY = y; // possibly delete

}

CShaft::~CShaft()
{
}

const double PI = 3.14149;
void CShaft::UpdatePosition(double angle)
{
	angle -= .5;
	double amplitude = 10;
	double cosSquaredRadians = cos(angle * 2 * PI * mRand - PI);
	cosSquaredRadians = cosSquaredRadians * cosSquaredRadians;
	double newHeight = mOriginalY - (amplitude * cosSquaredRadians);
	SetY(newHeight);

	if(cosSquaredRadians > .98)
	{
		mWavChannel->Play();
	}
}

void CShaft::UpdateRotation(double angle)
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

	//CComponent::SetRotation(actualAngle);
	UpdatePosition(actualAngle);

	/// Turn angle into Y movement, somehow!

	std::vector<CRotationSink*> vec = GetSource()->GetSinks();
	for (auto src : vec)
	{
		src->SetRotation(mRadius * actualAngle);
		src->SetY(GetY());
	}

}

void CShaft::SetSourceRadius(double rad)
{
	mAttached = true;
	mSourceRadius = rad;
}
