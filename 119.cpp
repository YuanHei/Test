// 算法提高 6-9删除数组中的0元素
/*
编写函数CompactIntegers，删除数组中所有值为0的元素，其后元素向数组首端移动。注意，CompactIntegers函数需要接收数组及其元素个数作为参数，函数返回值应为删除操作执行后数组的新元素个数。
　　输入时首先读入数组长度，再依次读入每个元素。
　　将调用此函数后得到的数组和函数返回值输出。
样例输入
7
2 0 4 3 0 0 5
样例输出
2 4 3 5
4
*/

#include <iostream>
#include <cstdio>
using namespace std;

int CompactIntegers(int num[], int n)
{
	int i = 0, j = 0;
	int count = 0;
	int flag = 0;
	for(i = n-1; i >= 0; --i)
	{
		if(0 == num[i])
		{
			n--;
		}
		else
		{
			break;
		}
	}
	i = 0;
	while(i < n)
	{
		if(0 == num[i])
		{
			for(j = i; j < n-1; ++j)
			{
				num[j] = num[j+1];
				flag = 1;
			}
			count++;
			if(flag == 1)
			{
		    	i--;
			}
		}
		i++;
	}

	return n-count;
}

int main()
{
	int ret = 0;
	int i = 0, n;
	int num[1000] = {0};
	cin >> n;
	for(i = 0; i < n; ++i)
	{
		cin >> num[i];
	}
	ret = CompactIntegers(num, n);
	for(i = 0; i < ret; ++i)
	{
		cout << num[i] << " ";
	}
	cout << endl << ret << endl;

	return 0;
}