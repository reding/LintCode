// LintCode022.cpp : 定义控制台应用程序的入口点。
//
/**
给定一个字符串source和一个目标字符串target，在字符串source
中找到包括所有目标字符串字母的子串。

样例
给出source = "ADOBECODEBANC"，target = "ABC" 满足要求的解  "BANC"

注意
如果在source中没有这样的子串，返回""，如果有多个这样的子串，返回起始位置最小的子串。

挑战
要求时间复杂度为O(n)

说明
在答案的子串中的字母在目标字符串中是否需要具有相同的顺序？

——不需要。
**/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	/**
	* @param source: A string
	* @param target: A string
	* @return: A string denote the minimum window
	*          Return "" if there is no such a string
	*/
	string minWindow(string &source, string &target) {
		// write your code here
		
	}
};

void test1()
{
	Solution s;
	string str = "ADOBECODEBANC";
	string target = "ABC";
	cout << s.minWindow(str, target).c_str() << endl;
}

int main()
{
	test1();
	system("pause");
    return 0;
}

