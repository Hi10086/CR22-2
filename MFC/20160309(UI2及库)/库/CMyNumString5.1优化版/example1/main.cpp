// example1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
//#include "RefCount.h"
#include <iostream>
#include "MyString.h"
#include "SmartPtr.h"
//#include "MyNumString.h"

using namespace std;

int main()
{
	CSmartPtr str1 = new CMyString("Hello");
	CSmartPtr str9 = new CMyString("AAAAA");
	CSmartPtr str2 = str1 + str9;

	// ����ָ��֧�������ض���+������ĺ�����һ�����಻֧��+��ô��
	str1 = str1 + "BBB";
	str9 = str2;
	cout << *str2 << endl;
	cout << *str1 << endl;
    return 0;
}

