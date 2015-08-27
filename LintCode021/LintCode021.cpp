// LintCode021.cpp : 定义控制台应用程序的入口点。
//
/**
给出一个整数数组nums和一个整数k。划分数组（即移动数组nums中的元素），使得：

所有小于k的元素移到左边
所有大于等于k的元素移到右边
返回数组划分的位置，即数组中第一个位置i，满足nums[i]大于等于k。
样例
给出数组nums=[3,2,2,1]和 k=2，返回 1

注意
你应该真正的划分数组nums，而不仅仅只是计算比k小的整数数，
如果数组nums中的所有元素都比k小，则返回nums.length。
**/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int partitionArray(vector<int> &nums, int k) {
		// write your code here
		int line = 0;
		int index = 0;
		while (index < nums.size())
		{
			if (nums[index] < k)
			{
				swap(nums, line, index);
				line++;
			}
			index++;
		}
		return line;
	}

	void swap(vector<int> &nums, int a, int b)
	{
		int temp = nums[a];
		nums[a] = nums[b];
		nums[b] = temp;
	}
};

void test1()
{
	Solution s;
	vector<int> nums = { 3,2,2,1 };
	if (s.partitionArray(nums, 2) == 1)
		cout << "test 1 passed!" << endl;
	else
		cout << "test 1 failed!" << endl;
}

int main()
{
	test1();
	system("pause");
    return 0;
}

