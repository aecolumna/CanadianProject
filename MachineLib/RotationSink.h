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
	double GetY() { return mY; }
	void SetY(double y) { mY = y; }

private:
	double mRotation = 0;
	double mY = 0;

};

