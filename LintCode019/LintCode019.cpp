// LintCode019.cpp : 定义控制台应用程序的入口点。
//
/**
交叉字符串

给出三个字符串:s1、s2、s3，判断s3是否由s1和s2交叉构成。

样例
比如 s1 = "aabcc" s2 = "dbbca"

- 当 s3 = "aadbbcbcac"，返回  true.

- 当 s3 = "aadbbbaccc"， 返回 false.

挑战
要求时间复杂度为O(n^2)或者更好
**/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	/**
	* Determine whether s3 is formed by interleaving of s1 and s2.
	* @param s1, s2, s3: As description.
	* @return: true of false.
	*/
	bool isInterleave(string s1, string s2, string s3)
	{
		int l1 = s1.length();
		int l2 = s2.length();
		int l3 = s3.length();

		if (l1 + l2 != l3) {
			return false;
		}
		/**
		dp[i][j] :表示s1的前i个字符和s2的前j个字符是否能和s3的前i+j个字符匹配
		dp[i][j] =  
		result[i,j] = (result[i-1,j] && s1[i] = s3[i+j])  || (result[i,j-1] && s2[j] = s3[i+j]);
		**/

		vector<vector<bool> > dp(s1.length() + 1, vector<bool>(s2.length() + 1, false));
		dp[0][0] = true;
		for (int i = 1;i <= s1.length();i++)
			dp[i][0] = dp[i - 1][0] && (s3[i - 1] == s1[i - 1]);
		for (int i = 1;i <= s2.length();i++)
			dp[0][i] = dp[0][i - 1] && (s3[i - 1] == s2[i - 1]);
		for (int i = 1;i <= s1.length();i++)
		{
			for (int j = 1;j <= s2.length();j++)
			{
				int t = i + j;
				if (s1[i - 1] == s3[t - 1])
					dp[i][j] = dp[i][j] || dp[i - 1][j];
				if (s2[j - 1] == s3[t - 1])
					dp[i][j] = dp[i][j] || dp[i][j - 1];
			}
		}
		return dp[s1.length()][s2.length()];
	}
};

void test1()
{
	string s1 = "asdfjopufaaf;lasnopfodifa;djfal;sfjdsf";
	string s2 = "adlkjfoqweijzdkj;ljfeowfjl;djfnd";
	Solution s;
	if (s.isInterleave(s1, s2, "asdfjopufaaf;lasnopfodadlkjfoqweijzdkj;ljfeowfjl;djfneifa;djfal;sfjdsf") == false)
	{
		cout << "test 1 passed!" << endl;
	}
	else
	{
		cout << "test 1 failed!" << endl;
	}
		
}

int main()
{
	test1();
	system("pause");
    return 0;
}

