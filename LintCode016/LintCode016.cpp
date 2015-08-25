// LintCode016.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
	/**
	* @param S: A set of numbers.
	* @return: A list of lists. All valid subsets.
	*/
	vector<vector<int> > subsets(vector<int> &nums) {
		// write your code here
		vector<vector<int>> results;
		vector<int> item;
		search(0, nums, item, results);
		return results;
	}

	void search(int index, vector<int> nums,vector<int> &item, vector<vector<int>> &result)
	{
		if (index == nums.size())
		{
			result.push_back(item);
			return;
		}
		item.push_back(nums[index]);
		search(index + 1, nums, item, result);
		item.pop_back();
		search(index + 1, nums, item, result);
	}
};


void test1()
{
	Solution s;
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(2);
	vector<vector<int>> result = s.subsets(a);
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

