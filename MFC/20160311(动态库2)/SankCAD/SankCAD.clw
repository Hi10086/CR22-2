; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=SetDialog
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "SankCAD.h"
LastPage=0

ClassCount=6
Class1=CSankCADApp
Class2=CSankCADDoc
Class3=CSankCADView
Class4=CMainFrame

ResourceCount=4
Resource1=IDR_MAINFRAME
Resource2=IDD_ABOUTBOX
Resource3=IDR_MENU1
Class5=CAboutDlg
Class6=SetDialog
Resource4=IDD_DIALOG1

[CLS:CSankCADApp]
Type=0
HeaderFile=SankCAD.h
ImplementationFile=SankCAD.cpp
Filter=N

[CLS:CSankCADDoc]
Type=0
HeaderFile=SankCADDoc.h
ImplementationFile=SankCADDoc.cpp
Filter=N

[CLS:CSankCADView]
Type=0
HeaderFile=SankCADView.h
ImplementationFile=SankCADView.cpp
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
HeaderFile=SankCAD.cpp
ImplementationFile=SankCAD.cpp
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
Command11=ID_EDIT_REDO
Command12=ID_EDIT_SELECT
Command13=ID_TOOL_LINE
Command14=ID_MENUITEM32773
Command15=ID_TOOL_POLYGON
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

[MNU:IDR_MENU1]
Type=1
Class=?
Command1=ID_RIGHT_MOVE
Command2=ID_RIGHT_COPY
Command3=ID_RIGHT_PATES
Command4=ID_RIGHT_DEL
CommandCount=4

[DLG:IDD_DIALOG1]
Type=1
Class=SetDialog
ControlCount=8
Control1=IDC_RADIO_SOLID,button,1342308361
Control2=IDC_RADIO_DASH,button,1342177289
Control3=IDC_RADIO_DOT,button,1342177289
Control4=IDC_RADIO_DASHDOT,button,1342177289
Control5=IDC_STATIC,button,1342177287
Control6=IDC_RADIO_DASHDOTDOT,button,1342177289
Control7=IDC_BUTTON_CANCEL,button,1342242816
Control8=IDC_BUTTON_OK,button,1342242816

[CLS:SetDialog]
Type=0
HeaderFile=SetDialog.h
ImplementationFile=SetDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_RADIO_SOLID
VirtualFilter=dWC

