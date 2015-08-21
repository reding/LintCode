// LintCode005.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <vector>
#include <limits>
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
		
		return 0;
	}
};


void test1(Solution s)
{
	vector<int> nums;
	for (int i = 0;i < 10000;i++)
	{
		nums.push_back(i);
	}
	if (s.kthLargestElement(3, nums) == 9998)
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
	if (s.kthLargestElement(2, nums) == 9999)
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

