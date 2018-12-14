/**
 * \file Shape.cpp
 *
 * \author Andres Columna
 */


#include "stdafx.h"
#include "Shape.h"


/**
 * Constructor
 */
CShape::CShape()
{
	CComponent::SetCanMove(true);
}


/**
 * Constructor overloaded
 * \param x pos
 * \param y pos
 */
CShape::CShape(int x, int y) : CComponent(x, y)
{
	CComponent::SetCanMove(true);
}


/**
 * Destructor
 */
CShape::~CShape()
{
}


/**
 * Update rotation
 * \param angle angle to rotate
 */
void CShape::UpdateRotation(double angle)
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
 * Set radius of source
 * \param rad 
 */
void CShape::SetSourceRadius(double rad)
{
	mAttached = true;
	mSourceRadius = rad;
}
