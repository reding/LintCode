// LintCode018.cpp : �������̨Ӧ�ó������ڵ㡣
//
/**
д��һ����Ч���㷨������ m �� n�����е�ֵ��

�����������������ԣ�

ÿ���е�����������������ġ�
ÿ�еĵ�һ����������һ�е����һ��������

����
�������о���

[
[1, 3, 5, 7],
[10, 11, 16, 20],
[23, 30, 34, 50]
]
���� target = 3������ true

**/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	/**
	* @param matrix, a list of lists of integers
	* @param target, an integer
	* @return a boolean, indicate whether matrix contains target
	*/
	bool searchMatrix(vector<vector<int> > &matrix, int target) {
		// write your code here
		if (matrix.size() == 0)
			return false;
		if (matrix[1].size() == 0)
			return false;
		int result = search(matrix, target, 0, matrix[0].size()*matrix.size() - 1);
		if (result == -1)
			return false;
		return true;
	}

	// ����

	int search(vector<vector<int> > &matrix, int target, int begin, int end)
	{
		if (begin >= end)
		{
			if (begin == end)
				if (getmn(matrix, begin) == target)
					return begin;
			return -1;
		}
			
		int m =  (end + begin) / 2;
		if (target == getmn(matrix, m))
		{
			return m;
		}
		else if (target > getmn(matrix, m))
		{
			search(matrix, target, m+1, end);
		}
		else
		{
			search(matrix, target, begin, m);
		}
	}

	int getmn(vector<vector<int> > &matrix,int mn)
	{
		int i = mn / matrix[0].size();
		int j = mn % matrix[0].size();
		return matrix[i][j];
	}

	//m*n 
	bool searchMatrixmn(vector<vector<int> > &matrix, int target) {
		// write your code here
		for (int i = 0;i < matrix.size();i++)
		{
			for (int j = 0;j < matrix[i].size();j++)
			{
				if (matrix[i][j] == target)
					return true;
			}
		}
		return false;
	}

};

void test1()
{
	vector<vector<int>> vs;
	vector<int> v1 = { 1,2,3,4,5 };
	vector<int> v2 = { 6,7,8,9,10 };
	vector<int> v3 = { 11,12,13,14,15 };
	vs = { v1,v2,v3 };
	Solution s;
	if (s.searchMatrix(vs, 1) == true)
	{
		cout << "test 1.1 passed!" << endl;
	}
	if (s.searchMatrix(vs, 6) == true)
	{
		cout << "test 1.2 passed!" << endl;
	}
	if (s.searchMatrix(vs, 15) == true)
	{
		cout << "test 1.3 passed!" << endl;
	}
	if (s.searchMatrix(vs, 22) == false)
	{
		cout << "test 1.4 passed!" << endl;
	}
	if (s.searchMatrix(vs, 0) == false)
	{
		cout << "test 1.5 passed!" << endl;
	}
}

int main()
{
	test1();
	system("pause");
    return 0;
}

