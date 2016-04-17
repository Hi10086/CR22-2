; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMemoryDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Enum.h"

ClassCount=5
Class1=CEnumApp
Class2=CEnumDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_ENUM_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_DIALOG1
Class4=CMyStatic
Resource4=IDD_ABOUTBOX
Class5=CMemoryDlg
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
Class=CMemoryDlg
ControlCount=7
Control1=IDC_STATIC,static,1342308865
Control2=IDC_EDIT_ADDRESS,edit,1350631552
Control3=IDC_STATIC,static,1342308865
Control4=IDC_EDIT_SIZE,edit,1350631552
Control5=IDC_BTN_READ,button,1342242816
Control6=IDC_BTN_WRITE,button,1342242816
Control7=IDC_EDIT_TEXT,edit,1350631552

[CLS:CMemoryDlg]
Type=0
HeaderFile=MemoryDlg.h
ImplementationFile=MemoryDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CMemoryDlg
VirtualFilter=dWC

