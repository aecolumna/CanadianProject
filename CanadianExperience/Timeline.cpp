/**
 * \file Timeline.cpp
 *
 * \author Charles B. Owen
 */

#include "stdafx.h"
#include "Timeline.h"

using namespace xmlnode;

/**
 * \brief Constructor
 */
CTimeline::CTimeline()
{
}


/**
 * \brief Destructor
 */
CTimeline::~CTimeline()
{
}



/**
 * \brief Add an animation channel to the timeline
 * \param channel Channel to add
 */
void CTimeline::AddChannel(CAnimChannel *channel)
{
    mChannels.push_back(channel);
    channel->SetTimeline(this);
}


/** \brief Sets the current time
*
* Ensures all of the channels are
* valid for that point in time.
* \param t The new time to set
*/
void CTimeline::SetCurrentTime(double t)
{
    // Set the time
    mCurrentTime = t;

    for (auto channel : mChannels)
    {
        channel->SetFrame(GetCurrentFrame());
    }
}


/** \brief Clear any keyframe at the current time.
*/
void CTimeline::ClearKeyframe()
{
    for (auto channel : mChannels)
    {
        channel->ClearKeyframe();
    }
}


/**
 * \brief Save the timeline animation to a file
 * \param root XML document root node
 */
void CTimeline::Save(std::shared_ptr<xmlnode::CXmlNode> root)
{
    root->SetAttribute(L"numframes", mNumFrames);
    root->SetAttribute(L"framerate", mFrameRate);

    for (auto channel : mChannels)
    {
        channel->XmlSave(root);
    }
}



/**
* \brief Load a timeline animation from a file
* \param root XML document root node
*/
void CTimeline::Load(std::shared_ptr<xmlnode::CXmlNode> root)
{
    // Once we know it is open, clear the existing data
    Clear();

    // Get the attributes
    mNumFrames = root->GetAttributeIntValue(L"numframes", 300);
    mFrameRate = root->GetAttributeIntValue(L"framerate", 30);

    for (auto node : root->GetChildren())
    {
        if (node->GetType() == NODE_ELEMENT && node->GetName() == L"channel")
        {
            XmlChannel(node);
        }
    }

}


/**
 * \brief Handle the "channel" XML tag.
 * \param node Node that is the channel tag.
 */
void CTimeline::XmlChannel(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
    // Get the channel name
    auto name = node->GetAttributeValue(L"name", L"");

    // Find the channel
    for (auto channel : mChannels) 
    {
        if (channel->GetName() == name)
        {
            // We found it, let it handle it
            channel->XmlLoad(node);
            break;
        }
    }
}



/** 
 * \brief Clear all keyframes 
 */
void CTimeline::Clear()
{
    // Reset the current time and restore to defaults.
    mCurrentTime = 0;
    mNumFrames = 300;
    mFrameRate = 30;

    for (auto channel : mChannels)
    {
        channel->Clear();
    }
}