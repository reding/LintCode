// LintCode008.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
using namespace std;

class Solution {
public:
	/**
	* @param str: a string
	* @param offset: an integer
	* @return: nothing
	*/
	void rotateString(string &str, int offset) {
		//wirte your code here
		if (str.size() == 0)
			return;
		offset = offset%str.size();
		for (int i = 0;i < offset;i++)
			movechars(str);
	}

	void movechars(string &str)
	{
		int r = str.size() - 1;
		char temp = str[r];
		for (;r > 0;r--)
		{
			str[r] = str[r - 1];
		}
		str[0] = temp;
	}
};

void test1()
{
	string str = "abcdefg";
	Solution s;
	s.rotateString(str, 0);
	if (!strcmp(str.c_str(), "abcdefg"))
		cout << "test 1 passed!" << endl;
	else
		cout << "test 1 faailed" << endl;
}

void test2()
{
	string str = "abcdefg";
	Solution s;
	s.rotateString(str, 1);
	if (!strcmp(str.c_str(), "gabcdef"))
		cout << "test 2 passed!" << endl;
	else
		cout << "test 2 faailed" << endl;
}

void test3()
{
	string str = "abcdefg";
	Solution s;
	s.rotateString(str, 2);
	if (!strcmp(str.c_str(), "fgabcde"))
		cout << "test 3 passed!" << endl;
	else
		cout << "test 3 faailed" << endl;
}

void test4()
{
	string str = "abcdefg";
	Solution s;
	s.rotateString(str, 3);
	if (!strcmp(str.c_str(), "efgabcd"))
		cout << "test 4 passed!" << endl;
	else
		cout << "test 4 faailed" << endl;
}

int main()
{
	test1();
	test2();
	test3();
	test4();
	system("pause");
    return 0;
}

