#include "stdafx.h"
#include "Component.h"



using namespace Gdiplus;
using namespace std;
CComponent::CComponent()
{
}

CComponent::CComponent(int x, int y)
{
	mPos = Point(x, y);
}

CComponent::CComponent(Gdiplus::Point point)
{
	mPos = point;
}


CComponent::~CComponent()
{
}

void CComponent::DrawComponent(Gdiplus::Graphics* graphics)
{

	CPolygon::DrawPolygon(graphics, mPos.X, mPos.Y);
}


void CComponent::DrawComponent(Gdiplus::Graphics * graphics, double angle)
{
	if(mCanMove)
	{
		mAngle = angle;
		CPolygon::SetRotation(angle * .1);
	}

	CPolygon::DrawPolygon(graphics, mPos.X, mPos.Y);
}
