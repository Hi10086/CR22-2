; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CFileMapDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "FileMap.h"

ClassCount=4
Class1=CFileMapApp
Class2=CFileMapDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_FILEMAP_DIALOG

[CLS:CFileMapApp]
Type=0
HeaderFile=FileMap.h
ImplementationFile=FileMap.cpp
Filter=N

[CLS:CFileMapDlg]
Type=0
HeaderFile=FileMapDlg.h
ImplementationFile=FileMapDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=FileMapDlg.h
ImplementationFile=FileMapDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_FILEMAP_DIALOG]
Type=1
Class=CFileMapDlg
ControlCount=3
Control1=IDC_BUTTON1,button,1342242816
Control2=IDC_BUTTON2,button,1342242816
Control3=IDC_BUTTON3,button,1342242816

