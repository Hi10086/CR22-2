; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMyButton
LastTemplate=CButton
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Create.h"

ClassCount=4
Class1=CCreateApp
Class2=CCreateDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CMyButton
Resource3=IDD_CREATE_DIALOG

[CLS:CCreateApp]
Type=0
HeaderFile=Create.h
ImplementationFile=Create.cpp
Filter=N

[CLS:CCreateDlg]
Type=0
HeaderFile=CreateDlg.h
ImplementationFile=CreateDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CCreateDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=CreateDlg.h
ImplementationFile=CreateDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_CREATE_DIALOG]
Type=1
Class=CCreateDlg
ControlCount=3
Control1=IDC_BUTTON1,button,1342242816
Control2=IDC_BUTTON2,button,1342242816
Control3=IDC_BUTTON3,button,1342242816

[CLS:CMyButton]
Type=0
HeaderFile=MyButton.h
ImplementationFile=MyButton.cpp
BaseClass=CButton
Filter=W
VirtualFilter=BWC

