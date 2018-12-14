/**
 * \file Pulley.h
 *
 * \author Andres Columna
 *
 * 
 */


#pragma once
#include "Component.h"
#include "RotationSink.h"
#include "RotationSource.h"


/**
 * Represents a pulley in a machine
 */
class CPulley : public CComponent
{
public:
	CPulley();
	CPulley(double radius);
	CPulley(int x, int y, double radius);
	virtual ~CPulley();

	virtual void UpdateRotation(double angle) override;

	/// Copy constructor/disabled
	CPulley(const CPulley &) = delete;

	/// Assignment operator/disabled
	void operator=(const CPulley &) = delete;

	/**
	 * Get Radius
	 * \return double
	 */
	double GetRadius() { return mRadius; }

	/**
	 * Set radius
	 * \param rad radius
	 */
	void SetSourceRadius(double rad);

private:

	/// source of rotation
	CRotationSource mSource;
	/// sink of rotation
	CRotationSink mSink;
	/// radius of this pulley
	double mRadius = 1;
	/// radius of the source of our rotation
	double mSourceRadius = 1;
	/// whether pulley is attached or not
	bool mAttached = false;
};

