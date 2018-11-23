/**
 * \file TimelineDlg.h
 *
 * \author Charles B. Owen
 *
 * \brief The timeline parameters dialog box.
 */

#pragma once

#include "Timeline.h"


/**
 * \brief The timeline parameters dialog box.
 */
class CTimelineDlg : public CDialog
{
	DECLARE_DYNAMIC(CTimelineDlg)

public:
	CTimelineDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CTimelineDlg();

// Dialog Data
	/// \cond
	enum { IDD = IDD_TIMELINEDLG };
	/// \endcond

    void SetTimeline(CTimeline *timeline);
    void Take();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

private:
    int mNumFrames;     ///< Number of frames in the animation
    int mFrameRate;     ///< Animation frame rate in frames per second

    /// The timeline we are editing
    CTimeline *mTimeline = nullptr;
};
