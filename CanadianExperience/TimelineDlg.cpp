/**
 * \file TimelineDlg.cpp
 *
 * \author Charles B. Owen
 */


#include "stdafx.h"
#include "CanadianExperience.h"
#include "TimelineDlg.h"
#include "afxdialogex.h"


IMPLEMENT_DYNAMIC(CTimelineDlg, CDialog)


/**
 * \brief Constructor
 * \param pParent Parent window or NULL if none
 */
CTimelineDlg::CTimelineDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTimelineDlg::IDD, pParent)
    , mNumFrames(0)
    , mFrameRate(0)
{

}


/**
 * \brief Destructor
 */
CTimelineDlg::~CTimelineDlg()
{
}


/**
 * \brief Exchange data between the dialog box and local variables.
 * \param pDX 
 */
void CTimelineDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_NUMFRAMES, mNumFrames);
    DDV_MinMaxInt(pDX, mNumFrames, 10, 10000);
    DDX_Text(pDX, IDC_FRAMERATE, mFrameRate);
	DDV_MinMaxInt(pDX, mFrameRate, 1, 60);
}


BEGIN_MESSAGE_MAP(CTimelineDlg, CDialog)
END_MESSAGE_MAP()


/**
* \brief Pass a timeline object to this dialog box class.
* \param timeline The timeline object.
*/
void CTimelineDlg::SetTimeline(CTimeline *timeline)
{
    mTimeline = timeline;
    mNumFrames = mTimeline->GetNumFrames();
    mFrameRate = mTimeline->GetFrameRate();
}

/** \brief Transfer dialog values to the Timeline object
*/
void CTimelineDlg::Take()
{
    mTimeline->SetNumFrames(mNumFrames);
    mTimeline->SetFrameRate(mFrameRate);
}
