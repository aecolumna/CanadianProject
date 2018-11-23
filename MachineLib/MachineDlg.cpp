/**
 * \file MachineDlg.cpp
 *
 * \author Charles Owen
 *
 * You are not allowed to change these classes in any way!
 *
*/

#include "stdafx.h"
#include "MachineLib.h"
#include "MachineDlg.h"
#include "afxdialogex.h"
#include "Machine.h"


/**
 * Open the dialog box as a modal dialog box
 * \returns Dialog box return value
 */
INT_PTR CMachineDlg::DoModal()
{
    AFX_MANAGE_STATE(AfxGetStaticModuleState());
    CMachineActualDlg dlg;
    dlg.SetSeed(mMachine->GetMachineNumber());
    INT_PTR ret = dlg.DoModal();
    if (ret == IDOK)
    {
        int seed = dlg.GetSeed();
        mMachine->SetMachineNumber(seed);
    }
    return ret;
}



/** \cond */
IMPLEMENT_DYNAMIC(CMachineActualDlg, CDialog)

CMachineActualDlg::CMachineActualDlg(CWnd* pParent /*=NULL*/)
    : CDialog(IDD_MACHINEDLG, pParent), mBrushBack(RGB(255, 255, 255))
{

}

INT_PTR CMachineActualDlg::DoModal()
{
   // 
    return CDialog::DoModal();
}

CMachineActualDlg::~CMachineActualDlg()
{
}

void CMachineActualDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_EDITSEED, mSeed);
}


BEGIN_MESSAGE_MAP(CMachineActualDlg, CDialog)
    ON_BN_CLICKED(IDC_BUTTONRANDOM, &CMachineActualDlg::OnBnClickedButtonrandom)
    ON_WM_CTLCOLOR()
END_MESSAGE_MAP()

/**
 * Constructor
 */
CMachineDlg::CMachineDlg(std::shared_ptr<CMachine> machine) : mMachine(machine)
{

}


void CMachineActualDlg::OnBnClickedButtonrandom()
{
    mSeed = rand();
    UpdateData(false);
}




BOOL CMachineActualDlg::OnInitDialog()
{
    CDialog::OnInitDialog();

    return TRUE;  // return TRUE unless you set the focus to a control
    // EXCEPTION: OCX Property Pages should return FALSE
}


HBRUSH CMachineActualDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
    HBRUSH hBrush = NULL;
    switch (nCtlColor)
    {
    case CTLCOLOR_DLG:
        // just return a not NULL brush handle
        hBrush = (HBRUSH)mBrushBack;
        break;

    default:
        // do the default processing
        hBrush = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
        break;
    }
    return hBrush;
}

/** \endcond */
