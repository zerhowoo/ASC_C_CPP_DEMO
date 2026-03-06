// SPiiPlusCLibraryDemo.h : main header file for the SPIIPLUSCLIBRARYDEMO application
//

#if !defined(AFX_SPIIPLUSCLIBRARYDEMO_H__2F7A9195_8C3E_4D2C_95D0_06115DD37D4B__INCLUDED_)
#define AFX_SPIIPLUSCLIBRARYDEMO_H__2F7A9195_8C3E_4D2C_95D0_06115DD37D4B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSPiiPlusCLibraryDemoApp:
// See SPiiPlusCLibraryDemo.cpp for the implementation of this class
//

class CSPiiPlusCLibraryDemoApp : public CWinApp
{
public:
	CSPiiPlusCLibraryDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSPiiPlusCLibraryDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSPiiPlusCLibraryDemoApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPIIPLUSCLIBRARYDEMO_H__2F7A9195_8C3E_4D2C_95D0_06115DD37D4B__INCLUDED_)
