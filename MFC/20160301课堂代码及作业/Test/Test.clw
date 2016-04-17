; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMyButton
LastTemplate=CButton
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Test.h"

ClassCount=5
Class1=CTestApp
Class2=CTestDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_TEST_DIALOG
Resource2=IDR_MAINFRAME
Class4=CMyEdit
Class5=CMyButton
Resource3=IDD_ABOUTBOX
Resource4=IDR_MENU1

[CLS:CTestApp]
Type=0
HeaderFile=Test.h
ImplementationFile=Test.cpp
Filter=N

[CLS:CTestDlg]
Type=0
HeaderFile=TestDlg.h
ImplementationFile=TestDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CTestDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=TestDlg.h
ImplementationFile=TestDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_TEST_DIALOG]
Type=1
Class=CTestDlg
ControlCount=10
Control1=IDC_EDIT1,edit,1350631552
Control2=IDC_EDIT2,edit,1350631552
Control3=IDC_EDIT_PATH,edit,1350631552
Control4=IDC_BTN_PATH,button,1342242816
Control5=IDC_EDIT_TEXT,edit,1353777284
Control6=IDC_BTN_READ,button,1342242816
Control7=IDC_BTN_WRITE,button,1342242816
Control8=IDC_BTN_SAVA,button,1342242816
Control9=IDC_STATIC,static,1342308352
Control10=IDC_BUTTON5,button,1342242816

[CLS:CMyEdit]
Type=0
HeaderFile=MyEdit.h
ImplementationFile=MyEdit.cpp
BaseClass=CEdit
Filter=W
VirtualFilter=WC

[CLS:CMyButton]
Type=0
HeaderFile=MyButton.h
ImplementationFile=MyButton.cpp
BaseClass=CButton
Filter=W

[MNU:IDR_MENU1]
Type=1
Class=?
Command1=IDM_OPEN
CommandCount=1

