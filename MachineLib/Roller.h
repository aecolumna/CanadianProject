/**
 * \file Roller.h
 *
 * \author Andres Columna
 *
 * 
 */


#pragma once
#include "Component.h"
#include "RotationSink.h"
#include "RotationSource.h"
#include "Shape.h"


/**
 * Represents a roller
 */
class CRoller : public CComponent
{
public:
	CRoller();
	virtual void Draw(Gdiplus::Graphics * graphics) override;
	CRoller(int x, int y);
	virtual ~CRoller();

	void UpdatePosition(double angle);

	virtual void UpdateRotation(double angle) override;

	/// Copy constructor/disabled
	CRoller(const CRoller &) = delete;

	/// Assignment operator/disabled
	void operator=(const CRoller &) = delete;

	/**
	 * Get Radius
	 * \return Radius
	 */
	double GetRadius() { return mRadius; }

	/**
	 * Set new machine
	 * \param rad A double
	 */
	void SetSourceRadius(double rad);

	/**
	 * Set rand
	 * \param x our random seed
	 */
	void SetRand(double x) { mRand = x; }


private:
	/// Our source of rotation
	CRotationSource mSource;
	/// Our sink of rotation
	CRotationSink mSink;
	/// The radius of rotation
	double mRadius = 30;
	/// The radius of the source of rotation
	double mSourceRadius = 1;

	/// Whether is it attached to another wheel or driven by pulley
	bool mAttached = false;
	/// the height of the original position of the roller
	double mOriginalY = 0; // keep
	/// Random seed for rand seed
	double mRand = 1.0;

};

