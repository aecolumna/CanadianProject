#include "stdafx.h"
#include "Pulley.h"
#include "RotationSink.h"

CPulley::CPulley()
{
}

CPulley::CPulley(double radius)
{
	CComponent::Circle(radius);
	CComponent::SetImage(L"images/pulley2.png");
	CComponent::SetCanMove(true);
}

CPulley::CPulley(int x, int y, double radius=1) : CComponent(x,y), mRadius(radius)
{

	CComponent::SetImage(L"images/pulley2.png");
	CComponent::SetCanMove(true);
	CComponent::Circle(radius);
}


CPulley::~CPulley()
{
}

void CPulley::UpdateRotation(double angle)
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

	std::vector<CRotationSink*> vec = GetSource()->GetSinks();
	for (auto src : vec)
	{
		src->SetRotation(mRadius * actualAngle);
	}

	//GetSource()->SetRotation(mRadius * actualAngle);
}

void CPulley::SetSourceRadius(double rad)
{
	mAttached = true;
	mSourceRadius = rad;
}
