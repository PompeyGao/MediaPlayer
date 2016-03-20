; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMMMediaDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MMMedia.h"

ClassCount=3
Class1=CMMMediaApp
Class2=CMMMediaDlg

ResourceCount=3
Resource2=IDD_MMMEDIA_DIALOG
Resource1=IDR_MAINFRAME
Class3=CAbout
Resource3=IDD_DIALOG1

[CLS:CMMMediaApp]
Type=0
HeaderFile=MMMedia.h
ImplementationFile=MMMedia.cpp
Filter=N

[CLS:CMMMediaDlg]
Type=0
HeaderFile=MMMediaDlg.h
ImplementationFile=MMMediaDlg.cpp
Filter=D
LastObject=CMMMediaDlg
BaseClass=CDialog
VirtualFilter=dWC



[DLG:IDD_MMMEDIA_DIALOG]
Type=1
Class=CMMMediaDlg
ControlCount=25
Control1=IDC_OCX1,{6BF52A52-394A-11D3-B153-00C04F79FAA6},1342242816
Control2=IDC_OPEN,button,1342242816
Control3=IDC_PLAY,button,1342242816
Control4=IDC_PAUSE,button,1342242816
Control5=IDC_STOP,button,1342242816
Control6=IDC_FORWARD,button,1342242816
Control7=IDC_REVERSE,button,1342242816
Control8=IDC_FULL,button,1342242816
Control9=IDC_EXIT,button,1342242816
Control10=IDC_ABOUT,button,1342242816
Control11=IDC_LIST1,SysListView32,1350631425
Control12=IDC_STATIC,button,1342177287
Control13=IDC_STATIC,button,1342177287
Control14=IDC_STATIC,button,1342177287
Control15=IDC_ADD,button,1342242816
Control16=IDC_DEV,button,1342242816
Control17=IDC_DELETE,button,1342242816
Control18=IDC_LAST,button,1342242816
Control19=IDC_NEXT,button,1342242816
Control20=IDC_OUT,button,1342242816
Control21=IDC_IN,button,1342242816
Control22=IDC_DELETEALL,button,1342242816
Control23=IDC_UP,button,1342242816
Control24=IDC_DOWN,button,1342242816
Control25=IDC_SLIENCE,button,1342242819

[DLG:IDD_DIALOG1]
Type=1
Class=CAbout
ControlCount=2
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342177283

[CLS:CAbout]
Type=0
HeaderFile=About.h
ImplementationFile=About.cpp
BaseClass=CDialog
Filter=D

