#if !defined(AFX_WMPCDROMCOLLECTION_H__62916EC8_F500_4CBC_8379_B3556C582FEB__INCLUDED_)
#define AFX_WMPCDROMCOLLECTION_H__62916EC8_F500_4CBC_8379_B3556C582FEB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


// Dispatch interfaces referenced by this interface
class CWMPCdrom;

/////////////////////////////////////////////////////////////////////////////
// CWMPCdromCollection wrapper class

class CWMPCdromCollection : public COleDispatchDriver
{
public:
	CWMPCdromCollection() {}		// Calls COleDispatchDriver default constructor
	CWMPCdromCollection(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CWMPCdromCollection(const CWMPCdromCollection& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	long GetCount();
	CWMPCdrom Item(long lIndex);
	CWMPCdrom getByDriveSpecifier(LPCTSTR bstrDriveSpecifier);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WMPCDROMCOLLECTION_H__62916EC8_F500_4CBC_8379_B3556C582FEB__INCLUDED_)