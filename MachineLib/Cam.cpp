#include "stdafx.h"
#include "Cam.h"


CCam::CCam()
{
	CCam(0, 0);
}


CCam::CCam(int x, int y) : CComponent(x, y)
{

	int insidePulleyRadius = 30;
	CComponent::SetCanMove(true);
	Circle(insidePulleyRadius - 10);
	SetImage(L"images/hammered-copper1.png");
	SetRadius(insidePulleyRadius - 10);
	SetSourceRadius(insidePulleyRadius);
	SetCanMove(true);
}



CCam::~CCam()
{
}

void CCam::UpdateRotation(double angle)
{
	/*
			The rotation is straight from the frame count!
			Multiply times the speed here maybe?
		*/

		// get angle-distance from Sink!
	double rawAngle = GetSink()->GetRotation();
	double actualAngle;
	if (!mAttached)
	{
		actualAngle = rawAngle / CComponent::GetRadius();
	}
	else
	{
		actualAngle = rawAngle / mSourceRadius;
	}

	CComponent::SetRotation(actualAngle);

	std::vector<CRotationSink*> vec = GetSource()->GetSinks();
	for (auto src : vec)
	{
		src->SetRotation(CComponent::GetRadius() * actualAngle);
	}

}

void CCam::SetSourceRadius(double rad)
{
	mAttached = true;
	mSourceRadius = rad;
}
