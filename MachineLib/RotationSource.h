#pragma once

class CRotationSink;

class CRotationSource
{
public:
	CRotationSource();
	virtual ~CRotationSource();
	CRotationSource(const CRotationSource &) = delete;
	/// Assignment operator/disabled
	void operator=(const CRotationSource &) = delete;

	void Rotate(double x) { mRotation = mRotation + x; }
	double GetRotation() { return mRotation; }

	void SetSink(CRotationSink* sink) { mSink = sink; }
	CRotationSink* GetSink() { return mSink; }

private:
	double mRotation = 0; // maybe not needed
	CRotationSink* mSink = nullptr;

};

