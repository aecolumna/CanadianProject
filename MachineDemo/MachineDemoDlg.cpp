/**
 * \file MachineDemoDlg.cpp
 *
 * \author Charles Owen
 */

#include "stdafx.h"
#include <string>
#include <sstream>

#include "MachineDemo.h"
#include "MachineDemoDlg.h"
#include "MachineDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;

/// The bottom border below the machine window in pixels
const int BottomBorder = 100;

/// Maximum speed
const double MaxSpeed = 1;

/**
 * Constructor
 * \param pParent Parent window (optional)
 */
CMachineDemoDlg::CMachineDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMachineDemoDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

    srand((unsigned int)time(NULL));
}

/**
 * Exchange data between the dialog box and variables
 * \param pDX Data exchange object
 */
void CMachineDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TIMESLIDER, mTimeSlider);
	DDX_Control(pDX, IDC_FRAME, mFrame);
	DDX_Control(pDX, IDC_BENDSLIDER, mSpeedSlider);
	DDX_Control(pDX, IDC_MACHINESEED, mMachineNumberView);
	DDX_Control(pDX, IDC_PLAY, mPlayButton);
	DDX_Control(pDX, IDC_STOP, mStopButton);
	DDX_Control(pDX, IDC_RW, mRwButton);
	DDX_Control(pDX, IDC_CONTROLS, mControls);
}

/** \cond */
BEGIN_MESSAGE_MAP(CMachineDemoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_WM_HSCROLL()
    ON_WM_SIZE()
    ON_BN_CLICKED(IDC_BUTTONNEWMACHINE, &CMachineDemoDlg::OnBnClickedButtonNewMachine)
	ON_BN_CLICKED(IDC_PLAY, &CMachineDemoDlg::OnBnClickedPlay)
	ON_BN_CLICKED(IDC_STOP, &CMachineDemoDlg::OnBnClickedStop)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_RW, &CMachineDemoDlg::OnBnClickedRw)
END_MESSAGE_MAP()
/** \endcond */


/**
 * Initialize the dialog box
 * \returns TRUE on success
 */
BOOL CMachineDemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	CBitmap bmpPlay;
	bmpPlay.LoadBitmapW(IDB_BITMAPPLAY);
	mPlayButton.SetBitmap(bmpPlay);

	CBitmap bmpStop;
	bmpStop.LoadBitmapW(IDB_BITMAPSTOP);
	mStopButton.SetBitmap(bmpStop);

	CBitmap bmpRw;
	bmpRw.LoadBitmapW(IDB_BITMAPRW);
	mRwButton.SetBitmap(bmpRw);

    mTimeSlider.SetRange(0, 300, TRUE);
    mTimeSlider.SetPageSize(30);
    mTimeSlider.SetTicFreq(30);

    mSpeedSlider.SetRange(0, 100, TRUE);
	mSpeedSlider.SetPos(100);
    mSpeedSlider.SetPageSize(10);
    mSpeedSlider.SetTicFreq(10);

    CRect rect;
    GetClientRect(&rect);

	CRect playRect;
	mControls.GetWindowRect(&playRect);
	ScreenToClient(&playRect);

	int height = playRect.top;
	int padding = playRect.left;

	mMachineView.Create(this, CRect(padding, padding, rect.Width() - padding, height - padding), 1, WS_VISIBLE | WS_CHILD);

    UpdateUI();

	return TRUE;  // return TRUE  unless you set the focus to a control
}



/**
 * Paint the dialog box
 */
void CMachineDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

/**
 * The system calls this function to obtain the cursor to display while the user drags
 * the minimized window. 
 * \return Cursor handle
 */
HCURSOR CMachineDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}





/**
 * Handle a horizontal scroll message
 * \param nSBCode Message code
 * \param nPos Position of the scroll
 * \param pScrollBar Source scroll bar object
 */
void CMachineDemoDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
    mFrameNum = mTimeSlider.GetPos();
    mSpeed = mSpeedSlider.GetPos() * MaxSpeed / mSpeedSlider.GetRangeMax();
    UpdateUI();

    CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}

/**
 * Update the user interface to match the current object state 
 */
void CMachineDemoDlg::UpdateUI() 
{
    wstringstream str;
    str << "Frame: " << mFrameNum << endl;
    mFrame.SetWindowTextW(str.str().c_str());

	mMachineView.SetSpeed(mSpeed);
	mMachineView.SetFrameRate(30.0);
    mMachineView.SetFrame(mFrameNum);

    wstringstream str2;
    str2 << "Machine: " << mMachineView.GetMachine()->GetMachineNumber() << endl;
    mMachineNumberView.SetWindowTextW(str2.str().c_str());
}


/**
 * Handle a size message
 * \param nType Type of size request
 * \param cx New width
 * \param cy New height
 */
void CMachineDemoDlg::OnSize(UINT nType, int cx, int cy)
{
    CDialogEx::OnSize(nType, cx, cy);

    CRect rect;
    GetClientRect(&rect);

    if (IsWindow(mMachineView.m_hWnd)) {
        mMachineView.MoveWindow(0, 0, rect.Width(), rect.Height() - BottomBorder);
    }
}
    


/**
 * Handle the New Machine button press
 */
void CMachineDemoDlg::OnBnClickedButtonNewMachine()
{
    CMachineDlg dlg(mMachineView.GetMachine());
    if (dlg.DoModal() == IDOK) {
        UpdateUI();
        mMachineView.SetFrame(0);
        mMachineView.SetFrame(mFrameNum);
    }
}


/**
 * Handle a play button click
 */
void CMachineDemoDlg::OnBnClickedPlay()
{
	if (mTimer != 0) 
	{
		KillTimer(mTimer);
	}

	if (mFrameNum >= mTimeSlider.GetRangeMax())
	{
		// We are at the end
		return;
	}

	/*
	* Initialize the elapsed time system
	*/
	LARGE_INTEGER time, freq;
	QueryPerformanceCounter(&time);
	QueryPerformanceFrequency(&freq);

	mLastTime = time.QuadPart;
	mTimeFreq = double(freq.QuadPart);
	mTime = 0;

	mTimer = SetTimer(1, 16, nullptr);
}


/**
 * Handle a stop button press
 */
void CMachineDemoDlg::OnBnClickedStop()
{
	if (mTimer != 0)
	{
		KillTimer(mTimer);
		mTimer = 0;
	}
}


/**
 * Handle a Rewind button press
 */
void CMachineDemoDlg::OnBnClickedRw()
{
	OnBnClickedStop();

	mFrameNum = 0;
	mTimeSlider.SetPos(mFrameNum);
	UpdateUI();
}



/**
 * Handle the timer event
 * \param nIDEvent Event ID
 */
void CMachineDemoDlg::OnTimer(UINT_PTR nIDEvent)
{
	/*
	* Compute the elapsed time since the last draw
	*/
	LARGE_INTEGER time;
	QueryPerformanceCounter(&time);
	long long diff = time.QuadPart - mLastTime;
	double elapsed = double(diff) / mTimeFreq;
	mLastTime = time.QuadPart;

	/*
	 * This code ensures we move forward in real time
	 */
	mTime += elapsed;
	double frameDuration = 1.0 / 30.0;
	while (mTime >= frameDuration)
	{
		mTime -= frameDuration;
		mFrameNum++;
		mTimeSlider.SetPos(mFrameNum);
		UpdateUI();

		if (mFrameNum >= mTimeSlider.GetRangeMax())
		{
			OnBnClickedStop();
		}
	}

	CDialogEx::OnTimer(nIDEvent);
}

