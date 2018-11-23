/**
 * \file RotatedBitmap.h
 *
 * \author Charles B. Owen
 *
 * \brief Base class for a rotated bitmap.
 */

#pragma once

#include <memory>
#include <string>


/**
 * \brief Base class for a rotated bitmap.
 */
class CRotatedBitmap
{
public:
    CRotatedBitmap();
    virtual ~CRotatedBitmap();

    /** \brief Copy constructor disabled */
    CRotatedBitmap(const CRotatedBitmap &) = delete;
    /** \brief Assignment operator disabled */
    void operator=(const CRotatedBitmap &) = delete;

    void LoadImage(const std::wstring &filename);
    void DrawImage(Gdiplus::Graphics *graphics, Gdiplus::Point position, double angle);

    /** \brief Set the center to rotate around
     * \param center New center */
    void SetCenter(Gdiplus::Point center) { mCenter = center; }

    /** \brief Get the center to rotate around
     * \returns Center */
    Gdiplus::Point GetCenter() const { return mCenter; }

    /** \brief Is this bitmap loaded for use?
    * \returns true if loaded */
    bool IsLoaded() const { return mLoaded; }

protected:
    /// The image for this drawable
    std::unique_ptr<Gdiplus::Bitmap> mImage;

    /// The center of the image
    Gdiplus::Point mCenter = Gdiplus::Point(0, 0);

    /// Has an image been loaded?
    bool mLoaded = false;
};

