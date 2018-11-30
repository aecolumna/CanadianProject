#pragma once

#include <vector>

class CRotationSink;

class CRotationSource
{
public:
	CRotationSource();
	virtual ~CRotationSource();
	CRotationSource(const CRotationSource &) = delete;
	/// Assignment operator/disabled
	void operator=(const CRotationSource &) = delete;

	void SetRotation(double x);
	double GetRotation() { return mAngleDistance; }


	void SetSink(CRotationSink* sink) { mSink = sink; }
	CRotationSink* GetSink() { return mSink; }

	void AddSink(CRotationSink* sink) { mSinks.push_back(sink); }
	std::vector<CRotationSink*>& GetSinks() { return mSinks; }

private:
	double mAngleDistance = 0; // maybe not needed
	CRotationSink* mSink = nullptr;
	std::vector<CRotationSink*> mSinks;


};

