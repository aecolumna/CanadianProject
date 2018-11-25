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

	void DrawComponent(Gdiplus::Graphics* graphics);
	void DrawComponent(Gdiplus::Graphics* graphics, double angle);

private:
	Gdiplus::Point mPos = Gdiplus::Point(0, 0);
	double mAngle = 0.0;
};

