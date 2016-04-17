; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CUDPClientDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "UDPClient.h"

ClassCount=4
Class1=CUDPClientApp
Class2=CUDPClientDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_UDPCLIENT_DIALOG

[CLS:CUDPClientApp]
Type=0
HeaderFile=UDPClient.h
ImplementationFile=UDPClient.cpp
Filter=N

[CLS:CUDPClientDlg]
Type=0
HeaderFile=UDPClientDlg.h
ImplementationFile=UDPClientDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=UDPClientDlg.h
ImplementationFile=UDPClientDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_UDPCLIENT_DIALOG]
Type=1
Class=CUDPClientDlg
ControlCount=2
Control1=IDC_EDIT1,edit,1350631552
Control2=IDC_BUTTON1,button,1342242817

