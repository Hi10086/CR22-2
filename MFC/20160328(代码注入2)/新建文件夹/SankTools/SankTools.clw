; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CThreadDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "sanktools.h"
LastPage=0

ClassCount=7
Class1=CModuleDlg
Class2=CMyProcessDlg
Class3=CSankToolsApp
Class4=CAboutDlg
Class5=CSankToolsDlg

ResourceCount=7
Resource1=IDD_SANKTOOLS_DIALOG
Resource2=IDD_MODULE_DLG
Resource3=IDD_ABOUTBOX
Resource4=IDD_THREAD_DLG
Resource5=IDD_PRO_DLG
Class6=CInjectDlg
Resource6=IDD_INJECT_DIALOG
Class7=CThreadDlg
Resource7=IDR_MENU_PROCESS

[CLS:CModuleDlg]
Type=0
BaseClass=CDialog
HeaderFile=ModuleDlg.h
ImplementationFile=ModuleDlg.cpp
Filter=D
VirtualFilter=dWC
LastObject=CModuleDlg

[CLS:CMyProcessDlg]
Type=0
BaseClass=CDialog
HeaderFile=MyProcessDlg.h
ImplementationFile=MyProcessDlg.cpp
LastObject=CMyProcessDlg
Filter=D
VirtualFilter=dWC

[CLS:CSankToolsApp]
Type=0
BaseClass=CWinApp
HeaderFile=SankTools.h
ImplementationFile=SankTools.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=SankToolsDlg.cpp
ImplementationFile=SankToolsDlg.cpp

[CLS:CSankToolsDlg]
Type=0
BaseClass=CDialog
HeaderFile=SankToolsDlg.h
ImplementationFile=SankToolsDlg.cpp

[DLG:IDD_MODULE_DLG]
Type=1
Class=CModuleDlg
ControlCount=1
Control1=IDC_LIST1,SysListView32,1350631425

[DLG:IDD_PRO_DLG]
Type=1
Class=CMyProcessDlg
ControlCount=1
Control1=IDC_LIST1,SysListView32,1350631425

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_SANKTOOLS_DIALOG]
Type=1
Class=CSankToolsDlg
ControlCount=1
Control1=IDC_TAB,SysTabControl32,1342177280

[MNU:IDR_MENU_PROCESS]
Type=1
Class=?
Command1=ID_MENU_PRO_FLUSH
Command2=ID_MENU_PRO_MODULE
Command3=ID_MENU_PRO_THREAD
Command4=ID_MENU_PRO_INJECT
Command5=ID_MENU_MODULE_FLUSH
Command6=ID_MENU_MODULE_INGECT
Command7=ID_MENU_THREAD_MSG
CommandCount=7

[DLG:IDD_INJECT_DIALOG]
Type=1
Class=CInjectDlg
ControlCount=11
Control1=IDC_EDIT_DLL_PATH,edit,1350631552
Control2=IDC_EDIT_MAP_VALUE,edit,1350631552
Control3=IDC_DLL_SEL,button,1342242816
Control4=IDC_BUTTON_INJECT,button,1342242816
Control5=IDC_BUTTON_END,button,1342242816
Control6=IDC_CHECK_MEM_MAP,button,1342242819
Control7=IDC_STATIC,button,1342177287
Control8=IDC_STATIC,button,1342177287
Control9=IDC_EDIT_MAP_VALUE_RETURN,edit,1350631552
Control10=IDC_EDIT_MAPOBJ_NAME,edit,1350631552
Control11=IDC_STATIC,static,1342308352

[CLS:CInjectDlg]
Type=0
HeaderFile=InjectDlg.h
ImplementationFile=InjectDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CInjectDlg
VirtualFilter=dWC

[DLG:IDD_THREAD_DLG]
Type=1
Class=CThreadDlg
ControlCount=1
Control1=IDC_LIST1,SysListView32,1350631425

[CLS:CThreadDlg]
Type=0
HeaderFile=ThreadDlg.h
ImplementationFile=ThreadDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CThreadDlg

