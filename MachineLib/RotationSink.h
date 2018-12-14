/**
 * \file RotationSink.h
 *
 * \author Andres Columna
 *
 * 
 */



#pragma once


/**
 * Represents a sink of rotation
 */
class CRotationSink
{
public:
	CRotationSink();
	CRotationSink(const CRotationSink &) = delete;
	/// Assignment operator/disabled
	void operator=(const CRotationSink &) = delete;

	virtual ~CRotationSink();

	/// Set the rotation of the polygon
	/// \return rotation Rotation in turns, where 0-1 is one revolution.
	double GetRotation() { return mRotation; }
	/// Set the rotation of the polygon
	/// \param x Rotation in turns, where 0-1 is one revolution.
	void SetRotation(double x) { mRotation = x; }
	/// Get Height
	/// \return mY rotation Rotation in turns, where 0-1 is one revolution.
	double GetY() { return mY; }
	/// Set the rotation of the polygon
	/// \param y Rotation in turns, where 0-1 is one revolution.
	void SetY(double y) { mY = y; }

private:
	/// rotation of sink
	double mRotation = 0;
	/// current height
	double mY = 0;

};

