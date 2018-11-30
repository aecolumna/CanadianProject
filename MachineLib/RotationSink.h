#pragma once
class CRotationSink
{
public:
	CRotationSink();
	CRotationSink(const CRotationSink &) = delete;
	/// Assignment operator/disabled
	void operator=(const CRotationSink &) = delete;
	virtual ~CRotationSink();

	double GetRotation() { return mRotation; }
	void SetRotation(double x) { mRotation = x; }

private:
	double mRotation = 0;

};

