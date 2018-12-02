#include "stdafx.h"
#include "Flag.h"
#include "Actor.h"
#include "Timeline.h"

#include <sstream>
#include <iomanip>

using namespace Gdiplus;
using namespace std;

/// Constant ratio to convert radians to degrees
const double RtoD = 57.295779513;

/** \brief Constructor for a top of the head object
 * \param name The drawable name to use
 * \param filename The filename for the image to use
 */
CFlag::CFlag(const std::wstring &name, const std::wstring &filename) : CImageDrawable(name, filename)
{
}


/**
 * \brief Destructor
 */
CFlag::~CFlag()
{
}


/**
 * \brief Set the actor. This is where we set the channel name
 * \param actor Actor to set
 */
void CFlag::SetActor(CActor *actor)
{
	CImageDrawable::SetActor(actor);

	// Set the channel name
	mPositionChannel.SetName(actor->GetName() + L":" + GetName() + L":position");

}


/**
 * \brief Set the timeline. The tells the channel the timeline
 * \param timeline Timeline to set
 */
void CFlag::SetTimeline(CTimeline *timeline)
{
	CImageDrawable::SetTimeline(timeline);

	timeline->AddChannel(&mPositionChannel);
}


/** \brief Set the keyframe based on the current status.
*/
void CFlag::SetKeyframe()
{
	CImageDrawable::SetKeyframe();

	mPositionChannel.SetKeyframe(GetPosition());
}

/** \brief Get the current channel from the animation system.
*/
void CFlag::GetKeyframe()
{
	CImageDrawable::GetKeyframe();

	if (mPositionChannel.IsValid())
		SetPosition(mPositionChannel.GetPoint());
}



/**
* \brief Draw the head
* \param graphics Graphics context to draw on
*/
void CFlag::Draw(Gdiplus::Graphics *graphics)
{
	CImageDrawable::Draw(graphics);

	//SolidBrush brush(Color::Black);
	//FontFamily fontFamily(L"Arial");
	//Gdiplus::Font font(&fontFamily, 30);

	//wstringstream str;
	//double rotation = GetRotation();
	//str << fixed << setprecision(1) << rotation;
	//RectF bb;
	//graphics->MeasureString(str.str().c_str(), str.str().length(), &font, PointF(0, 0), &bb);
	//graphics->DrawString(str.str().c_str(), str.str().length(), &font, PointF((float)(mPlacedPosition.X - bb.Width / 2), (float)mPlacedPosition.Y - 40), &brush);

}

/** Transform a point from a location on the bitmap to
*  a location on the screen.
* \param  p Point to transform
* \returns Transformed point
*/
Gdiplus::Point CFlag::TransformPoint(Gdiplus::Point p)
{
	// Make p relative to the image center
	p = p - GetCenter();

	// Rotate as needed and offset
	return RotatePoint(p, mPlacedR) + mPlacedPosition;
}