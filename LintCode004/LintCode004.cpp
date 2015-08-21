// LintCode004.cpp : 定义控制台应用程序的入口点。
//
/**
设计一个算法，找出只含素因子3，5，7 的第 k 大的数。

符合条件的数如：3，5，7，9，15......

样例
如果k=4， 返回 9

挑战
要求时间复杂度为O(nlogn)或者O(n)
**/

#include <iostream>
using namespace std;

class Solution {
public:
	/*
	* @param k: The number k.
	* @return: The kth prime number as description.
	*/
	long long kthPrimeNumber(int k) {
		// write your code here
		int index = 0;
		long long n = 2;
		while (true)
		{
			if (isugly(n))
			{
				index++;
				if (index == k)
					return n;
			}
			n++;
		}
	}

	bool isugly(long long n)
	{
		while (n >= 3 && n % 3 == 0)
			n = n / 3;
		while (n >= 5 && n % 5 == 0)
			n = n / 5;
		while (n >= 7 && n % 7 == 0)
			n = n / 7;
		if (n == 1)
			return true;
		else
			return false;
	}


	long long Min(long long a, long long b, long long c)
	{
		if (a < b)
		{
			if (a < c)
				return a;
			return c;
		}
		else
		{
			if (b < c)
				return b;
			return c;
		}
	}

	/*
	* @param k: The number k.
	* @return: The kth prime number as description.
	*/
	long long kthPrimeNumber2(int k)
	{
		long long * nums = new long long[k+1];
		nums[0] = 1;
		int index3 = 0;
		int index5 = 0;
		int index7 = 0;
		int index = 1;
		while (index <= k)
		{
			long long min = Min(nums[index3] * 3, nums[index5] * 5, nums[index7] * 7);
			nums[index] = min;
			while (nums[index3] * 3 <= nums[index])index3++;
			while (nums[index5] * 5 <= nums[index])index5++;
			while (nums[index7] * 7 <= nums[index])index7++;
			index++;
		}
		cout << nums[k] << endl;
		return nums[k];
	}


};

int main()
{
	Solution s;
	if (s.kthPrimeNumber2(4) == 9)
		cout << "test 1 passed!" << endl;
	else
		cout << "test 1 failed!" << endl;

	if (s.kthPrimeNumber2(5) == 15)
		cout << "test 2 passed!" << endl;
	else
		cout << "test 2 failed!" << endl;

	if (s.kthPrimeNumber2(599) == 1102959375)
		cout << "test 3 passed!" << endl;
	else
		cout << "test 3 failed!" << endl;

	system("pause");
    return 0;
}

