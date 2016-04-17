; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CCTL2Dlg
LastTemplate=CButton
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "CTL2.h"

ClassCount=4
Class1=CCTL2App
Class2=CCTL2Dlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CMyButton
Resource3=IDD_CTL2_DIALOG

[CLS:CCTL2App]
Type=0
HeaderFile=CTL2.h
ImplementationFile=CTL2.cpp
Filter=N

[CLS:CCTL2Dlg]
Type=0
HeaderFile=CTL2Dlg.h
ImplementationFile=CTL2Dlg.cpp
Filter=D
LastObject=IDOK
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=CTL2Dlg.h
ImplementationFile=CTL2Dlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_CTL2_DIALOG]
Type=1
Class=CCTL2Dlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_BUTTON1,button,1342242816
Control4=IDC_BUTTON2,button,1342242816

[CLS:CMyButton]
Type=0
HeaderFile=MyButton.h
ImplementationFile=MyButton.cpp
BaseClass=CButton
Filter=W
VirtualFilter=BWC

