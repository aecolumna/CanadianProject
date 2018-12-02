/**
 * \file Flag.h
 *
 * \author Andres Columna
 *
 * \brief Implements the top of a characters head,
 * which has special functionality.
 */

#pragma once

#include "ImageDrawable.h"
#include "AnimChannelPoint.h"

 /** \brief Implements the top of a characters head,
 * which has special functionality.
 */
class CFlag :
	public CImageDrawable
{
public:
	CFlag(const std::wstring &name, const std::wstring &filename);
	~CFlag();

	/** \brief Default constructor disabled */
	CFlag() = delete;
	/** \brief Copy constructor disabled */
	CFlag(const CFlag &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CFlag &) = delete;

	/// \brief Is this drawable moveable?
	/// \returns true
	virtual bool IsMovable() { return true; }

	void Draw(Gdiplus::Graphics *graphics);


	virtual void SetActor(CActor *actor) override;
	virtual void SetTimeline(CTimeline *timeline) override;
	virtual void SetKeyframe() override;
	virtual void GetKeyframe() override;

private:
	Gdiplus::Point TransformPoint(Gdiplus::Point p);

	/// Channel for the head position
	CAnimChannelPoint mPositionChannel;
};

