; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
ClassCount=3
Class1=CModalPlaneDLLApp
LastClass=CGodPlaneDlg
NewFileInclude2=#include "ModalPlaneDLL.h"
ResourceCount=1
NewFileInclude1=#include "stdafx.h"
Class2=CGodPlaneDlg
LastTemplate=CWinThread
Class3=CGodThread
Resource1=IDD_DIALOG_GODPLANE

[CLS:CModalPlaneDLLApp]
Type=0
HeaderFile=ModalPlaneDLL.h
ImplementationFile=ModalPlaneDLL.cpp
Filter=N
BaseClass=CWinApp
VirtualFilter=AC
LastObject=CModalPlaneDLLApp

[DLG:IDD_DIALOG_GODPLANE]
Type=1
Class=CGodPlaneDlg
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,button,1342177287
Control3=IDC_EDIT_PLANE_X,edit,1350639744
Control4=IDC_EDIT_PLANE_Y,edit,1350639744
Control5=IDC_STATIC,static,1342308353
Control6=IDC_STATIC,static,1342308353
Control7=IDC_BUTTON_SCAN,button,1342242816
Control8=IDC_BUTTON_STOP,button,1342242816

[CLS:CGodPlaneDlg]
Type=0
HeaderFile=GodPlaneDlg.h
ImplementationFile=GodPlaneDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT_PLANE_X
VirtualFilter=dWC

[CLS:CGodThread]
Type=0
HeaderFile=GodThread.h
ImplementationFile=GodThread.cpp
BaseClass=CWinThread
Filter=N
VirtualFilter=TC

