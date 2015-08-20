// LintCode002.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
using namespace std;

class Solution {
public:
	// param n : description of n
	// return: description of return 
	long long trailingZeros(long long n) {
		long long temp = n;
		long long result = 0;
		while (temp>=5)
		{
			result += temp/5;
			temp = temp / 5;
		}
		return result;
	}
};

int main()
{
	Solution s;
	if (s.trailingZeros(11) == 2)
		cout << "test 1 passed!" << endl;
	else
		cout << "test 1 failed!" << endl;
	cout << s.trailingZeros(50) << endl;
	system("pause");
    return 0;
}

