#pragma once
#include "Polygon.h"

#include "RotationSink.h"
#include "RotationSource.h"


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

	virtual void UpdateRotation(double angle);
	bool GetCanMove() { return mCanMove; }
	void SetCanMove(bool val) { mCanMove = val; }

	CRotationSource* GetSource() { return &mSource; }
	CRotationSink* GetSink() { return &mSink; }
	void SetRadius(double radius) { mRadius = radius; }
	double GetRadius() { return mRadius; }
	int GetX() { return mPos.X; }
	int GetY() { return mPos.Y; }
	void SetY(int y) { mPos = Gdiplus::Point(mPos.X, y); }
	void SetX(int x){ mPos = Gdiplus::Point(x, mPos.Y) ; }
	void SetPos(int x, int y) { Gdiplus::Point(x, y); }

private:
	Gdiplus::Point mPos = Gdiplus::Point(0, 0);
	double mAngle = 0.0; // remove!
	bool mCanMove = false;
	CRotationSource mSource;
	CRotationSink mSink;
	double mRadius = 1;
};

