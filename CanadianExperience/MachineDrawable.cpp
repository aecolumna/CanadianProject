/**
 * \file MachineDrawable.cpp
 *
 * \author Andres Columna
 */


#include "stdafx.h"
#include "MachineDrawable.h"
#include "MachineFactory.h"
#include "Timeline.h"


 /** \brief Constructor
  */
CMachineDrawable::CMachineDrawable()
{
	auto factory = CMachineFactory();
	mMachine = factory.CreateMachine();
	mMachine->SetLocation(200, 200);
}

/** \brief Constructor
* \param x signals to call the constructor for machine2
 */
CMachineDrawable::CMachineDrawable(int x)
{
	auto factory = CMachineFactory();
	mMachine = factory.CreateMachine(x);
	mMachine->SetLocation(50, 50);
}


/**
 * Destructor
 */
CMachineDrawable::~CMachineDrawable()
{
}

/** \brief Sets timeline
* \param timeline Timeline used by this drawable
*/
void CMachineDrawable::SetTimeline(CTimeline * timeline)
{
	CDrawable::SetTimeline(timeline);
	mTimeline = timeline;
}

/** \brief Draws machine
*   \param graphics Graphics object we draw onto
*/
void CMachineDrawable::Draw(Gdiplus::Graphics * graphics)
{
	int currFrame = mTimeline->GetCurrentFrame();
	if ( currFrame >= mStartTime && currFrame <= mEndTime)
	{
		mMachine->SetMachineFrame(currFrame);
	}

	mMachine->DrawMachine(graphics);
}

/** \brief checks to see if Machine has been hit
* \param pos position of the click
* \returns bool whether actor is hit
*/
bool CMachineDrawable::HitTest(Gdiplus::Point pos)
{

	// check if we've been hit!
	return true;
}
