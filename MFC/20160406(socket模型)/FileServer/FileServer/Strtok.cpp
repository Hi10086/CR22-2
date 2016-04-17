
#include "stdafx.h"
#include "Strtok.h"

CStrtok::CStrtok()
{
}

void CStrtok::Begin()
{
    pStr = NULL;
    m_list.clear();
    m_hash_map.clear();
}

void CStrtok::StrTok(TCHAR *str, const TCHAR *splic)
{
    int nlen = ::_tcslen(str) + sizeof(TCHAR);
    pStr = new TCHAR[nlen];
    ::_tcscpy(pStr, str);

    TCHAR *pToken = ::_tcstok(str, splic);
    while (pToken)
    {
        m_list.push_back(pToken);
        pToken = ::_tcstok(NULL, splic);
    }
}

void CStrtok::MakePair(const TCHAR * splic, bool KeyisLeft)
{
    TCHAR *szKey = NULL;
    TCHAR *szValue = NULL;
    TCHAR *pToken = NULL;

    int nOldLength = m_list.size();
    list<TCHAR *>::iterator it = m_list.begin();

    while (nOldLength)
    {
        pToken = ::_tcstok(*it, splic);
        if (pToken)
        {
            szKey = pToken;
            szValue = ::_tcstok(NULL, TEXT("\n"));

            m_hash_map.insert(std::make_pair(szKey, szValue));
        }
        ++it;
        --nOldLength;
    }

    m_list.clear();
}

sstring CStrtok::GetValue(TCHAR* szKey)
{
    unordered_map<TCHAR *, TCHAR *, string_hash, string_equal>::iterator it = m_hash_map.find(szKey);
    if (it != m_hash_map.end())
    {
        return it->second;
    } 

    return TEXT("");
}

CStrtok::~CStrtok()
{
    this->Begin();
}
