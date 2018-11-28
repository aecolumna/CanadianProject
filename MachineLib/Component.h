#pragma once
#include "Polygon.h"


class CComponent : public CPolygon
{
public:
	CComponent();
	CComponent(int x, int y);
	CComponent(Gdiplus::Point point);
	virtual ~CComponent();

	/// Copy constructor/disabled
	CComponent(const CComponent &) = delete;

	/// Assignment operator/disabled
	void operator=(const CComponent &) = delete;

	virtual void Draw(Gdiplus::Graphics* graphics);
	virtual void Draw(Gdiplus::Graphics* graphics, double angle);
	bool GetCanMove() { return mCanMove; }
	void SetCanMove(bool val) { mCanMove = val; }

private:
	Gdiplus::Point mPos = Gdiplus::Point(0, 0);
	double mAngle = 0.0;
	bool mCanMove = false;
};

