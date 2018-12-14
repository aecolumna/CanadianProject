/**
 * \file Cam.cpp
 *
 * \author Andres Columna
 */

/**
 * \file Cam.cpp
 *
 * \author Andres Columna
 */



#include "stdafx.h"
#include "Cam.h"



/**
 * Constructor
 */
CCam::CCam()
{
	CCam(0, 0);
}


/**
 * Constructor
 * \param x position val
 * \param y position val
 */
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



/**
 * Destructor
 */
CCam::~CCam()
{
}


/**
 * Update Rotation
 * \param angle angle we'd like to rotate the cam at
 */
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


/**
 * Set source radius of rotation
 * \param rad turns in radians
 */
void CCam::SetSourceRadius(double rad)
{
	mAttached = true;
	mSourceRadius = rad;
}
