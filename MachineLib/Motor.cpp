#include "stdafx.h"
#include "Motor.h"


CMotor::CMotor()
{
}


CMotor::~CMotor()
{
}

CMotor::CMotor(int x, int y) :
	CComponent(x, y)
{

}


void CMotor::Draw(Gdiplus::Graphics * graphics, double angle)
{
	CComponent::Draw(graphics, angle);
}
