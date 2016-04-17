; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CWM_COPYDATADlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "WM_COPYDATA.h"

ClassCount=4
Class1=CWM_COPYDATAApp
Class2=CWM_COPYDATADlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_WM_COPYDATA_DIALOG

[CLS:CWM_COPYDATAApp]
Type=0
HeaderFile=WM_COPYDATA.h
ImplementationFile=WM_COPYDATA.cpp
Filter=N

[CLS:CWM_COPYDATADlg]
Type=0
HeaderFile=WM_COPYDATADlg.h
ImplementationFile=WM_COPYDATADlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=WM_COPYDATADlg.h
ImplementationFile=WM_COPYDATADlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_WM_COPYDATA_DIALOG]
Type=1
Class=CWM_COPYDATADlg
ControlCount=1
Control1=IDC_BUTTON1,button,1342242816

