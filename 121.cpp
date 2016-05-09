// 121 算法提高 高精度加法  
/*
问题描述
　　在C/C++语言中，整型所能表示的范围一般为-231到231（大约21亿）,即使long long型，一般也只能表示到-263到263。要想计算更加规模的数，就要用软件来扩展了，比如用
数组或字符串来模拟更多规模的数及共运算。
　　现在输入两个整数，请输出它们的和。
输入格式
　　两行，每行一个整数，每个整数不超过1000位
输出格式
　　一行，两个整数的和。
样例输入
15464315464465465
482321654151
样例输出
15464797786119616
数据规模和约定
　　每个整数不超过1000位
*/
#include<iostream>
#include<cstring>
#include<math.h>
#include<algorithm>
using namespace std;

int main()
{
	//	freopen("D:\\in.txt","r",stdin);
	int c, i, j, cnt;
	int res[1111];
	char a[1111], b[1111];
	cin >> a >> b;
	int lena = strlen(a);
	int lenb = strlen(b);
	c = 0;
	cnt = 0;
	for (i = lena - 1, j = lenb - 1; i >= 0 && j >= 0; i--, j--)
	{
		int p = (a[i] - '0') + (b[j] - '0') + c;
		res[cnt++] = p % 10;
		c = p / 10;
	}
	while (i >= 0)
	{
		int p = (a[i] - '0') + c;
		res[cnt++] = p % 10;
		c = p / 10;
		i--;
	}
	while (j >= 0)
	{
		int p = (b[j] - '0') + c;
		res[cnt++] = p % 10;
		c = p / 10;
		j--;
	}
	if (c)
	{
		res[cnt++] = c;
	}
	for (i = cnt - 1; i >= 0; i--)
	{
		cout << res[i];
	}
	cout << endl;
	return 0;
}