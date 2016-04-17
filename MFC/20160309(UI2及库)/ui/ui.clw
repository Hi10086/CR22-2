; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CPage3
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ui.h"
LastPage=0

ClassCount=8
Class1=CUiApp
Class2=CUiDoc
Class3=CUiView
Class4=CMainFrame

ResourceCount=7
Resource1=IDD_PAGE1
Resource2=IDR_TOOLBAR1
Class5=CAboutDlg
Resource3=IDD_DIALOG1
Resource4=IDD_ABOUTBOX
Resource5=IDD_PAGE2
Resource6=IDR_MAINFRAME
Class6=CPage1
Class7=CPage2
Class8=CPage3
Resource7=IDD_PAGE3

[CLS:CUiApp]
Type=0
HeaderFile=ui.h
ImplementationFile=ui.cpp
Filter=N

[CLS:CUiDoc]
Type=0
HeaderFile=uiDoc.h
ImplementationFile=uiDoc.cpp
Filter=N

[CLS:CUiView]
Type=0
HeaderFile=uiView.h
ImplementationFile=uiView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T




[CLS:CAboutDlg]
Type=0
HeaderFile=ui.cpp
ImplementationFile=ui.cpp
Filter=D
LastObject=CAboutDlg
BaseClass=CDialog
VirtualFilter=dWC

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=1
Control1=IDC_TAB2,SysTabControl32,1342177280

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
CommandCount=16

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

[TB:IDR_TOOLBAR1]
Type=1
Class=?
Command1=ID_BUTTON32771
Command2=ID_BUTTON32772
Command3=ID_BUTTON32773
CommandCount=3

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
Class=?
ControlCount=4
Control1=IDM_LINE,button,1342242816
Control2=IDC_CHECK1,button,1342242819
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_COMBO1,combobox,1344340226

[DLG:IDD_PAGE1]
Type=1
Class=CPage1
ControlCount=1
Control1=IDC_EDIT1,edit,1350631552

[DLG:IDD_PAGE2]
Type=1
Class=CPage2
ControlCount=1
Control1=IDC_RADIO1,button,1342177289

[DLG:IDD_PAGE3]
Type=1
Class=CPage3
ControlCount=1
Control1=IDC_CHECK1,button,1342242819

[CLS:CPage1]
Type=0
HeaderFile=Page1.h
ImplementationFile=Page1.cpp
BaseClass=CDialog
Filter=D

[CLS:CPage2]
Type=0
HeaderFile=Page2.h
ImplementationFile=Page2.cpp
BaseClass=CDialog
Filter=D

[CLS:CPage3]
Type=0
HeaderFile=Page3.h
ImplementationFile=Page3.cpp
BaseClass=CDialog
Filter=D

