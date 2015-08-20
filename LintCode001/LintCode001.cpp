// LintCode001.cpp : 定义控制台应用程序的入口点。
/**
中等: A + B 问题

给出两个整数a和b, 求他们的和, 但不能使用 + 等数学运算符。

样例
如果 a=1 并且 b=2，返回3

注意
你不需要从输入流读入数据，只需要根据aplusb的两个参数a和b，计算他们的和并返回就行。

挑战
显然你可以直接 return a + b，但是你是否可以挑战一下不这样做？

说明
a和b都是 32位 整数么？

是的
我可以使用位运算符么？

当然可以
**/

#include <iostream>
using namespace std;

class Solution {
public:
	/*
	* @param a: The first integer
	* @param b: The second integer
	* @return: The sum of a and b
	*/
	int aplusb(int a, int b) {
		// write your code here, try to do it without arithmetic operators.
		int nCarry = a & b;      // 进位  
		int nSumNoCarry = a ^ b; // 非进位  
		if (nCarry != 0)
			return aplusb(nSumNoCarry, nCarry << 1);
		else
			return nSumNoCarry;
	}
};

int main()
{
	Solution s;
	if (s.aplusb(1, 1) == 2)
		cout << "test 1 passed!" << endl;
	if (s.aplusb(1, -1) == 0)
		cout << "test 2 passed!" << endl;
	if (s.aplusb(1, 3) == 4)
		cout << "test 3 passed!" << endl;
	if (s.aplusb(0, 0) == 0)
		cout << "test 4 passed!" << endl;
	if (s.aplusb(100, 100) == 200)
		cout << "test 5 passed!" << endl;
	system("pause");
    return 0;
}

