// LintCode015.cpp : �������̨Ӧ�ó������ڵ㡣
//
/**
����һ�������ظ����ֵ��б��ҳ��б����в�ͬ������

������ʵ���������Ƿ�����������⣿ Yes
����
�����б�[1,2,2]����ͬ�������У�

[

[1,2,2],

[2,1,2],

[2,2,1]

]

��ս
�ܷ�ʹ�õݹ���ɣ�
**/
#include <iostream>
#include <vector>
using namespace std;


/**
* @param nums: A list of integers.
* @return: A list of permutations.
*/

/**
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

void swap(vector<int> &nums, int a, int b)
{
	int temp = nums[a];
	nums[a] = nums[b];
	nums[b] = temp;
}
**/

class Solution {
public:
	/**
	* @param nums: A list of integers.
	* @return: A list of unique permutations.
	*/
	vector<vector<int> > permuteUnique(vector<int> &nums) {
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
				if (isswap(nums,position,i))
				{
					swap(nums, position, i);
					search(nums, results, position + 1);
					swap(nums, i, position);
				}
				
			}
		}
	}

	bool isswap(vector<int> nums, int begin, int end)
	{
		for (;begin < end;begin++)
		{
			if (nums[end] == nums[begin])
				return false;
		}
		return true;
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
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(2);
	vector<vector<int>> result = s.permuteUnique(a);
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

