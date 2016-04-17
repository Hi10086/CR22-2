; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMyNoteDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MyNote.h"

ClassCount=3
Class1=CMyNoteApp
Class2=CMyNoteDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_MYNOTE_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Resource4=IDR_MENU1

[CLS:CMyNoteApp]
Type=0
HeaderFile=MyNote.h
ImplementationFile=MyNote.cpp
Filter=N

[CLS:CMyNoteDlg]
Type=0
HeaderFile=MyNoteDlg.h
ImplementationFile=MyNoteDlg.cpp
Filter=D
LastObject=IDC_EDIT1
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=MyNoteDlg.h
ImplementationFile=MyNoteDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MYNOTE_DIALOG]
Type=1
Class=CMyNoteDlg
ControlCount=1
Control1=IDC_EDIT1,edit,1353777284

[MNU:IDR_MENU1]
Type=1
Class=?
Command1=IDC_MENU_OPEN
Command2=IDC_MENU_SAVE
Command3=IDC_MENU_SAVE2
CommandCount=3

