/**
 * \file Polygon.cpp
 *
 * \author Charles Owen
 */

#include "stdafx.h"
#include "Polygon.h"

using namespace Gdiplus;
using namespace std;

/// Degrees in a circle
const double CircleDegrees = 360;

/// Default number of steps when drawing a circle
const int DefaultCircleSteps = 32;

/// Length of the vector used for intersection testing.
const double IntersectionLength = 1000;


/**
 * Constructor
 */
CPolygon::CPolygon()
{
    // Create an initial brush in black
    mBrush = make_shared<Gdiplus::SolidBrush>(Color::Black);
}

/**
 * Destructor
 */
CPolygon::~CPolygon()
{
}


/**
 * Create a rectangle
 * \param x Left side X
 * \param y Bottom left Y
 * \param wid Width of the rectangle
 * \param hit Height of the rectangle
 */
void CPolygon::Rectangle(int x, int y, int wid, int hit)
{
    AddPoint(x, y);
    AddPoint(x, y-hit);
    AddPoint(x+wid, y-hit);
    AddPoint(x+wid, y);
}

/**
 * Create a circle centered on (0,0)
 * \param radius Circle radius
 * \param steps Number of steps in circle (0=default)
 */
void CPolygon::Circle(double radius, int steps)
{
	if (steps == 0)
	{
		steps = DefaultCircleSteps;
	}

	for (int i = 0; i < steps; i++)
	{
		double angle = double(i) / double(steps) * M_PI * 2;
		AddPoint(radius * cos(angle), radius * sin(angle));
	}
}


/**
 * Create a centered square at location 0,0
 * \param size Width and height of the square
 */
void CPolygon::CenteredSquare(int size)
{
    Rectangle(-size / 2, size / 2, size, size);
}


/**
 * Set the color of the polygon. If we set a color, images are not used.
 * \param color A Gdiplus Color object.
 */
void CPolygon::SetColor(Gdiplus::Color color)
{
    mBrush = make_shared<Gdiplus::SolidBrush>(color);
}

/**
 * Set an image we will use as a texture for the polygon
 * \param filename Image filename
 * \param center If true, the texture is centered on (0, 0)
 */
void CPolygon::SetImage(std::wstring filename, bool center)
{
	mTexture = make_shared<Texture>(this, filename, center);
}

/**
 * Constructor for a Texture mapping object.
 * \param polygon Polygon that is using this object
 * \param filename Texture image filename
 * \param center If true, the texture is centered on (0, 0)
 */
CPolygon::Texture::Texture(CPolygon *polygon, std::wstring filename, bool center) : 
	mPolygon(polygon), mCenter(center)
{
    mTexture = shared_ptr<Gdiplus::Bitmap>(Bitmap::FromFile(filename.c_str()));
    if (mTexture->GetLastStatus() != Ok)
    {
        AfxMessageBox((wstring(L"Failed to open ") + filename).c_str());
    }
    mBrush = make_shared<Gdiplus::TextureBrush>(mTexture.get());
}


/**
 * Draw the polygon
 * \param graphics Gdiplus graphics object
 * \param x X location to draw in pixels
 * \param y Y location to draw in pixels
 */
void CPolygon::DrawPolygon(Gdiplus::Graphics *graphics, int x, int y)
{
    auto saveSM = graphics->GetSmoothingMode();
    graphics->SetSmoothingMode(SmoothingMode::SmoothingModeHighQuality);

    auto save = graphics->Save();
    graphics->TranslateTransform((REAL)x, (REAL)y);
    graphics->RotateTransform((REAL)((mRotation + mPhase) * CircleDegrees));

	auto brush = mBrush;
    if (mTexture != nullptr)
    {
        brush = mTexture->Configue();
	}

    graphics->FillPolygon(brush.get(), &mPoints[0], mPoints.size());

    graphics->Restore(save);

    graphics->SetSmoothingMode(saveSM);
}

/**
 * Test if a line segment from the origin intersects with the polygon.
 *
 * This will return the first intersection found if there are many!
 * \param angle An angle in the range 0-1 that determines the direction of the line.
 * \param intersection Where to put the intersection point
 * \return true if there is an intersection
 */
bool CPolygon::Intersection(double angle, Gdiplus::PointF & intersection)
{
	return Intersection(PointF(0, 0),
		PointF((REAL)(IntersectionLength * cos(angle * M_PI * 2)), 
			(REAL)(-IntersectionLength * sin(angle * M_PI * 2))),
		intersection);
} 

