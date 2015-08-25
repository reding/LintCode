// LintCode017.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	/**
	* @param S: A set of numbers.
	* @return: A list of lists. All valid subsets.
	*/
	vector<vector<int> > subsetsWithDup(const vector<int> &S) {
		// write your code here
		vector<int> nums;
		for (int i = 0;i < S.size();i++)
			nums.push_back(S[i]);
		sort(nums.begin(), nums.end());
		vector<vector<int>> results;
		vector<int> item;
		search(0, S, item, results);
		return results;
	}

	void search(int index, const vector<int> nums, vector<int> &item, vector<vector<int>> &result)
	{
		if (index == nums.size())
		{
			result.push_back(item);
			return;
		}

		if (item.size() == 0 || item[item.size() - 1] != nums[index])
		{
			vector<int> item2;
			for (int i = 0;i < item.size();i++)
			{
				item2.push_back(item[i]);
			}
			search(index + 1, nums, item2, result);
		}

	    item.push_back(nums[index]);
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
	a.push_back(1);
	a.push_back(2);
	vector<vector<int>> result = s.subsetsWithDup(a);
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

