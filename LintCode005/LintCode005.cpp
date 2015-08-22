// LintCode005.cpp : 定义控制台应用程序的入口点。
//
/**
在数组中找到第k大的元素
样例
给出数组[9,3,2,4,8]，第三大的元素是4

给出数组 [1,2,3,4,5]，第一大的元素是5，第二大的元素是4，第三大的元素是3，以此类推

注意
你可以交换数组中的元素的位置

挑战
要求时间复杂度为O(n），空间复杂度为O(1）
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

