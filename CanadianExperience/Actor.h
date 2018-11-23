/**
 * \file Actor.h
 *
 * \author Charles B. Owen
 *
 * \brief Class for actors in our drawings
 */

#pragma once

#include "Drawable.h"
#include "AnimChannelPoint.h"

#include <string>
#include <memory>
#include <vector>

class CPicture;

/**
 * \brief Class for actors in our drawings.
 *
 * An actor is some graphical object that consists of 
 * one or more parts. Actors can be animated.
 */
class CActor
{
public:
    CActor(const std::wstring &name);

    /** \brief Default constructor disabled */
    CActor() = delete;
    /** \brief Copy constructor disabled */
    CActor(const CActor &) = delete;
    /** \brief Assignment operator disabled */
    void operator=(const CActor &) = delete;

    virtual ~CActor();

    void SetRoot(std::shared_ptr<CDrawable> root);

    /** \brief Get the root drawable for this actor 
     * \returns Pointer to root drawable */
    std::shared_ptr<CDrawable> GetRoot() { return mRoot; }
    void Draw(Gdiplus::Graphics *graphics);
    std::shared_ptr<CDrawable> HitTest(Gdiplus::Point pos);
    void AddDrawable(std::shared_ptr<CDrawable> drawable);

    /** \brief Get the actor name 
     * \returns Actor name */
    std::wstring GetName() const { return mName; }

    /** \brief The actor position
    * \returns The actor position as a point */
    Gdiplus::Point GetPosition() const { return mPosition; }

    /** \brief The actor position
    * \param pos The new actor position */
    void SetPosition(Gdiplus::Point pos) { mPosition = pos; }


    /** \brief Actor is enabled
    * \returns enabled status */
    bool IsEnabled() const { return mEnabled; }

    /** \brief Set Actor Enabled
    * \param enabled New enabled status */
    void SetEnabled(bool enabled) { mEnabled = enabled; }

    /** \brief Actor is clickable
    * \returns true if actor is clickable */
    bool IsClickable() const { return mClickable; }

    /** \brief Actor clickable
    * \param clickable New clickable status */
    void SetClickable(bool clickable) { mClickable = clickable; }

    void SetPicture(CPicture *picture);

    /** \brief Get the picture this actor is for 
     * \returns The picture object */
    CPicture *GetPicture() { return mPicture; }

    void SetKeyframe();
    void GetKeyframe();

    /** \brief The position animation channel
    * \returns Pointer to animation channel */
    CAnimChannelPoint *GetPositionChannel() { return &mChannel; }

private:
    /// The actor name
    std::wstring mName;

    /// Is this actor enabled (drawable)?
    bool mEnabled = true;

    /// The actor position
    Gdiplus::Point mPosition = Gdiplus::Point(0, 0);
    
    /// Is this actor mouse clickable?
    bool mClickable = true;

    /// The root drawable
    std::shared_ptr<CDrawable> mRoot;

    /// The drawables in drawing order
    std::vector<std::shared_ptr<CDrawable>> mDrawablesInOrder;

    /// The picture this actor is associated with
    CPicture *mPicture = nullptr;

    /// The actor position channel
    CAnimChannelPoint mChannel;
};

