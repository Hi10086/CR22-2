// example1.cpp : 定义控制台应用程序的入口点。
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

	// 智能指针支持这种特定的+运算真的好吗？万一换个类不支持+怎么办
	str1 = str1 + "BBB";
	str9 = str2;
	cout << *str2 << endl;
	cout << *str1 << endl;
    return 0;
}

