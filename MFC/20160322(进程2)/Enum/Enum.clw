; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMoudleDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Enum.h"

ClassCount=5
Class1=CEnumApp
Class2=CEnumDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_DIALOG1
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Class4=CMyStatic
Resource4=IDD_ENUM_DIALOG
Class5=CMoudleDlg
Resource5=IDR_MENU1

[CLS:CEnumApp]
Type=0
HeaderFile=Enum.h
ImplementationFile=Enum.cpp
Filter=N

[CLS:CEnumDlg]
Type=0
HeaderFile=EnumDlg.h
ImplementationFile=EnumDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CEnumDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=EnumDlg.h
ImplementationFile=EnumDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_ENUM_DIALOG]
Type=1
Class=CEnumDlg
ControlCount=2
Control1=IDC_LIST1,SysListView32,1350631425
Control2=IDC_MY_STATIC,static,1342177550

[MNU:IDR_MENU1]
Type=1
Class=?
Command1=IDM_ENUM_PROCESS
Command2=IDM_MODULE
Command3=IDM_THREAD
Command4=IDM_WINDOW
Command5=IDM_MEMORY
Command6=ID_MENUITEM32776
Command7=ID_MENUITEM32777
Command8=ID_MENUITEM32778
CommandCount=8

[CLS:CMyStatic]
Type=0
HeaderFile=MyStatic.h
ImplementationFile=MyStatic.cpp
BaseClass=CStatic
Filter=W
VirtualFilter=WC

[DLG:IDD_DIALOG1]
Type=1
Class=CMoudleDlg
ControlCount=2
Control1=IDOK,button,1342242816
Control2=IDC_LIST2,SysListView32,1350631425

[CLS:CMoudleDlg]
Type=0
HeaderFile=MoudleDlg.h
ImplementationFile=MoudleDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_LIST2
VirtualFilter=dWC

