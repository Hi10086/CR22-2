; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAboutDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "SankCAD.h"
LastPage=0

ClassCount=9
Class1=CSankCADApp
Class2=CSankCADDoc
Class3=CSankCADView
Class4=CMainFrame
Class9=CAboutDlg

ResourceCount=3
Resource1=IDR_MENU1
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX

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

