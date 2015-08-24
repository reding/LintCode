// LintCode014.cpp : �������̨Ӧ�ó������ڵ㡣
//

/**
����һ�������б����������п��ܵ����С�

����
����һ���б�[1,2,3]����ȫ����Ϊ��

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

