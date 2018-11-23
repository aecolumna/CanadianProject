/**
 * \file MachineDemoView.cpp
 *
 * \author Charles Owen
 */

#include "stdafx.h"
#include "MachineDemo.h"
#include "MachineDemoView.h"
#include "DoubleBufferDC.h"
#include "MachineFactory.h"

using namespace Gdiplus;

// Window class name for this view
#define VIEWER_CLASSNAME    _T("CMachineDemoView")  // Window class name

IMPLEMENT_DYNAMIC(CMachineDemoView, CWnd)

/**
 * Constructor
 */
CMachineDemoView::CMachineDemoView()
{
    RegisterWindowClass();

    //
    // Use a factory to create the machine object
    //
    CMachineFactory factory;
    mMachine = factory.CreateMachine();
}

/**
 * Destructor
 */
CMachineDemoView::~CMachineDemoView()
{
}

/**
 * Register this view as  a window
 * \return TRUE if successful
 */
BOOL CMachineDemoView::RegisterWindowClass()
{
    WNDCLASS wndcls;
    HINSTANCE hInst = AfxGetInstanceHandle();

    if (!(::GetClassInfo(hInst, VIEWER_CLASSNAME, &wndcls)))
    {
        // otherwise we need to register a new class
        wndcls.style = CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW;
        wndcls.lpfnWndProc = ::DefWindowProc;
        wndcls.cbClsExtra = wndcls.cbWndExtra = 0;
        wndcls.hInstance = hInst;
        wndcls.hIcon = NULL;
        wndcls.hCursor = AfxGetApp()->LoadStandardCursor(IDC_ARROW);
        wndcls.hbrBackground = (HBRUSH)(COLOR_3DFACE + 1);
        wndcls.lpszMenuName = NULL;
        wndcls.lpszClassName = VIEWER_CLASSNAME;

        if (!AfxRegisterClass(&wndcls))
        {
            AfxThrowResourceException();
            return FALSE;
        }
    }

    return TRUE;
}


/**
 * Create the view
 * \param pParentWnd Optional parent window
 * \param rect View rectanlge
 * \param nID ID for the view
 * \param dwStyle Window style
 * \returns true if successful
 */
BOOL CMachineDemoView::Create(CWnd* pParentWnd, const RECT& rect, UINT nID, DWORD dwStyle /*=WS_VISIBLE*/)
{
    int rootX = rect.right / 2;
    int rootY = rect.bottom - 100;
    mMachine->SetLocation(rootX, rootY);

	return CWnd::CreateEx(WS_EX_CLIENTEDGE, VIEWER_CLASSNAME, _T(""), dwStyle, rect, pParentWnd, nID);
    //return CWnd::Create(VIEWER_CLASSNAME, _T(""), dwStyle, rect, pParentWnd, nID);
}

/** \cond */
BEGIN_MESSAGE_MAP(CMachineDemoView, CWnd)
    ON_WM_PAINT()
    ON_WM_ERASEBKGND()
END_MESSAGE_MAP()
/** \endcond */


/**
 * Paint the view
 */
void CMachineDemoView::OnPaint()
{
    CPaintDC paintDC(this);     // device context for painting
    CDoubleBufferDC dc(&paintDC); // device context for painting

    Graphics graphics(dc.m_hDC);    // Create GDI+ graphics context

    mMachine->DrawMachine(&graphics);
}


/**
 * Handle an erase background message. Since we use CDoubleBufferDC, we ignore it
 * \param pDC Device context
 * \returns FALSE
 */
BOOL CMachineDemoView::OnEraseBkgnd(CDC* pDC)
{
    return FALSE;
}


/**
 * Set the current view frame
 * \param frame Frame number
 */
void CMachineDemoView::SetFrame(int frame) 
{
    mMachine->SetMachineFrame(frame);
    Invalidate();
}


/**
 * Set the machine frame rate
 * \param rate Frame rate in frames per second
 */
void CMachineDemoView::SetFrameRate(double rate)
{
	mMachine->SetFrameRate(rate);
	Invalidate();
}


/**
 * Set the bend angle
 * \param bend Bend angle in radians
 */
void CMachineDemoView::SetSpeed(double bend)
{
    mMachine->SetSpeed(bend);
    Invalidate();
}


/**
 * Set the machine number
 * \param machine Machine number
 */
void CMachineDemoView::SetMachineNumber(int machine)
{
    mMachine->SetMachineNumber(machine);
}
