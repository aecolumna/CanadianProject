/**
 * \file MachineDemoDlg.h
 * The machine demostration dialog box class
 * \author Charles Owen
 */


#pragma once
#include "afxcmn.h"
#include "afxwin.h"

#include "MachineDemoView.h"

/**
 * The machine demonstration dialog box class
 */
class CMachineDemoDlg : public CDialogEx
{
public:
	CMachineDemoDlg(CWnd* pParent = NULL);	// standard constructor

	/// Dialog box ID
	enum { IDD = IDD_MACHINEDEMO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;  ///< Icon handle

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
    afx_msg void OnSize(UINT nType, int cx, int cy);
    afx_msg void OnBnClickedButtonNewMachine();

private:
    int mFrameNum = 0;			///< Frame number, assumed 30 frames per second
    double mSpeed = 1;			///< Machine speed from 0 to 1

    void UpdateUI();
    CSliderCtrl mTimeSlider;    ///< The time/frame slider
    CStatic mFrame;             ///< Current frame
        
    CMachineDemoView mMachineView;    ///< The machine viewer window
    CSliderCtrl mSpeedSlider;	///< The speed slider
   
    CStatic mMachineNumberView;		///< View were we put the machine number
	CButton mPlayButton;		///< The Play button control
	CButton mStopButton;		///< The Stop button control
	CButton mRwButton;			///< The Rewind button control

public:
	afx_msg void OnBnClickedPlay();
	afx_msg void OnBnClickedStop();
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	UINT_PTR mTimer = 0;	///< The ID for the timer that controls playback

	long long mLastTime;    ///< Last time we read the timer
	double mTimeFreq;       ///< Rate the timer updates

	double mTime = 0;		///< Running time
	afx_msg void OnBnClickedRw();

	CStatic mControls;		///< Container for dialog box controls
};
