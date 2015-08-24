// LintCode014.cpp : 定义控制台应用程序的入口点。
//

/**
给定一个数字列表，返回其所有可能的排列。

样例
给出一个列表[1,2,3]，其全排列为：

[
[1,2,3],
[1,3,2],
[2,1,3],
[2,3,1],
[3,1,2],
[3,2,1]
]
**/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	/**
	* @param nums: A list of integers.
	* @return: A list of permutations.
	*/
	vector<vector<int>> permute(vector<int> nums) {
		// write your code here
		vector<vector<int>> results;
		vector<int> item;
		search(nums, results, 0);
		return results;

	}

	void search(vector<int> nums, vector<vector<int>> &results, int position)
	{
		if (position == nums.size() - 1)
		{
			results.push_back(nums);
			return;
		}
		else
		{
			for (int i = position;i < nums.size();i++)
			{
				swap(nums, position, i);
				search(nums, results, position + 1);
				swap(nums, i, position);
			}
		}
	}

	void swap(vector<int> &nums,int a,int b)
	{
		int temp = nums[a];
		nums[a] = nums[b];
		nums[b] = temp;
	}
};

void test1()
{
	Solution s;
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	vector<vector<int>> result = s.permute(a);
	for (int i = 0;i < result.size();i++)
	{
		for (int j = 0;j < result[i].size();j++)
		{
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	test1();
	system("pause");
    return 0;
}

