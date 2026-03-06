// SPiiPlusCLibraryDemo.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "SPiiPlusCLibraryDemo.h"
#include "SPiiPlusCLibraryDemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSPiiPlusCLibraryDemoApp

BEGIN_MESSAGE_MAP(CSPiiPlusCLibraryDemoApp, CWinApp)
	//{{AFX_MSG_MAP(CSPiiPlusCLibraryDemoApp)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSPiiPlusCLibraryDemoApp construction

CSPiiPlusCLibraryDemoApp::CSPiiPlusCLibraryDemoApp()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CSPiiPlusCLibraryDemoApp object

CSPiiPlusCLibraryDemoApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CSPiiPlusCLibraryDemoApp initialization

BOOL CSPiiPlusCLibraryDemoApp::InitInstance()
{
//TODO: call AfxInitRichEdit2() to initialize richedit2 library.
	AfxEnableControlContainer();

	// Standard initialization

	CSPiiPlusCLibraryDemoDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
	}
	else if (nResponse == IDCANCEL)
	{
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
