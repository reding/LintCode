// LintCode003.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
using namespace std;

class Solution {
public:
	/*
	* param k : As description.
	* param n : As description.
	* return: How many k's between 0 and n.
	*/
	int digitCounts(int k, int n) {
		if (n < 0 || k > 9 || k < 0)
			return 0;
		// write your code here
		int result = 0;
		for (int i = 0;i <= n;i++)
		{
			result += digitCountn(k, i);
		}
		return result;
	}

	int digitCountn(int k, int m)
	{
		int temp = m;
		int result = 0;
		while (temp > 0)
		{
			int s = temp % 10;
			if (s == k)
				result++;
			temp = temp / 10;
		}
		return result;
	}
};


int main()
{
	Solution s;
	if (s.digitCounts(1, 12) == 5)
		cout << "test 1 passed!" << endl;
	else
		cout << "test 1 failed!" << endl;
	if (s.digitCounts(2, 1) == 0)
		cout << "test 2 passed!" << endl;
	else
		cout << "test 2 failed!" << endl;
	system("pause");
    return 0;
}

