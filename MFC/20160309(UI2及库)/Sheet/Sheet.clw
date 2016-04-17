; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CPage3
LastTemplate=CPropertyPage
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Sheet.h"

ClassCount=6
Class1=CSheetApp
Class2=CSheetDlg
Class3=CAboutDlg

ResourceCount=6
Resource1=IDD_DIALOG1
Resource2=IDR_MAINFRAME
Resource3=IDD_SHEET_DIALOG
Class4=CPage1
Resource4=IDD_ABOUTBOX
Resource5=IDD_DIALOG2
Class5=CPage2
Class6=CPage3
Resource6=IDD_DIALOG3

[CLS:CSheetApp]
Type=0
HeaderFile=Sheet.h
ImplementationFile=Sheet.cpp
Filter=N

[CLS:CSheetDlg]
Type=0
HeaderFile=SheetDlg.h
ImplementationFile=SheetDlg.cpp
Filter=D
LastObject=CSheetDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=SheetDlg.h
ImplementationFile=SheetDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_SHEET_DIALOG]
Type=1
Class=CSheetDlg
ControlCount=1
Control1=IDC_BUTTON1,button,1342242816

[DLG:IDD_DIALOG1]
Type=1
Class=CPage1
ControlCount=2
Control1=IDC_BUTTON1,button,1342242816
Control2=IDC_EDIT1,edit,1350631552

[CLS:CPage1]
Type=0
HeaderFile=Page1.h
ImplementationFile=Page1.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=CPage1
VirtualFilter=idWC

[DLG:IDD_DIALOG2]
Type=1
Class=CPage2
ControlCount=2
Control1=IDC_RADIO1,button,1342177289
Control2=IDC_RADIO2,button,1342177289

[DLG:IDD_DIALOG3]
Type=1
Class=CPage3
ControlCount=2
Control1=IDC_CHECK1,button,1342242819
Control2=IDC_CHECK2,button,1342242819

[CLS:CPage2]
Type=0
HeaderFile=Page2.h
ImplementationFile=Page2.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=CPage2
VirtualFilter=idWC

[CLS:CPage3]
Type=0
HeaderFile=Page3.h
ImplementationFile=Page3.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=CPage3
VirtualFilter=idWC

