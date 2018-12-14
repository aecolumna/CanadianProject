/**
 * \file RotationSource.h
 *
 * \author Andres Columna
 *
 * 
 */


#pragma once

#include <vector>

/// forward declaration
class CRotationSink;


/**
 * Represents a rotation source
 */
class CRotationSource
{
public:
	CRotationSource();
	virtual ~CRotationSource();
	CRotationSource(const CRotationSource &) = delete;
	/// Assignment operator/disabled
	void operator=(const CRotationSource &) = delete;

	void SetRotation(double x);

	/// get the rotation of the source
	/// \return rotation Rotation in turns, where 0-1 is one revolution.
	double GetRotation() { return mAngleDistance; }

	void SetY(double y);

	/// Set sink
	/// \param sink Rotation in turns, where 0-1 is one revolution.
	void SetSink(CRotationSink* sink) { mSink = sink; }

	/// get the sink of the polygon
	/// \return rotation Rotation in turns, where 0-1 is one revolution.
	CRotationSink* GetSink() { return mSink; }

	/// Set sink
	/// \param sink Add sink to list
	void AddSink(CRotationSink* sink) { mSinks.push_back(sink); }

	/**
	* Get sinks
	* \return Vector of sinks
	*/
	std::vector<CRotationSink*>& GetSinks() { return mSinks; }


private:
	/// Angle distance
	double mAngleDistance = 0; // maybe not needed
	/// Angle my
	double mY = 0;
	/// pointer to sink
	CRotationSink* mSink = nullptr;
	/// vector of all sinks sourced by thus rotation rouce
	std::vector<CRotationSink*> mSinks;


};

