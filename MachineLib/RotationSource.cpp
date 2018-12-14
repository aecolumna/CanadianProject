#include "stdafx.h"
#include "RotationSource.h"
#include "RotationSink.h"


/**
 * Constructor
 */
CRotationSource::CRotationSource()
{
}


/**
 * Destructor
 */
CRotationSource::~CRotationSource()
{
}


/**
 * Set rotation
 * \param angleDistance distance
 */
void CRotationSource::SetRotation(double angleDistance)
{
	mAngleDistance = angleDistance;
	if (GetSink() == nullptr)
		return;
	GetSink()->SetRotation(mAngleDistance);
}


/**
 * Set the y value position
 * \param y 
 */
void CRotationSource::SetY(double y)
{
	mY = y;
	if (GetSink() == nullptr)
		return;
	GetSink()->SetY(y);
}




