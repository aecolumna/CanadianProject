/**
 * \file MachineDlg.h
 *
 * \author Charles Owen
 *
 * Class that implements a dialog box for machine seeds
 */

#pragma once

#include <memory>

class CMachine;

/**
* Exported dialog box class for entering a machine seed
*
* You can't open a Dialog Box from a remote DLL, so
* this class is a wrapper that creates and calls DoModal
* on the dialog box in this class.
*
* You are not allowed to change this class in any way!
*
* AFX_EXT_CLASS is a Microsoft directive that indicates
* that this class can be used outside the DLL. Do not change
* it or add it to any other classes.
*/
class AFX_EXT_CLASS CMachineDlg
{
public:
    /**
     * Constructor
     * \param machine Machine we are editing the seed for 
     */
    CMachineDlg(std::shared_ptr<CMachine> machine);
    INT_PTR DoModal();

private:
    /// Machine we are editing
    std::shared_ptr<CMachine> mMachine;
};

/**
 * Dialog box class for entering a Machine Seed.
 *
 * This is the actual MFC dialog box class.
 *
 * \cond
 */
class CMachineActualDlg : public CDialog
{
	DECLARE_DYNAMIC(CMachineActualDlg)

public:
	CMachineActualDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CMachineActualDlg();

    virtual INT_PTR DoModal() override;

    int GetSeed() { return mSeed; }
    void SetSeed(int seed) { mSeed = seed; }

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedButtonrandom();

private:
    int mSeed = 99;

    CBrush mBrushBack;

public:
    virtual BOOL OnInitDialog();
    afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};

/// \endcond
