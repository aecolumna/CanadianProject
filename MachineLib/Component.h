/**
 * \file Component.h
 *
 * \author Andres Columna
 *
 * 
 */



#pragma once
#include "Polygon.h"

#include "RotationSink.h"
#include "RotationSource.h"



/**
 * Class denotes a component in our machine
 */
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
	/**
	 * whether component is fixed or not
	 * \return bool if it can move
	 */
	bool GetCanMove() { return mCanMove; }
	/**
	 * Set whether can move
	 * \param val if it can move
	 */
	void SetCanMove(bool val) { mCanMove = val; }

	/**
	 * Get source of turning
	 * \return pointer to srouce
	 */
	CRotationSource* GetSource() { return &mSource; }
	/**
	 * Get sink of turning
	 * \return pointer to sink
	 */
	CRotationSink* GetSink() { return &mSink; }
	/**
	 * Set  radius of rotation
	 * \param radius 
	 */
	void SetRadius(double radius) { mRadius = radius; }
	/**
	 * Get  radius of rotation
	 * \return double of radius
	 */
	double GetRadius() { return mRadius; }
	/**
	 * Get x
	 * \return int x position
	 */
	int GetX() { return mPos.X; }
	/**
	 * Get y
	 * \return int y position
	 */
	int GetY() { return mPos.Y; }
	/**
	 * Set Y
	 * \param y int y position
	 */
	void SetY(int y) { mPos = Gdiplus::Point(mPos.X, y); }
	/**
	 * Set x
	 * \param x position
	 */
	void SetX(int x){ mPos = Gdiplus::Point(x, mPos.Y) ; }
	/**
	 * Set position
	 * \param x position
	 * \param y position
	 */
	void SetPos(int x, int y) { Gdiplus::Point(x, y); }

private:
	/// position of component
	Gdiplus::Point mPos = Gdiplus::Point(0, 0);
	/// angle
	double mAngle = 0.0; // remove!
	/// whether it can move
	bool mCanMove = false;
	/// the source of rotation
	CRotationSource mSource;
	/// the sink where we keep items this component drives
	CRotationSink mSink;
	/// the radius of this component
	double mRadius = 1;
};

