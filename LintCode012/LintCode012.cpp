// LintCode012.cpp : �������̨Ӧ�ó������ڵ㡣
//
/**
�ַ������ң��ֳƲ������ַ����������ַ���������һ�������õĺ��������������ʵ�����������

����һ�������� source �ַ�����һ�� target �ַ�������Ӧ���� source �ַ������ҳ� target �ַ������ֵĵ�һ��λ��(��0��ʼ)��

��������ڣ��򷵻� -1��

����
��� source = "source" �� target = "target"������ -1��

��� source = "abcdabcdefg" �� target = "bcd"������ 1��

��ս
O(n2)���㷨�ǿ��Խ��ܵġ����������O(n)���㷨�������Ǹ��Ӻá�����ʾ��KMP��
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

