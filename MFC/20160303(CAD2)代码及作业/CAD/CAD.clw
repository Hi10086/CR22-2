; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSettingDlg
LastTemplate=CButton
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "CAD.h"
LastPage=0

ClassCount=7
Class1=CCADApp
Class2=CCADDoc
Class3=CCADView
Class4=CMainFrame

ResourceCount=4
Resource1=IDR_MENU1
Class5=CAboutDlg
Resource2=IDD_ABOUTBOX
Class6=CSettingDlg
Class7=CMyButton
Resource3=IDR_MAINFRAME
Resource4=IDD_DIALOG1

[CLS:CCADApp]
Type=0
HeaderFile=CAD.h
ImplementationFile=CAD.cpp
Filter=N
BaseClass=CWinApp
VirtualFilter=AC

[CLS:CCADDoc]
Type=0
HeaderFile=CADDoc.h
ImplementationFile=CADDoc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC

[CLS:CCADView]
Type=0
HeaderFile=CADView.h
ImplementationFile=CADView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=CAD.cpp
ImplementationFile=CAD.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
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
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
Command17=IDM_LINE
Command18=IDM_RECT
Command19=IDM_SELECT
Command20=IDM_SETTING
CommandCount=20

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

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

[CLS:CSettingDlg]
Type=0
HeaderFile=SettingDlg.h
ImplementationFile=SettingDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CSettingDlg
VirtualFilter=dWC

[CLS:CMyButton]
Type=0
HeaderFile=MyButton.h
ImplementationFile=MyButton.cpp
BaseClass=CButton
Filter=W
VirtualFilter=BWC

[MNU:IDR_MENU1]
Type=1
Class=?
Command1=IDM_EDIT
Command2=ID_MENUITEM32776
Command3=ID_MENUITEM32777
Command4=ID_MENUITEM32778
Command5=ID_MENUITEM32779
Command6=ID_MENUITEM32780
Command7=ID_MENUITEM32781
Command8=ID_MENUITEM32782
CommandCount=8

