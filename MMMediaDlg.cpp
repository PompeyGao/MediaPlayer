// MMMediaDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MMMedia.h"
#include "MMMediaDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

int spaceflag=1;
int i;

/////////////////////////////////////////////////////////////////////////////
// CMMMediaDlg dialog

CMMMediaDlg::CMMMediaDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMMMediaDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMMMediaDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMMMediaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMMMediaDlg)
	DDX_Control(pDX, IDC_LIST1, m_lctrl);
	DDX_Control(pDX, IDC_OCX1, m_player);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMMMediaDlg, CDialog)
	//{{AFX_MSG_MAP(CMMMediaDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_OPEN, OnOpen)
	ON_BN_CLICKED(IDC_PLAY, OnPlay)
	ON_BN_CLICKED(IDC_PAUSE, OnPause)
	ON_BN_CLICKED(IDC_STOP, OnStop)
	ON_BN_CLICKED(IDC_FORWARD, OnForward)
	ON_BN_CLICKED(IDC_REVERSE, OnReverse)
	ON_BN_CLICKED(IDC_FULL, OnFull)
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	ON_BN_CLICKED(IDC_ABOUT, OnAbout)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_DEV, OnDev)
	ON_BN_CLICKED(IDC_SLIENCE, OnSlience)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	ON_BN_CLICKED(IDC_LAST, OnLast)
	ON_BN_CLICKED(IDC_NEXT, OnNext)
	ON_BN_CLICKED(IDC_OUT, OnOut)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	ON_BN_CLICKED(IDC_IN, OnIn)
	ON_BN_CLICKED(IDC_DELETEALL, OnDeleteall)
	ON_BN_CLICKED(IDC_UP, OnUp)
	ON_BN_CLICKED(IDC_DOWN, OnDown)

	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMMMediaDlg message handlers

