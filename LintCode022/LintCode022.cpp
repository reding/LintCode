// LintCode022.cpp : �������̨Ӧ�ó������ڵ㡣
//
/**
����һ���ַ���source��һ��Ŀ���ַ���target�����ַ���source
���ҵ���������Ŀ���ַ�����ĸ���Ӵ���

����
����source = "ADOBECODEBANC"��target = "ABC" ����Ҫ��Ľ�  "BANC"

ע��
�����source��û���������Ӵ�������""������ж���������Ӵ���������ʼλ����С���Ӵ���

��ս
Ҫ��ʱ�临�Ӷ�ΪO(n)

˵��
�ڴ𰸵��Ӵ��е���ĸ��Ŀ���ַ������Ƿ���Ҫ������ͬ��˳��

��������Ҫ��
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

