/**
 * \file MachineDrawable.h
 *
 * \author Andres Columna
 *
 * 
 */


#pragma once
#include "Drawable.h"
#include "Machine.h"
#include "Timeline.h"

/**
 * CMachineDrawable Represents a drawable machine
 */
class CMachineDrawable : public CDrawable
{
public:
	CMachineDrawable();
	CMachineDrawable(int x);
	/** \brief Copy constructor disabled */
	CMachineDrawable(const CMachineDrawable &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CMachineDrawable &) = delete;
	virtual ~CMachineDrawable();

	virtual void SetTimeline(CTimeline *timeline) override;
	virtual void Draw(Gdiplus::Graphics *graphics) override;
	virtual bool HitTest(Gdiplus::Point pos) override;

private:
	/// timeline for getting current frame
	CTimeline* mTimeline = nullptr;

	/// Pointer to machine
	std::shared_ptr<CMachine> mMachine;

	/// When the machine starts playing
	int mStartTime = 60;
	/// frame at which machine stops playing
	int mEndTime = 270;
};