BOOL CMMMediaDlg::OnInitDialog()
{
	CDialog::OnInitDialog();


	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_control=static_cast<CWMPControls>(m_player.GetControls());
    m_setting=m_player.GetSettings();
    m_list=static_cast<CWMPPlaylist>(m_player.GetCurrentPlaylist());
    m_media=static_cast<CWMPMedia>(m_player.GetCurrentMedia());
	CRect rect;
	m_lctrl.GetClientRect(&rect);
	m_lctrl.SetExtendedStyle(m_lctrl.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_lctrl.InsertColumn(0,_T("名称"),LVCFMT_CENTER,2*rect.Width()/4,0);
	m_lctrl.InsertColumn(1,_T("格式"),LVCFMT_CENTER,rect.Width()/4,1);
	m_lctrl.InsertColumn(2,_T("时间"),LVCFMT_CENTER,rect.Width()/4,2);
	m_lctrl.InsertColumn(3,NULL,LVCFMT_CENTER,0,3);
	m_lctrl.InsertColumn(4,NULL,LVCFMT_CENTER,0,4);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMMMediaDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMMMediaDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMMMediaDlg::OnOpen() 
{
	// TODO: Add your control notification handler code here
	m_lctrl.SetFocus();CString str;
	POSITION pos;
	pos = m_lctrl.GetFirstSelectedItemPosition();
	i=m_lctrl.GetNextSelectedItem(pos);
	m_lctrl.SetItemState(i,~LVIS_SELECTED,LVIS_SELECTED);
	TCHAR szFilter[] = _T("Mp3 File(*.mp3)|*.mp3|Wma File(*.wma)|*.wma|Video File(*.dat)|*.dat|Wave File(*.wav)|*.wav|AVI File(*.avi)|*.avi|Movie File(*.mov)|*.mov|Media File(*.mmm)|*.mmm|Mid File(*.mid;*,rmi)|*.mid;*.rmi|MPEG File(*.mpeg)|*.mpeg|All File(*.*)|*.*||");
	CFileDialog fileDlg(TRUE,NULL, NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, this);
	CString strFilePath;
	if (IDOK == fileDlg.DoModal())
	{
		strFilePath = fileDlg.GetPathName();
		strFilePath.MakeUpper();
		m_player.SetUrl(strFilePath);
		m_media=static_cast<CWMPMedia>(m_player.newMedia(strFilePath));
		m_list.appendItem(m_media);	
		m_lctrl.InsertItem(0,m_media.GetName());
		m_lctrl.SetItemText(0,1,_T(m_media.getItemInfo("FileType")));
		m_lctrl.SetItemText(0,2,_T(m_media.GetDurationString()));
		m_lctrl.SetItemText(0,3,_T(strFilePath));
		m_lctrl.SetItemText(0,4,_T(m_media.getItemInfo("Duration")));
		m_player.SetUrl(m_lctrl.GetItemText(0,3));
		m_lctrl.SetItemState(0,LVIS_SELECTED,LVIS_SELECTED);

	}

	
}

void CMMMediaDlg::OnPlay() 
{
	// TODO: Add your control notification handler code here
	CFileFind finder;
	if(m_list.GetCount()<=0)
	{
		MessageBox("列表无文件！","Warning",MB_OK);
		spaceflag=1;
	}
	else
	{
		if(!finder.FindFile(m_player.GetUrl()))
		{
			MessageBox("文件不存在，该项将被删除！","Warning",MB_OK);
			CMMMediaDlg::OnDelete();
		}
		else
		{
			m_control.play();
			if(m_control.GetCurrentPosition()==0)
				m_control.SetCurrentPosition(0.01);
			spaceflag=0;
		}
	}

	
}

void CMMMediaDlg::OnPause() 
{
	// TODO: Add your control notification handler code here
	m_control.pause();
	spaceflag=1;	
}

void CMMMediaDlg::OnStop() 
{
	// TODO: Add your control notification handler code here
	m_control.stop();
	
}

void CMMMediaDlg::OnForward() 
{
	// TODO: Add your control notification handler code here
	double t = m_control.GetCurrentPosition();
	m_control.SetCurrentPosition(t=t+10);	

	
}

void CMMMediaDlg::OnReverse() 
{
	// TODO: Add your control notification handler code here
	double t = m_control.GetCurrentPosition();
	m_control.SetCurrentPosition(t=t-10);	

	
}

void CMMMediaDlg::OnFull() 
{
	// TODO: Add your control notification handler code here
	if(m_control.GetCurrentPosition()!=0&&!m_player.GetFullScreen())
	{
		m_control.pause();
		m_player.SetFullScreen(true);
		m_control.play();

	}	

	
}

void CMMMediaDlg::OnExit() 
{
	// TODO: Add your control notification handler code here
	CMMMediaDlg::OnStop();
	SendMessage(WM_CLOSE);

	
}

void CMMMediaDlg::OnAbout() 
{
	// TODO: Add your control notification handler code here
	CAbout aboutDlg;
	aboutDlg.DoModal();

	
}

void CMMMediaDlg::OnAdd() 
{
	// TODO: Add your control notification handler code here
	m_setting.SetVolume(m_setting.GetVolume()+10);
	
}

void CMMMediaDlg::OnDev() 
{
	// TODO: Add your control notification handler code here
	int Volume=m_setting.GetVolume();
	m_setting.SetVolume(Volume=Volume-10);

	
}

void CMMMediaDlg::OnSlience() 
{
	// TODO: Add your control notification handler code here
	if(!m_setting.GetMute())
		m_setting.SetMute(true);
		else
		m_setting.SetMute(false);

	
}

void CMMMediaDlg::OnDelete() 
{
	// TODO: Add your control notification handler code here
	m_lctrl.SetFocus();	
	POSITION pos;CString strname;
	int num;
	UINT flag1 = LVIS_SELECTED|LVIS_FOCUSED;
	pos = m_lctrl.GetFirstSelectedItemPosition();
	i = m_lctrl.GetNextSelectedItem(pos); 
	if(i == -1)
	{
		AfxMessageBox("列表内没有被选中项！");
		return;
	}
	num=i;
	m_lctrl.DeleteItem(num);
	CMMMediaDlg::OnStop();
	if(m_lctrl.GetItemCount()!=0)
	{
		if(i == m_lctrl.GetItemCount())
		{
			m_lctrl.SetItemState(i-1, flag1, flag1);
			strname=m_lctrl.GetItemText(i-1,3);
			m_player.SetUrl(strname);
		}
		else
		{
			m_lctrl.SetItemState(i, flag1, flag1);
			strname=m_lctrl.GetItemText(i,3);
			m_player.SetUrl(strname);
		}
		CMMMediaDlg::OnPlay();
	}

	
}


void CMMMediaDlg::OnDeleteall() 
{
	// TODO: Add your control notification handler code here
	CMMMediaDlg::OnStop();
	int m=m_lctrl.GetItemCount(),j;
	for(j=m-1;j>=0;j--)
	{
		m_lctrl.DeleteItem(j);
	}

	
}

void CMMMediaDlg::OnUp() 
{
	// TODO: Add your control notification handler code here
	m_lctrl.SetFocus();	
	POSITION pos;
	int num;
	CString name;
	CString form;
	CString length;
	CString strName;
	CString duration;
	UINT flag1 = LVIS_SELECTED|LVIS_FOCUSED;	
	pos = m_lctrl.GetFirstSelectedItemPosition();
	i = m_lctrl.GetNextSelectedItem(pos); 
	if(i == -1)
	{
		AfxMessageBox("列表内没有被选中项！");
		return;
	}
	if(i == 0)
	{
		AfxMessageBox("已经到了列表头部！");
		m_lctrl.SetItemState(i, flag1, flag1);
		return;
	}
	num=i;
	name=m_lctrl.GetItemText(num,0);
	form=m_lctrl.GetItemText(num,1);
	length=m_lctrl.GetItemText(num,2);
	strName=m_lctrl.GetItemText(num,3);
	duration=m_lctrl.GetItemText(num,4);
	m_lctrl.DeleteItem(num);
	m_lctrl.InsertItem(num-1,_T(name));
	m_lctrl.SetItemText(num-1,1,_T(form));
	m_lctrl.SetItemText(num-1,2,_T(length));
	m_lctrl.SetItemText(num-1,3,_T(strName));
	m_lctrl.SetItemText(num-1,4,_T(duration));
	m_lctrl.SetItemState(i-1, flag1, flag1);

	
}

void CMMMediaDlg::OnDown() 
{
	// TODO: Add your control notification handler code here
	m_lctrl.SetFocus();	
	POSITION pos;
	int num;
	CString name;
	CString form;
	CString length;
	CString strName;
	CString duration;
	UINT flag1 = LVIS_SELECTED|LVIS_FOCUSED;
	pos = m_lctrl.GetFirstSelectedItemPosition();
	i = m_lctrl.GetNextSelectedItem(pos); 
	if(i == -1)
	{
		AfxMessageBox("列表内没有被选中项！");
		return;
	}
	if(i == m_lctrl.GetItemCount()-1)
	{
		AfxMessageBox("已经到了列表末尾！");
		m_lctrl.SetItemState(i, flag1, flag1);
		return;
	}
	num=i;
	name=m_lctrl.GetItemText(num,0);
	form=m_lctrl.GetItemText(num,1);
	length=m_lctrl.GetItemText(num,2);
	strName=m_lctrl.GetItemText(num,3);
	duration=m_lctrl.GetItemText(num,4);
	m_lctrl.DeleteItem(num);
	m_lctrl.InsertItem(num+1,_T(name));
	m_lctrl.SetItemText(num+1,1,_T(form));
	m_lctrl.SetItemText(num+1,2,_T(length));
	m_lctrl.SetItemText(num+1,3,_T(strName));
	m_lctrl.SetItemText(num+1,4,_T(duration));
	m_lctrl.SetItemState(i+1, flag1, flag1);

	
}

void CMMMediaDlg::OnLast() 
{
	// TODO: Add your control notification handler code here
	m_lctrl.SetFocus();	
	POSITION pos;CString strName;
	UINT flag1 = LVIS_SELECTED|LVIS_FOCUSED;	
	pos = m_lctrl.GetFirstSelectedItemPosition();
	i = m_lctrl.GetNextSelectedItem(pos); 
	if(i == -1)
	{
		AfxMessageBox("列表无选中项！");
		return;
	}
	if(i == 0)
	{
		AfxMessageBox("已到列表头部！");
		m_lctrl.SetItemState(i, flag1, flag1);
		return;
	}
	m_lctrl.SetItemState(i,~LVIS_SELECTED,LVIS_SELECTED);
	m_lctrl.SetItemState(i-1, flag1, flag1);
	strName=m_lctrl.GetItemText(i-1,3);
	CMMMediaDlg::OnStop();
	m_player.SetUrl(strName);
	CMMMediaDlg::OnPlay();

	
}

void CMMMediaDlg::OnNext() 
{
	// TODO: Add your control notification handler code here
	m_lctrl.SetFocus();	
	POSITION pos;CString strName;
	UINT flag1 = LVIS_SELECTED|LVIS_FOCUSED;
	pos = m_lctrl.GetFirstSelectedItemPosition();
	i = m_lctrl.GetNextSelectedItem(pos); 
	if(i == -1)
	{
		AfxMessageBox("列表内没有被选中项！");
		return;
	}
	if(i == m_lctrl.GetItemCount()-1)
	{
		AfxMessageBox("已经到了列表末尾！");
		m_lctrl.SetItemState(i, flag1, flag1);
		return;
	}
	m_lctrl.SetItemState(i,~LVIS_SELECTED,LVIS_SELECTED);
	m_lctrl.SetItemState(i+1, flag1, flag1);
	strName=m_lctrl.GetItemText(i+1,3);
	CMMMediaDlg::OnStop();
	m_player.SetUrl(strName);
	CMMMediaDlg::OnPlay();

	
}

void CMMMediaDlg::OnIn() 
{
	// TODO: Add your control notification handler code here
	m_lctrl.SetFocus();
	TCHAR szFilter[] = _T("列表文件(*.list)|*.list||");   
    // 构造打开文件对话框   
    CFileDialog fileDlg(TRUE, _T("list"), NULL, 0, szFilter, this);   
    CString strFilePath;   
  
    // 显示打开文件对话框   
    if (IDOK == fileDlg.DoModal())   
    {   
        // 如果点击了文件对话框上的"打开"按钮，则将选择的文件路径显示到编辑框里   
        strFilePath = fileDlg.GetPathName();  
	}
	CStdioFile file;int k;
	if(file.Open(strFilePath,CFile::modeRead|CFile::typeText))
	{
		POSITION pos;
		pos = m_lctrl.GetFirstSelectedItemPosition();
		i = m_lctrl.GetNextSelectedItem(pos); 
		m_lctrl.SetItemState(i,~LVIS_SELECTED,LVIS_SELECTED);
		file.SeekToBegin();
		CString str;CString strtemp[6];
		while(file.ReadString(str))
		{
			for(k=0;i<5;i++)
			AfxExtractSubString(strtemp[k],str,k,'|');
			m_lctrl.InsertItem(0,strtemp[0]);    //列表插入了第一行 ，用insertitem （列表控件的函数）
			for(int j=1;j<5;j++)             //循环插入 用 for 循环
				m_lctrl.SetItemText(0,j,_T(strtemp[j])); 
			
			m_player.SetUrl(strtemp[3]);
			m_media=static_cast<CWMPMedia>(m_player.newMedia(strFilePath));
			m_list.appendItem(m_media);	
		}
		m_player.SetUrl(m_lctrl.GetItemText(0,3));
		m_lctrl.SetItemState(0,LVIS_SELECTED,LVIS_SELECTED);
	}
	else
	{
		TRACE("Can't open list file!");
	}
	file.Close();

	
}

void CMMMediaDlg::OnOut() 
{
	// TODO: Add your control notification handler code here
	TCHAR szFilter[]=_T("列表文件(*.list)|*.list||");
		CFileDialog fileDlg(FALSE,_T("list"),NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, this); 
		CString strFilePath;
	    if (IDOK == fileDlg.DoModal())   
    {   
        // 如果点击了文件对话框上的"保存"按钮，则将选择的文件路径显示到编辑框里   
        strFilePath = fileDlg.GetPathName();   
    }  
		CStdioFile file;int i,j;
	if(file.Open(strFilePath,CFile::modeCreate|CFile::modeReadWrite|CFile::typeText))
	{
		
		for(i=m_lctrl.GetItemCount()-1;i>=0;i--)
		{
			CString temp;
			for(j=0;j<4;j++)
			{
				
				temp=m_lctrl.GetItemText(i,j);
				temp+="|";
				file.WriteString(temp);
			}
			temp=m_lctrl.GetItemText(i,j);
			temp+="\n";
			file.WriteString(temp);
		}
		file.Close();
	}
	else
	{
		TRACE("Can't Open File");
	}


	
}

BOOL CMMMediaDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(pMsg->message==WM_KEYDOWN)
	{
		switch(pMsg->wParam)
		{
		case VK_ESCAPE:
			{
				if(m_control.GetCurrentPosition()!=0&&m_player.GetFullScreen())
					m_player.SetFullScreen(false);
				else
					SendMessage(WM_CLOSE);
				return TRUE;
				break;
			}
		case VK_SPACE:
			{
				if(spaceflag==0)
					CMMMediaDlg::OnPause();
				else
					if(spaceflag==1)
						CMMMediaDlg::OnPlay();
				return TRUE;
				break;
			}
		case VK_LEFT:
			{
				CMMMediaDlg::OnReverse();
				return TRUE;
				break;
			}
		case VK_RIGHT:
			{
				CMMMediaDlg::OnForward();
				return TRUE;
				break;
			}
		case VK_PRIOR:
			{
				CMMMediaDlg::OnLast();
				return TRUE;
				break;
			}
		case VK_NEXT:
			{
				CMMMediaDlg::OnNext();
				return TRUE;
				break;
			}
		case VK_UP:
			{
				CMMMediaDlg::OnAdd();
				return TRUE;
				break;
			}
		case VK_DOWN:
			{
				CMMMediaDlg::OnDev();
				return TRUE;
				break;
			}
		default:
			return TRUE;
			break;
		}
	}

	
	return CDialog::PreTranslateMessage(pMsg);
}

void CMMMediaDlg::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	
LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);   

	// TODO: Add your control notification handler code here
	NMLISTVIEW *pNMListView = (NMLISTVIEW*)pNMHDR;
	*pResult = 0;
	CString strName;
	if(-1 !=pNMListView->iItem)
	{
		strName=m_lctrl.GetItemText(pNMListView->iItem,3);
		CMMMediaDlg::OnStop();
		m_player.SetUrl(strName);
		CMMMediaDlg::OnPlay();
	}
}


