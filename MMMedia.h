// MMMedia.h : main header file for the MMMEDIA application
//

#if !defined(AFX_MMMEDIA_H__36C068B4_7A64_4BA0_84E9_E09AFEC4C6D8__INCLUDED_)
#define AFX_MMMEDIA_H__36C068B4_7A64_4BA0_84E9_E09AFEC4C6D8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMMMediaApp:
// See MMMedia.cpp for the implementation of this class
//

class CMMMediaApp : public CWinApp
{
public:
	CMMMediaApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMMMediaApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMMMediaApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MMMEDIA_H__36C068B4_7A64_4BA0_84E9_E09AFEC4C6D8__INCLUDED_)
