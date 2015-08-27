// LintCode021.cpp : �������̨Ӧ�ó������ڵ㡣
//
/**
����һ����������nums��һ������k���������飨���ƶ�����nums�е�Ԫ�أ���ʹ�ã�

����С��k��Ԫ���Ƶ����
���д��ڵ���k��Ԫ���Ƶ��ұ�
�������黮�ֵ�λ�ã��������е�һ��λ��i������nums[i]���ڵ���k��
����
��������nums=[3,2,2,1]�� k=2������ 1

ע��
��Ӧ�������Ļ�������nums����������ֻ�Ǽ����kС����������
�������nums�е�����Ԫ�ض���kС���򷵻�nums.length��
**/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int partitionArray(vector<int> &nums, int k) {
		// write your code here
		int line = 0;
		int index = 0;
		while (index < nums.size())
		{
			if (nums[index] < k)
			{
				swap(nums, line, index);
				line++;
			}
			index++;
		}
		return line;
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
	vector<int> nums = { 3,2,2,1 };
	if (s.partitionArray(nums, 2) == 1)
		cout << "test 1 passed!" << endl;
	else
		cout << "test 1 failed!" << endl;
}

int main()
{
	test1();
	system("pause");
    return 0;
}

