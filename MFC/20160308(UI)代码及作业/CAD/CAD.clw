; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMyTree
LastTemplate=CTreeView
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "cad.h"
LastPage=0

ClassCount=8
Class1=CCADApp
Class2=CAboutDlg
Class3=CCADDoc
Class4=CCADView
Class5=CMainFrame
Class6=CMyButton
Class7=CSettingDlg

ResourceCount=5
Resource1=IDR_MAINFRAME
Resource2=IDR_TOOLBAR1
Resource3=IDR_MENU1
Resource4=IDD_ABOUTBOX
Class8=CMyTree
Resource5=IDD_DIALOG1

[CLS:CCADApp]
Type=0
BaseClass=CWinApp
HeaderFile=CAD.h
ImplementationFile=CAD.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=CAD.cpp
ImplementationFile=CAD.cpp
LastObject=CAboutDlg

[CLS:CCADDoc]
Type=0
BaseClass=CDocument
HeaderFile=CADDoc.h
ImplementationFile=CADDoc.cpp

[CLS:CCADView]
Type=0
BaseClass=CView
HeaderFile=CADView.h
ImplementationFile=CADView.cpp
Filter=C
VirtualFilter=VWC

[CLS:CMainFrame]
Type=0
BaseClass=CFrameWnd
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp

[CLS:CMyButton]
Type=0
BaseClass=CButton
HeaderFile=MyButton.h
ImplementationFile=MyButton.cpp

[CLS:CSettingDlg]
Type=0
BaseClass=CDialog
HeaderFile=SettingDlg.h
ImplementationFile=SettingDlg.cpp

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=5
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_TREE1,SysTreeView32,1350631431

[DLG:IDD_DIALOG1]
Type=1
Class=CSettingDlg
ControlCount=12
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,button,1342177287
Control4=IDC_RADIO1,button,1342308361
Control5=IDC_RADIO2,button,1342177289
Control6=IDC_RADIO3,button,1342177289
Control7=IDC_RADIO4,button,1342177289
Control8=IDC_STATIC,static,1342308352
Control9=IDC_EDIT_WIDTH,edit,1350631552
Control10=IDC_SPIN1,msctls_updown32,1342177312
Control11=IDC_BTN_COLOR,button,1342242816
Control12=IDC_EDIT_PEN_COLOR,edit,1350631552

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[TB:IDR_TOOLBAR1]
Type=1
Class=?
Command1=IDM_TEST
Command2=IDM_LINE
Command3=IDM_RECT
Command4=IDM_SELECT
CommandCount=4

[MNU:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_REDO
Command12=ID_EDIT_CUT
Command13=ID_EDIT_COPY
Command14=ID_EDIT_PASTE
Command15=ID_VIEW_TOOLBAR
Command16=ID_VIEW_STATUS_BAR
Command17=ID_APP_ABOUT
Command18=IDM_RECT
Command19=IDM_LINE
Command20=IDM_SELECT
Command21=IDM_SETTING
Command22=IDM_SCREEN
CommandCount=22

[MNU:IDR_MENU1]
Type=1
Class=?
Command1=IDM_EDIT
Command2=ID_MENUITEM32781
Command3=ID_MENUITEM32782
Command4=ID_MENUITEM32778
Command5=ID_MENUITEM32776
Command6=ID_MENUITEM32777
CommandCount=6

[ACL:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_EDIT_COPY
Command2=ID_FILE_NEW
Command3=ID_FILE_OPEN
Command4=ID_FILE_PRINT
Command5=ID_FILE_SAVE
Command6=ID_EDIT_PASTE
Command7=ID_EDIT_UNDO
Command8=ID_EDIT_CUT
Command9=ID_NEXT_PANE
Command10=ID_PREV_PANE
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_EDIT_CUT
Command14=ID_EDIT_REDO
Command15=ID_EDIT_UNDO
CommandCount=15

[CLS:CMyTree]
Type=0
HeaderFile=MyTree.h
ImplementationFile=MyTree.cpp
BaseClass=CTreeView
Filter=C
VirtualFilter=VWC

