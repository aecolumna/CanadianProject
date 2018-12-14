/**
 * \file Shape.h
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
 * Represents a shape component
 */
class CShape : public CComponent
{
public:
	// you must specify source radius
	CShape();

	CShape(int x, int y);

	virtual ~CShape();

	virtual void UpdateRotation(double angle) override;

	//virtual void UpdateRotation(double angle) override;

	/// Copy constructor/disabled
	CShape(const CShape &) = delete;

	/// Assignment operator/disabled
	void operator=(const CShape &) = delete;

	/// Get Radius
	/// \return radius
	double GetRadius() { return mRadius; }


	void SetSourceRadius(double rad);
	/// Set whether it is attached
	/// \param val Rotation in turns, where 0-1 is one revolution.
	void SetAttached(bool val) { mAttached = val; }

private:
	/// source of rotation
	CRotationSource mSource;
	/// sink of rotation
	CRotationSink mSink;
	/// radius of rotation
	double mRadius = 1;
	/// source of rotation
	double mSourceRadius = 1;
	///whether it is attached or not
	bool mAttached = false;
};

