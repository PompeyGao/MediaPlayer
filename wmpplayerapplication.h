#if !defined(AFX_WMPPLAYERAPPLICATION_H__7E750B44_A193_4F7B_BE1D_0E290C20D54D__INCLUDED_)
#define AFX_WMPPLAYERAPPLICATION_H__7E750B44_A193_4F7B_BE1D_0E290C20D54D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.

/////////////////////////////////////////////////////////////////////////////
// CWMPPlayerApplication wrapper class

class CWMPPlayerApplication : public COleDispatchDriver
{
public:
	CWMPPlayerApplication() {}		// Calls COleDispatchDriver default constructor
	CWMPPlayerApplication(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CWMPPlayerApplication(const CWMPPlayerApplication& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	void switchToPlayerApplication();
	void switchToControl();
	BOOL GetPlayerDocked();
	BOOL GetHasDisplay();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WMPPLAYERAPPLICATION_H__7E750B44_A193_4F7B_BE1D_0E290C20D54D__INCLUDED_)
