/**
 * \file Component.cpp
 *
 * \author Andres Columna
 */


#include "stdafx.h"
#include "Component.h"
#include "RotationSource.h"
#include "RotationSink.h"


using namespace Gdiplus;
using namespace std;


/**
 * Constructor
 */
CComponent::CComponent()
{
	CPolygon::SetColor(Color::Black); //default color is black
}


/**
 * Constrcutor overloaded
 * \param x position x
 * \param y position y
 */
CComponent::CComponent(int x, int y)
{

	mPos = Point(x, y);
	CPolygon::SetColor(Color::Black); // default color is black
}


/**
 * Constructor overloaded
 * \param point location of our component
 */
CComponent::CComponent(Gdiplus::Point point)
{
	mPos = point;
}


/**
 * Destructor
 */
CComponent::~CComponent()
{
}


/**
 * Draw polygon
 * \param graphics object on which to draw
 */
void CComponent::Draw(Gdiplus::Graphics* graphics)
{
	CPolygon::DrawPolygon(graphics, mPos.X, mPos.Y);
}


/**
 * Draw component
 * \param graphics 
 * \param angle 
 */
void CComponent::Draw(Gdiplus::Graphics * graphics, double angle)
{
	/*if(mCanMove)
	{
		mAngle = angle;
		CPolygon::SetRotation(angle * .1);
	}*/

	CPolygon::DrawPolygon(graphics, mPos.X, mPos.Y);
}


/**
 * Update rotation of component
 * \param angle on which to switch to
 */
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
