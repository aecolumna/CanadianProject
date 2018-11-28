#pragma once
class CRotationSink
{
public:
	CRotationSink();
	CRotationSink(const CRotationSink &) = delete;
	/// Assignment operator/disabled
	void operator=(const CRotationSink &) = delete;
	virtual ~CRotationSink();
};

