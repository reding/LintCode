// LintCode004.cpp : 定义控制台应用程序的入口点。
//

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

	}
};

int main()
{
	Solution s;
	if (s.kthPrimeNumber(4) == 9)
		cout << "test 1 passed!" << endl;
	else
		cout << "test 1 failed!" << endl;

	if (s.kthPrimeNumber(5) == 15)
		cout << "test 2 passed!" << endl;
	else
		cout << "test 2 failed!" << endl;

	system("pause");
    return 0;
}

