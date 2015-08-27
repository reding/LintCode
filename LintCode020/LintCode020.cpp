// LintCode020.cpp : �������̨Ӧ�ó������ڵ㡣
//
/**
���� ��������

����һ�����ص��İ���������ʼ�˵�����������б�

���б��в���һ���µ����䣬��Ҫȷ���б��е�������Ȼ�����Ҳ��ص�������б�Ҫ�Ļ������Ժϲ����䣩��

����
��������[2, 5] �� [[1,2], [5,9]]�����ǵõ� [[1,9]]��

��������[3, 4] �� [[1,2], [5,9]]�����ǵõ� [[1,2], [3,4], [5,9]]��
**/

#include <iostream>
#include <vector>
#include <limits>
using namespace std;
class Interval
{
public:
	int start, end;
	Interval(int start, int end)
	{
		this->start = start;
		this->end = end;
	}
};
class Solution {
public:
	/**
	* Insert newInterval into intervals.
	* @param intervals: Sorted interval list.
	* @param newInterval: new interval.
	* @return: A new interval list.
	*/
	/*
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		// write your code here
		vector<Interval> result;
		if (intervals.size() == 0) 
		{
			result.push_back(newInterval);
			return result;
		}
		if (newInterval.end < intervals[0].start)
		{
			result.push_back(newInterval);
			for (int i = 0;i < intervals.size();i++)
				result.push_back(intervals[i]);
			return result;
		}
		if (newInterval.start > intervals.size() - 1)
		{
			for (int i = 0;i < intervals.size();i++)
				result.push_back(intervals[i]);
			result.push_back(newInterval);
			return result;
		}
		for (int i = 0;i < intervals.size()-1;i++)
		{
			if (newInterval.start > intervals[i].end&&newInterval.end < intervals[i + 1].start)
			{
				for (int j = 0;j < intervals.size();j++)
				{
					result.push_back(intervals[j]);
					if (j == i)
						result.push_back(newInterval);
				}
				return result;
			}
		}

		int startindex = 0;
		int endindex = 0;
		for (int i = 0;i < intervals.size();i++)
		{
			if (newInterval.start > intervals[i].start&&newInterval.start < intervals[i].end)
			{
				startindex = i;
			}
			if (newInterval.end > intervals[i].start&&newInterval.end < intervals[i].end)
			{
				endindex = i;
			}
		}
		if (startindex == endindex)
			return intervals;
		else
		{
			for (int i = 0;i < startindex;i++)
			{
				result.push_back(intervals[i]);
			}
			result.push_back(*(new Interval(intervals[startindex].start, intervals[endindex].end)));
			for (int j = endindex + 1;j < intervals.size();j++)
			{
				result.push_back(intervals[j]);
			}
			return result;
		}
	}
	*/
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval)
	{
		vector<Interval> result;
		int i = 0;

		/**
		��newInterval��ߵ�����ȫ�����뵽�����
		**/
		while (i < intervals.size() && newInterval.start>intervals[i].end)
		{
			result.push_back(intervals[i++]);
		}

		/**
		����ĺϲ���
		
		**/
		while (i < intervals.size() && newInterval.end >= intervals[i].start)
		{
			//��������newInterval��start��
			newInterval.start = newInterval.start > intervals[i].start ? intervals[i].start : newInterval.start;
			//��������newInterval��end
			newInterval.end = newInterval.end > intervals[i].end ? newInterval.end : intervals[i].end;
			i++;
		}
		result.push_back(newInterval);

		/**
		newInterval�ұߵ�����ȫ�����뵽�����
		**/
		while (i < intervals.size())
		{
			result.push_back(intervals[i++]);
		}
		return result;
	}
};

void test1()
{
	vector<Interval> r;
	r.push_back(*(new Interval(1, 4)));
	r.push_back(*(new Interval(6, 9)));
	Solution s;
	vector<Interval> result = s.insert(r, *(new Interval(4, 7)));
	if (result.size() != 1)
	{
		cout << "test 1 failed!" << endl;
		return;
	}
	if(result[0].start!=1&&result[0].end!=9)
	{
		cout << "test 1 failed!" << endl;
		return;
	}
	cout << "test 1 passed!" << endl;
		


}

int main()
{
	test1();
	system("pause");
    return 0;
}

