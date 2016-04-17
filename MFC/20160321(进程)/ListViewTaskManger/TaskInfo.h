// TaskInfo.h: interface for the CTaskInfo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TASKINFO_H__8F8D3CA4_ACAB_451D_B03D_59FCAD4B1491__INCLUDED_)
#define AFX_TASKINFO_H__8F8D3CA4_ACAB_451D_B03D_59FCAD4B1491__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CTaskInfo  
{
public:
	CTaskInfo();
	virtual ~CTaskInfo();
public:
	CString m_ProcessName;
	DWORD m_PID;
	DWORD m_ThreadCuts;
};

#endif // !defined(AFX_TASKINFO_H__8F8D3CA4_ACAB_451D_B03D_59FCAD4B1491__INCLUDED_)
