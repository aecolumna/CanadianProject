#include "stdafx.h"
#include "Component.h"
#include "RotationSource.h"
#include "RotationSink.h"


using namespace Gdiplus;
using namespace std;
CComponent::CComponent()
{
	CPolygon::SetColor(Color::Black); //default color is black
}

CComponent::CComponent(int x, int y)
{

	mPos = Point(x, y);
	CPolygon::SetColor(Color::Black); // default color is black
}

CComponent::CComponent(Gdiplus::Point point)
{
	mPos = point;
}


CComponent::~CComponent()
{
}

void CComponent::Draw(Gdiplus::Graphics* graphics)
{

	CPolygon::DrawPolygon(graphics, mPos.X, mPos.Y);
}


void CComponent::Draw(Gdiplus::Graphics * graphics, double angle)
{
	/*if(mCanMove)
	{
		mAngle = angle;
		CPolygon::SetRotation(angle * .1);
	}*/

	CPolygon::DrawPolygon(graphics, mPos.X, mPos.Y);
}

void CComponent::UpdateRotation(double angle)
{

	/*
	The rotation is straight from the frame count!
	Multiply times the speed here maybe?
	*/
	
	// doesn't have a source so return
	if (mCanMove == false) 
	{
		return;
	}

// get angle-distance from Sink!
	double rawAngle = GetSink()->GetRotation();
	double actualAngle;

	actualAngle = rawAngle / mRadius;
	
	CComponent::SetRotation(actualAngle);
	GetSource()->SetRotation(mRadius * actualAngle);
	return; // do nothing!
}
