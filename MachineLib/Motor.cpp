#include "stdafx.h"
#include "Motor.h"


/**
 * Constructor
 */
CMotor::CMotor()
{
	SetImage(L"images/pulley2.png");
	SetCanMove(true);
}


/**
 * Destructor
 */
CMotor::~CMotor()
{
}


/**
 * Overloaded constructor
 * \param x 
 * \param y 
 * \param radius 
 */
CMotor::CMotor(int x, int y, double radius=1) :
	CComponent(x, y), mRadius(radius)
{
	Circle(radius);
	SetImage(L"images/pulley2.png");
	SetCanMove(true);
}


/**
 * Draw the motor
 * \param graphics 
 * \param angle 
 */
void CMotor::Draw(Gdiplus::Graphics * graphics, double angle)
{
	CComponent::Draw(graphics, angle);
}


/**
 * Update rotation
 * \param angle 
 */
void CMotor::UpdateRotation(double angle)
{
	/*
		The rotation is straight from the frame count!
		Multiply times the speed here maybe?
	*/
	CComponent::SetRotation(angle);

	GetSource()->SetRotation( mRadius * angle);
}
