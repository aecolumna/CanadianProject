/**
* \file AnimChannelPoint.h
*
* \brief An animation channel specific to points (movement)
*
* \author Charles B. Owen
*/

#pragma once
#include "AnimChannel.h"

/** \brief An animation channel specific to points (movement)
*/
class CAnimChannelPoint :
    public CAnimChannel
{
public:
    CAnimChannelPoint();
    ~CAnimChannelPoint();

    /// \brief The point we compute
    /// \return The computed point
    Gdiplus::Point GetPoint() { return mPoint; }

    /// \brief A keyframe for a point channel
    class KeyframePoint : public Keyframe
    {
    public:
        /** \brief Constructor
        * \param channel The channel we are for
        * \param point The animation position for the keyframe */
        KeyframePoint(CAnimChannelPoint *channel, Gdiplus::Point point) :
            Keyframe(channel), mChannel(channel), mPoint(point) {}

        /** \brief Default constructor disabled */
        KeyframePoint() = delete;
        /** \brief Copy constructor disabled */
        KeyframePoint(const KeyframePoint &) = delete;
        /** \brief Assignment operator disabled */
        void operator=(const KeyframePoint &) = delete;

        /// \brief The keyframe point
        /// \return The keyframe point
        Gdiplus::Point GetPoint() { return mPoint; }

        /** \brief Use this keyframe as keyframe 1 */
        virtual void UseAs1() override { mChannel->mKeyframe1 = this; }

        /** \brief Use this keyframe as keyfraem 2 */
        virtual void UseAs2() override { mChannel->mKeyframe2 = this; }

        /** \brief Use this keyframe as the angle */
        virtual void UseOnly() override { mChannel->mPoint = mPoint; }

        virtual std::shared_ptr<xmlnode::CXmlNode> XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node);

    private:
        /// The keyframe point
        Gdiplus::Point mPoint = Gdiplus::Point(0, 0);

        /// The channel this keyframe is associated with
        CAnimChannelPoint *mChannel;
    };

    void SetKeyframe(Gdiplus::Point point);
    void Tween(double t);

protected:
    virtual void XmlLoadKeyframe(const std::shared_ptr<xmlnode::CXmlNode> &node) override;

private:
    /// The point we compute
    Gdiplus::Point mPoint = Gdiplus::Point(0, 0);

    /// The first angle keyframe
    KeyframePoint *mKeyframe1 = nullptr;

    /// The second angle keyframe
    KeyframePoint *mKeyframe2 = nullptr;
};

