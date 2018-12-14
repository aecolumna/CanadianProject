/**
 * \file Pulley.cpp
 *
 * \author Andres Columna
 */

#include "stdafx.h"
#include "Pulley.h"
#include "RotationSink.h"


/**
 * Constructor
 */
CPulley::CPulley()
{
}


/**
 * Constructor
 * \param radius set radius
 */
CPulley::CPulley(double radius)
{
	CComponent::Circle(radius);
	CComponent::SetImage(L"images/pulley2.png");
	CComponent::SetCanMove(true);
}


/**
 * Constructor
 * \param x x position
 * \param y y position
 * \param radius of turning
 */
CPulley::CPulley(int x, int y, double radius=1) : CComponent(x,y), mRadius(radius)
{

	CComponent::SetImage(L"images/pulley2.png");
	CComponent::SetCanMove(true);
	CComponent::Circle(radius);
}


/**
 * Destructor
 */
CPulley::~CPulley()
{
}


/**
 * Update rotation of pulley
 * \param angle 
 */
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


/**
 * Set radius of source connected to this pulley
 * \param rad 
 */
void CPulley::SetSourceRadius(double rad)
{
	mAttached = true;
	mSourceRadius = rad;
}
