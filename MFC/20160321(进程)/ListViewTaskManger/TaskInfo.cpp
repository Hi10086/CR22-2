// TaskInfo.cpp: implementation of the CTaskInfo class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ListViewTaskManger.h"
#include "TaskInfo.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTaskInfo::CTaskInfo()
{
	m_ThreadCuts = m_PID = 0;
}

CTaskInfo::~CTaskInfo()
{

}
