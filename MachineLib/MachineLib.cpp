/**
 * \file MachineLib.cpp
 *
 * \author Charles Owen
 */


#include "stdafx.h"
#include "MachineLib.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


BEGIN_MESSAGE_MAP(CMachineLibApp, CWinApp)
END_MESSAGE_MAP()


/**
 * Constructor
 */
CMachineLibApp::CMachineLibApp()
{
}


/// The one and only CMachineLibApp object
CMachineLibApp theApp;


/**
 * CMachineLibApp initialization
 * \returns 
 */
BOOL CMachineLibApp::InitInstance()
{
	CWinApp::InitInstance();
    srand((unsigned int)time(nullptr));
	return TRUE;
}

