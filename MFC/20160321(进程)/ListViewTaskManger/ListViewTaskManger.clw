; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTaskListView
LastTemplate=CListView
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ListViewTaskManger.h"
LastPage=0

ClassCount=11
Class1=CListViewTaskMangerApp
Class2=CListViewTaskMangerDoc
Class3=CListViewTaskMangerView
Class4=CMainFrame
Class9=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Class10=CTankListView
Class11=CTaskListView
Resource2=IDR_MENU1
Resource3=IDR_MAINFRAME

[CLS:CListViewTaskMangerApp]
Type=0
HeaderFile=ListViewTaskManger.h
ImplementationFile=ListViewTaskManger.cpp
Filter=N

[CLS:CListViewTaskMangerDoc]
Type=0
HeaderFile=ListViewTaskMangerDoc.h
ImplementationFile=ListViewTaskMangerDoc.cpp
Filter=N

[CLS:CListViewTaskMangerView]
Type=0
HeaderFile=ListViewTaskMangerView.h
ImplementationFile=ListViewTaskMangerView.cpp
Filter=C


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T




[CLS:CAboutDlg]
Type=0
HeaderFile=ListViewTaskManger.cpp
ImplementationFile=ListViewTaskManger.cpp
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

[CLS:CTankListView]
Type=0
HeaderFile=TankListView.h
ImplementationFile=TankListView.cpp
BaseClass=CListView
Filter=C

[CLS:CTaskListView]
Type=0
HeaderFile=TaskListView.h
ImplementationFile=TaskListView.cpp
BaseClass=CListView
Filter=C
VirtualFilter=VWC

[MNU:IDR_MENU1]
Type=1
Class=?
Command1=ID_MENUITEM_CLOSE
Command2=ID_MENUITEM_PRIORITY
CommandCount=2

