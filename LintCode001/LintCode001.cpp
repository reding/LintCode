// LintCode001.cpp : �������̨Ӧ�ó������ڵ㡣
/**
�е�: A + B ����

������������a��b, �����ǵĺ�, ������ʹ�� + ����ѧ�������

����
��� a=1 ���� b=2������3

ע��
�㲻��Ҫ���������������ݣ�ֻ��Ҫ����aplusb����������a��b���������ǵĺͲ����ؾ��С�

��ս
��Ȼ�����ֱ�� return a + b���������Ƿ������սһ�²���������

˵��
a��b���� 32λ ����ô��

�ǵ�
�ҿ���ʹ��λ�����ô��

��Ȼ����
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
		int nCarry = a & b;      // ��λ  
		int nSumNoCarry = a ^ b; // �ǽ�λ  
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

