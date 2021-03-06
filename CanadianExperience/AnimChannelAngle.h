/**
 * \file AnimChannelAngle.h
 *
 * \author Charles B. Owen
 *
 * \brief Animation channel for angles
 */

#pragma once
#include "AnimChannel.h"


/**
 * \brief Animation channel for angles
 */
class CAnimChannelAngle :
    public CAnimChannel
{
public:
    CAnimChannelAngle();
    virtual ~CAnimChannelAngle();
   
    /** \brief Get the current time angle 
     * \return Angle in radians */
    double GetAngle() { return mAngle; }

    /// \brief A keyframe for an angle channel
    class KeyframeAngle : public Keyframe
    {
    public:
        /** \brief Constructor
        * \param channel The channel we are for
        * \param angle The angle for the keyframe */
        KeyframeAngle(CAnimChannelAngle *channel, double angle) :
            Keyframe(channel), mChannel(channel), mAngle(angle) {}

        /** \brief Destructor */
        ~KeyframeAngle();

        /** \brief Default constructor disabled */
        KeyframeAngle() = delete;
        /** \brief Copy constructor disabled */
        KeyframeAngle(const KeyframeAngle &) = delete;
        /** \brief Assignment operator disabled */
        void operator=(const KeyframeAngle &) = delete;

        /** \brief Get the angle at this keyframe 
         * \returns Angle in radians */
        double GetAngle() { return mAngle; }

        /** \brief Use this keyframe as keyframe 1 */
        virtual void UseAs1() override { mChannel->mKeyframe1 = this; }

        /** \brief Use this keyframe as keyfraem 2 */
        virtual void UseAs2() override { mChannel->mKeyframe2 = this; }

        /** \brief Use this keyframe as the angle */
        virtual void UseOnly() override { mChannel->mAngle = mAngle; }

        virtual std::shared_ptr<xmlnode::CXmlNode> XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node);


    private:
        double mAngle;  ///< The angle for this keyframe

        /// The channel this keyframe is associated with
        CAnimChannelAngle *mChannel;
    };

    void SetKeyframe(double angle);
    void Tween(double t);

protected:
    virtual void XmlLoadKeyframe(const std::shared_ptr<xmlnode::CXmlNode> &node) override;

private:
    double mAngle = 0;  ///< The computed animation angle

    /// The first angle keyframe
    KeyframeAngle *mKeyframe1 = nullptr;

    /// The second angle keyframe
    KeyframeAngle *mKeyframe2 = nullptr;
};

