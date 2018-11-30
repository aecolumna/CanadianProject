#include "stdafx.h"
#include "RotationSource.h"
#include "RotationSink.h"

CRotationSource::CRotationSource()
{
}


CRotationSource::~CRotationSource()
{
}

void CRotationSource::SetRotation(double angleDistance)
{
	mAngleDistance = angleDistance;
	if (GetSink() == nullptr)
		return;
	GetSink()->SetRotation(mAngleDistance);
}


