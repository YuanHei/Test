//算法提高 找素数  
/*
问题描述
　　给定区间[L, R] ， 请计算区间中素数的个数。
输入格式
　　两个数L和R。
输出格式
　　一行，区间中素数的个数。
样例输入
2 11
样例输出
5
数据规模和约定
　　2 <= L <= R <= 2147483647 R-L <= 1000000
*/

//运行超时

#include <iostream>
#include <math.h>
using namespace std;

int Count(long long int left, long long int right)
{
	long long int i, j, count = 0;
	for(i = left; i < right+1; ++i)
	{
		for(j = 2; j < sqrt(i); ++j)
		{
			if(i % j == 0)
			{
				break;
			}
		}
		if(j > sqrt(i))
		{
			count++;
		}
	}

	return count;
}

int main()
{
	long long int L, R;
	cin >> L >> R;

    cout << Count(L, R) << endl;

	return 0;
}
