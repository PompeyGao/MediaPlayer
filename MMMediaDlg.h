// MMMediaDlg.h : header file
//
//{{AFX_INCLUDES()
#include "wmpplayer4.h"
#include "wmpcontrols.h"
#include "wmpsettings.h"
#include "wmpplaylist.h"
#include "wmpmedia.h"

//}}AFX_INCLUDES

#if !defined(AFX_MMMEDIADLG_H__793CBFA7_6D69_4EF0_AE00_D5D5428E6A2C__INCLUDED_)
#define AFX_MMMEDIADLG_H__793CBFA7_6D69_4EF0_AE00_D5D5428E6A2C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "About.h"
/////////////////////////////////////////////////////////////////////////////
// CMMMediaDlg dialog

class CMMMediaDlg : public CDialog
{
// Construction
public:
	CMMMediaDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMMMediaDlg)
	enum { IDD = IDD_MMMEDIA_DIALOG };
	CListCtrl	m_lctrl;
	CWMPPlayer4	m_player;
	CWMPControls m_control;
	CWMPSettings m_setting;
	CString	m_position;
	CWMPPlaylist m_list;
	CWMPMedia m_media;

	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMMMediaDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMMMediaDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnOpen();
	afx_msg void OnPlay();
	afx_msg void OnPause();
	afx_msg void OnStop();
	afx_msg void OnForward();
	afx_msg void OnReverse();
	afx_msg void OnFull();
	afx_msg void OnExit();
	afx_msg void OnAbout();
	afx_msg void OnAdd();
	afx_msg void OnDev();

	afx_msg void OnDelete();
	afx_msg void OnLast();
	afx_msg void OnNext();
	afx_msg void OnOut();
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnIn();
	afx_msg void OnDeleteall();
	afx_msg void OnUp();
	afx_msg void OnDown();
	afx_msg void OnSlience();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MMMEDIADLG_H__793CBFA7_6D69_4EF0_AE00_D5D5428E6A2C__INCLUDED_)
