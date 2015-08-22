// LintCode013.cpp : 定义控制台应用程序的入口点。
//

/**
容易 二分查找

29% 通过
给定一个排序的整数数组（升序）和一个要查找的整数target，
用O(logn)的时间查找到target第一次出现的下标（从0开始），
如果target不存在于数组中，返回-1。

样例
在数组 [1, 2, 3, 3, 4, 5, 10] 中二分查找3，返回2。

挑战
如果数组中的整数个数超过了2^32，你的算法是否会出错？
**/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	/**
	* @param nums: The integer array.
	* @param target: Target number to find.
	* @return: The first position of target. Position starts from 0.
	*/
	int binarySearch(vector<int> &array, int target) {
		// write your code here
		int l = 0;
		int r = array.size() - 1;
		return binarysch(array,target,l,r);
	}
	int binarysch(vector<int>&array, int target, int l, int r)
	{
		if (l >= r)
			return -1;
		int mid = (l + r) / 2;
		if (array[mid] == target)
		{
			while (((mid-1)>=0)&&(array[mid - 1] == target))
				mid--;
			return mid;
		}
		else if (array[mid] > target)
			binarysch(array, target, l, mid);
		else
			binarysch(array, target, mid+1, r);
	}
};

void test1()
{
	Solution s;
	vector<int> nums;
	nums.push_back(1);nums.push_back(2);nums.push_back(3);
	nums.push_back(3);nums.push_back(4);nums.push_back(5);
	nums.push_back(10);
	if (s.binarySearch(nums, 3) == 2)
		cout << "test 1 passed!" << endl;
	else
		cout << "test 1 failed" << endl;

	if (s.binarySearch(nums, 7) == -1)
		cout << "test 2 passed!" << endl;
	else
		cout << "test 2 failed" << endl;
}

void test2()
{
	Solution s;
	vector<int> nums;
	//4,5,9,9,12,13,14,15,15,18
	nums.push_back(4);nums.push_back(5);nums.push_back(9);
	nums.push_back(9);nums.push_back(12);nums.push_back(13);
	nums.push_back(14);nums.push_back(15);nums.push_back(15);
	nums.push_back(18);
	if (s.binarySearch(nums, 10) == -1)
		cout << "test 3 passed!" << endl;
	else
		cout << "test 3 failed" << endl;
	if (s.binarySearch(nums, 4) == 0)
		cout << "test 4 passed!" << endl;
	else
		cout << "test 4 failed" << endl;
}

int main()
{
	test1();
	test2();
	system("pause");
    return 0;
}