/**
 * Test if a line segment intersects the polygon edge.
 *
 * This will return the first intersection found if there are many!
 * \param p0 Line segment point 1
 * \param p1 Line segment point 2
 * \param intersection Where to put the intersection point
 * \return true if there is an intersection
 */
bool CPolygon::Intersection(Gdiplus::PointF p0, Gdiplus::PointF p1, Gdiplus::PointF & intersection)
{
	// Rotate p0, p1 around the origin by the negative rotation of the polygon
	auto p0r = Rotate(p0, -(mRotation + mPhase) * M_PI * 2);
	auto p1r = Rotate(p1, -(mRotation + mPhase) * M_PI * 2);

	// i,j are two points on the polygon edge
	for (unsigned int i = 0; i < mPoints.size(); i++) 
	{
		unsigned int j = (i + 1) % mPoints.size();

		auto p3 = mPoints[i];
		auto p4 = mPoints[j];

		auto t = Intersection(p0r, p1r, p3, p4);
		if(t >= 0) 
		{
			intersection.X = p0.X + (t * p1.X - p0.X);
			intersection.Y = p0.Y + (t * p1.Y - p0.Y);

			return true;
		}
	}

	return false;
}

/**
 * Internal (private) function for intersection testings of two line segements
 * \param p0 Line segment 1 first point
 * \param p1 Line segment 1 second point
 * \param p2 Line segment 2 first point
 * \param p3 Line segment 2 second point
 * \return T value for line segment 1 for the intersection point or -1 if no intersection.
 */
float CPolygon::Intersection(Gdiplus::PointF p0, Gdiplus::PointF p1, Gdiplus::PointF p2, Gdiplus::PointF p3)
{
	// Compute differentials for each segment in each axis
	REAL s1_x, s1_y, s2_x, s2_y;
	s1_x = p1.X - p0.X;     s1_y = p1.Y - p0.Y;
	s2_x = p3.X - p2.X;     s2_y = p3.Y - p2.Y;

	REAL s, t;
	s = (-s1_y * (p0.X - p2.X) + s1_x * (p0.Y - p2.Y)) / (-s2_x * s1_y + s1_x * s2_y);
	t = (s2_x * (p0.Y - p2.Y) - s2_y * (p0.X - p2.X)) / (-s2_x * s1_y + s1_x * s2_y);

	if (s >= 0 && s <= 1 && t >= 0 && t <= 1)
	{
		// Collision detected
		return t;
	}

	return -1;
}

/**
 * Configure a brush to use for the texture map. 
 *
 * It makes the bounds of the texture map be the extents of the polygon.
 * Optionally, the texture can be centered on the origin (0, 0)
 * \return A configured texture brush.
 */
std::shared_ptr<Gdiplus::TextureBrush> CPolygon::Texture::Configue()
{
    //
    // Find minimum and maximum x and y values
    //
    PointF min = mPolygon->mPoints[0];
    PointF max = mPolygon->mPoints[0];
    for (PointF p : mPolygon->mPoints)
    {
        if (p.X < min.X)
        {
            min.X = p.X;
        }

        if (p.X > max.X)
        {
            max.X = p.X;
        }

        if (p.Y < min.Y)
        {
            min.Y = p.Y;
        }

        if (p.Y > max.Y)
        {
            max.Y = p.Y;
        }
    }

	// If we center, then minX = -maxX and minY = -maxY
	if (mCenter)
	{
		max.X = min.X < max.X ? max.X : min.X;
		min.X = -max.X;
		max.Y = min.Y < max.Y ? max.Y : min.Y;
		min.Y = -max.Y;

	}

    mBrush->ResetTransform();
    mBrush->TranslateTransform(min.X, min.Y);
    mBrush->ScaleTransform((max.X - min.X) / mTexture->GetWidth(),
        (max.Y - min.Y) / mTexture->GetHeight());

	return mBrush;
}


/**
 * Rotate a point p by r radians
 * \param p Point to rotate
 * \param r Angle of rotation in radians
 * \return Rotated point
 */
Gdiplus::PointF CPolygon::Rotate(Gdiplus::PointF p, double r)
{
	PointF pp;
	REAL sr = (REAL)sin(r);
	REAL cr = (REAL)cos(r);
	pp.X = cr * p.X - sr * p.Y;
	pp.Y = sr * p.X + cr * p.Y;
	return pp;
}
