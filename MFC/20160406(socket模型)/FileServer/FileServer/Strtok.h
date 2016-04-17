#pragma once
#include <unordered_map>
#include <list>

#define sstring CString
using namespace std;

struct string_hash
{
    int operator()(TCHAR *const& lhs) const 
    {
        int hash = 0;
        for (size_t i = 0; i < ::_tcslen(lhs); i++)
        {
            hash = lhs[i] + i;
        }

        return hash;
    }
};

struct string_equal
{
    bool operator()(TCHAR *const& lhs, TCHAR *const& rhs) const
    {
        return ::_tcscmp(lhs, rhs) == 0;
    }
};

class CStrtok
{
public:
    CStrtok();
    void Begin();

    void StrTok(TCHAR *str,const TCHAR *splic);
    void MakePair(const TCHAR *splic, bool KeyisLeft = true);

    sstring GetValue(TCHAR* szKey);
    virtual ~CStrtok();
private:
    TCHAR *pStr;
    list<TCHAR *> m_list;
    unordered_map<TCHAR *, TCHAR *, string_hash, string_equal> m_hash_map;
};

