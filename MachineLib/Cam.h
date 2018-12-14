/**
 * \file Cam.h
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
 * A cam in our machine
 */
class CCam : public CComponent
{
public:
	// you must specify source radius
	CCam();

	CCam(int x, int y);

	virtual ~CCam();

	virtual void UpdateRotation(double angle) override;

	//virtual void UpdateRotation(double angle) override;

	/// Copy constructor/disabled
	CCam(const CCam &) = delete;

	/// Assignment operator/disabled
	void operator=(const CCam &) = delete;

	/**
	* Get Radius
	* \return radius of cam
	*/
	double GetRadius() { return mRadius; }


	void SetSourceRadius(double rad);

	/**
	 * Set whether cam is attached to its source or by pulley if false
	 * \param val true if attached
	 */
	void SetAttached(bool val) { mAttached = val; }

private:
	/// Source of turning
	CRotationSource mSource;
	/// Sink of turning
	CRotationSink mSink;

	/// Radius of cam
	double mRadius = 1;
	/// Source of Radius
	double mSourceRadius = 1;
	/// whether machine is attached or not
	bool mAttached = true;
};



