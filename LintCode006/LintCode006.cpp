// LintCode006.cpp : 定义控制台应用程序的入口点。
//
/**
合并两个排序的整数数组A和B变成一个新的数组。

样例
给出A=[1,2,3,4]，B=[2,4,5,6]，返回 [1,2,2,3,4,4,5,6]

挑战
你能否优化你的算法，如果其中一个数组很大而另一个数组很小？
**/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	/**
	* @param A and B: sorted integer array A and B.
	* @return: A new sorted integer array
	*/
	vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
		// write your code here
		vector<int> result;
		int indexa = 0;
		int indexb = 0;
		while (indexa<A.size()&&indexb<B.size())
		{
			if (A[indexa] < B[indexb])
			{
				result.push_back(A[indexa]);
				indexa++;
			}
			else
			{
				result.push_back(B[indexb]);
				indexb++;
			}
		}
		while (indexa < A.size())
		{
			result.push_back(A[indexa]);
			indexa++;
		}
		while (indexb < B.size())
		{
			result.push_back(B[indexb]);
			indexb++;
		}
		return result;
	}
};

void test1()
{
	vector<int> a;
	vector<int> b;
	Solution s;
	for (int i = 1;i <= 100;i++)
	{
		a.push_back(i);
		b.push_back(i + 100);
	}
	vector<int> c = s.mergeSortedArray(a, b);
	for (int j = 0;j < 200;j++)
	{
		if (c[j] != j+1)
		{
			cout << "test 1 failed!" << endl;
			return;
		}
	}
	cout << "test 1 passed!" << endl;
}

int main()
{
	test1();
	system("pause");
    return 0;
}

