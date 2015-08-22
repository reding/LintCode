// LintCode012.cpp : 定义控制台应用程序的入口点。
//
/**
字符串查找（又称查找子字符串），是字符串操作中一个很有用的函数。你的任务是实现这个函数。

对于一个给定的 source 字符串和一个 target 字符串，你应该在 source 字符串中找出 target 字符串出现的第一个位置(从0开始)。

如果不存在，则返回 -1。

样例
如果 source = "source" 和 target = "target"，返回 -1。

如果 source = "abcdabcdefg" 和 target = "bcd"，返回 1。

挑战
O(n2)的算法是可以接受的。如果你能用O(n)的算法做出来那更加好。（提示：KMP）
**/


#include <iostream>
using namespace std;

class Solution {
public:
	/**
	* Returns a index to the first occurrence of target in source,
	* or -1  if target is not part of source.
	* @param source string to be scanned.
	* @param target string containing the sequence of characters to match.
	*/
	int strStr(const char *source, const char *target) {
		// write your code here
		if (source == NULL || target == NULL)
		{
			return -1;
		}
		int n = strlen(source);
		int m = strlen(target);
		if ( n < m )
			return -1;
		if (m == 0)
			return NULL;
		int indext = 0;
		int result = -1;
		while (indext < (n - m + 1))
		{
			int indextt = 0;
			while (indextt < m)
			{
				
				if (source[indext+indextt] == target[indextt] && indextt == m - 1)
				{
					result = 1;
					return result;
				}
				else if (source[indext+indextt] == target[indextt])
					indextt++;
				else
				{
					break;
				}
			}
			indext++;
		}
		return result;
	}
};

void test1()
{
	Solution s;
	char * source = "source";
	char * target = "target";
	if (s.strStr(source, target) == -1)
		cout << "test 1 passed!" << endl;
	else
		cout << "test 1 failed!" << endl;
}

void test2()
{
	Solution s;
	char * source = "sourcesource";
	char * target = "ceso";
	if (s.strStr(source, target) == 1)
		cout << "test 2 passed!" << endl;
	else
		cout << "test 2 failed!" << endl;
}

int main()
{
	test1();
	test2();
	system("pause");
    return 0;
}

