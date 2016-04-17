; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMyThread
LastTemplate=CWinThread
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MFCThread.h"

ClassCount=5
Class1=CMFCThreadApp
Class2=CMFCThreadDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=CMyThread
Resource3=IDD_MFCTHREAD_DIALOG

[CLS:CMFCThreadApp]
Type=0
HeaderFile=MFCThread.h
ImplementationFile=MFCThread.cpp
Filter=N

[CLS:CMFCThreadDlg]
Type=0
HeaderFile=MFCThreadDlg.h
ImplementationFile=MFCThreadDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=MFCThreadDlg.h
ImplementationFile=MFCThreadDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MFCTHREAD_DIALOG]
Type=1
Class=CMFCThreadDlg
ControlCount=2
Control1=IDC_BUTTON1,button,1342242816
Control2=IDC_BUTTON2,button,1342242816

[CLS:CMyThread]
Type=0
HeaderFile=MyThread.h
ImplementationFile=MyThread.cpp
BaseClass=CWinThread
Filter=N
VirtualFilter=TC

