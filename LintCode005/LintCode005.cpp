// LintCode005.cpp : �������̨Ӧ�ó������ڵ㡣
//
/**
���������ҵ���k���Ԫ��
����
��������[9,3,2,4,8]���������Ԫ����4

�������� [1,2,3,4,5]����һ���Ԫ����5���ڶ����Ԫ����4���������Ԫ����3���Դ�����

ע��
����Խ��������е�Ԫ�ص�λ��

��ս
Ҫ��ʱ�临�Ӷ�ΪO(n�����ռ临�Ӷ�ΪO(1��
**/
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <functional>
using namespace std;

class Solution {
public:
	/*
	* param k : description of k
	* param nums : description of array and index 0 ~ n-1
	* return: description of return
	*/
	int kthLargestElement(int k, vector<int> nums) {
		// write your code here
		sort(nums.begin(), nums.end(), greater<int>());
		cout << nums[k - 1] << endl;
		return nums[k - 1];
	}
};


void test1(Solution s)
{
	vector<int> nums;
	for (int i = 0;i < 10000;i++)
	{
		nums.push_back(i);
	}
	if (s.kthLargestElement(3, nums) == 9997)
		cout << "test 1 passed!" << endl;
	else
		cout << "test 1 failed!" << endl;
}

void test2(Solution s)
{
	vector<int> nums;
	for (int i = 1000;i > 0 ;i--)
	{
		nums.push_back(i);
	}
	if (s.kthLargestElement(2, nums) == 999)
		cout << "test 2 passed!" << endl;
	else
		cout << "test 2 failed!" << endl;
}

int main()
{
	Solution s;
	test1(s);
	test2(s);
	system("pause");
    return 0;
}

