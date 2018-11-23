/**
 * \file Picture.h
 *
 * \author Charles B. Owen
 *
 * \brief The picture we are drawing
 */

#pragma once

#include <vector>
#include "PictureObserver.h"
#include "Timeline.h"

class CActor;

/**
 * \brief The picture we are drawing.
 *
 * There will be one picture object that contains all of 
 * our actors, which then contains the drawables. 
 */
class CPicture
{
public:
    CPicture();
    virtual ~CPicture();

    /// \brief Copy Constructor (Disabled)
    CPicture(const CPicture &) = delete;
    /// \brief Assignment Operator (Disabled)
	/// \return disabled
    CPicture &operator=(const CPicture &) = delete;

    /** \brief The picture size
    * \return Size */
    Gdiplus::Size GetSize() { return mSize; }

    /** \brief The picture size
    * \param size The new picture size */
    void SetSize(Gdiplus::Size size) { mSize = size; }

    void AddObserver(CPictureObserver *observer);
    void RemoveObserver(CPictureObserver *observer);
    void UpdateObservers();
    void Draw(Gdiplus::Graphics *graphics);
    void AddActor(std::shared_ptr<CActor> actor);

    void Save(const std::wstring &filename);
    void Load(const std::wstring &filename);

    /** \brief Iterator that iterates over the actors in a picture */
    class ActorIter
    {
    public:
        /** \brief Constructor
        * \param picture Picture we are iterating
        * \param pos Starting position */
        ActorIter(CPicture *picture, int pos) : mPicture(picture), mPos(pos) {}

        /** \brief Test for end of the iterator
        * \param other Other object to test against
        * \returns True if we this position equals not equal to the other position */
        bool operator!=(const ActorIter &other) const
        {
            return mPos != other.mPos;
        }

        /** \brief Get value at current position
        * \returns Value at mPos in the collection */
        std::shared_ptr<CActor> operator *() const { return mPicture->mActors[mPos]; }

        /** \brief Increment the iterator
        * \returns Reference to this iterator */
        const ActorIter& operator++()
        {
            mPos++;
            return *this;
        }


    private:
        CPicture *mPicture; ///< Picture we are iterating over
        int mPos;           ///< Position in the collection
    };

    /** \brief Get an iterator for the beginning of the collection
    * \returns Iter object at position 0 */
    ActorIter begin() { return ActorIter(this, 0); }

    /** \brief Get an iterator for the end of the collection
    * \returns Iter object at position past the end */
    ActorIter end() { return ActorIter(this, mActors.size()); }

    /** \brief Get a pointer to the Timeline object
    * \returns Pointer to the Timeline object
    */
    CTimeline *GetTimeline() { return &mTimeline; }
    void SetAnimationTime(double time);
    double GetAnimationTime();

private:
    /// The picture size
    Gdiplus::Size mSize = Gdiplus::Size(800, 600);

    /// The observers of this picture
    std::vector<CPictureObserver *> mObservers;

    //! The actors associated with this picture
    std::vector<std::shared_ptr<CActor>> mActors;

    /// The animation timeline
    CTimeline mTimeline;
};

