/**
 * \file Polygon.h
 *
 * \author Charles Owen
 *
 * Generic polygon class that is used to make shapes we
 * will use in our project.
 */

#pragma once

#include <vector>
#include <memory>
#include <string>

/**
 * Generic polygon class that is used to make shapes we 
 * will use in our project.
 */
class CPolygon
{
public:
    CPolygon();
    virtual ~CPolygon();

    /// Add a point to the polygon
    /// \param x X value for point
    /// \param y Y value for point
    void AddPoint(int x, int y) { mPoints.push_back(Gdiplus::PointF((float)x, (float)y)); }

    /// Add a point to the polygon. Convenience version that accepts doubles.
    /// \param x X value for point
    /// \param y Y value for point
    void AddPoint(double x, double y) { AddPoint((int)x, (int)y); }

    void Rectangle(int x, int y, int wid, int hit);
    void CenteredSquare(int size);
	void Circle(double radius, int steps = 0);

    void SetColor(Gdiplus::Color color);

    void SetImage(std::wstring filename, bool center=false);

    void DrawPolygon(Gdiplus::Graphics *graphics, int x, int y);

    /// Set the rotation of the polygon
    /// \param rotation Rotation in turns, where 0-1 is one revolution.
    void SetRotation(double rotation) { mRotation = rotation; }

    /// Get the rotation of the polygon
    /// \return rotation Rotation in turns, where 0-1 is one revolution.
    double GetRotation() { return mRotation; }

	/// Set the phase. This is an optional value that is added
	/// to the rotation when the rotation is set. It provides a 
	/// way to radially align an image.
	/// \param phase Phase to set in the range 0 to 1
	void SetPhase(double phase) { mPhase = phase; }

	/// Get the phase. This is an optional value that is added
	/// to the rotation when the rotation is set. It provides a 
	/// way to radially align an image.
	/// \return Phase value that is set in the range 0 to 1
	double GetPhase() const { return mPhase; } 

	bool Intersection(Gdiplus::PointF p0, Gdiplus::PointF p1, Gdiplus::PointF &intersection);
	bool Intersection(double angle, Gdiplus::PointF &intersection);

private:
    /// The points that make up the polygon
    std::vector<Gdiplus::PointF> mPoints;

    /// A brush to draw the polygon with
    std::shared_ptr<Gdiplus::Brush> mBrush;

    /// Any amount to rotate the polygon in turns
    /// 0 to 1 is one complete rotation
    double mRotation = 0;

	/// Optional added rotation value. Is added to 
	/// mRotation when the rotation is set.
	/// 0 to 1 is a complete rotation
	double mPhase = 0;

	/// Nested class that describes any texturing.
	class Texture 
	{
	public:
		Texture(CPolygon *polygon, std::wstring filename, bool center);

		std::shared_ptr<Gdiplus::TextureBrush> Configue();

	private:
		/// If we are using a textured brush, this will be it
		std::shared_ptr<Gdiplus::TextureBrush> mBrush;

		/// If we are using a texture image, this is it
		std::shared_ptr<Gdiplus::Bitmap> mTexture;

		/// If true, the texture is centered on (0,0)
		bool mCenter;

		/// Polygon that is using this texture
		CPolygon *mPolygon;
	};

	/// Optional texture object
	std::shared_ptr<Texture> mTexture;

	float Intersection(Gdiplus::PointF p1, Gdiplus::PointF p2, Gdiplus::PointF p3, Gdiplus::PointF p4);

	static Gdiplus::PointF Rotate(Gdiplus::PointF p, double r);
};

