//算法提高 c++_ch03_02 
/*
问题描述
　　PASCAL三角是形状如下的三角矩阵：
　　1
　　1 1
　　1 2 1
　　1 3 3 1
　　1 4 6 4 1
　　在PASCAL三角中的每个数是一个组合C(n,k)。
　　C(n,k)=(((((((n/1)(n-1))/2(n-2))/3)***(n-k+2))/(k-1))(n-k+1))/k
　　公式中交替使用乘法和除法，每次将从n开始递减的一个值相乘，然后除以下一个从1开始递增的值。
　　如果对行和列从0开始计数，则数字C(n,k)在n行k列。例如C(6,2)在第6行第2列。编程输出指定阶数的PASCAL三角矩阵。例如下面给出的是12阶PASCAL三角形矩阵。

　　编写程序，使运行结果为：
　　1
　　1 1
　　1 2 1
　　1 3 3 1
　　1 4 6 4 1
　　1 5 10 10 5 1
　　1 6 15 20 15 6 1
　　1 7 21 35 35 21 7 1
　　1 8 28 56 70 56 28 8 1
　　1 9 36 84 126 126 84 36 9 1
　　1 10 45 120 210 252 210 120 45 10 1
　　1 11 55 165 330 462 462 330 165 55 11 1
　　1 12 66 220 495 792 924 792 495 220 66 12 1


　　该题的详细文档及程序框架请从网络学堂下载！
*/


#include <iostream>
#include <cstdio>
using namespace std;

void print(char a, char b, char c)
{
	int value = 0;
	int i = 0;
	int num[255] = { 0 };
	int k = 0;
	if(a == '0' && b == '0' && c == '0')
	{
		cout << "0 0 0" << endl;
		return;
	}
    cout << a << b << c << " ";
	if(c >= '0' && c <= '9')
	{
		value += (c-'0');
	}
	else
	{
		value += (c-'A'+10);
	}
	if(b >= '0' && b <= '9')
	{
		value += (b-'0')*16;
	}
	else
	{
		value += (b-'A'+10)*16;
	}
	if(a >= '0' && a <= '9')
	{
		value += (a-'0')*16*16;
	}
	else
	{
		value += (a-'A'+10)*16*16;
	}
	cout << value << " ";
	while(value)
	{
		num[k++] = value % 8;
		value /= 8; 
	}
	for(i = k-1; i >= 0; --i)
	{
		cout << num[i];
	}
	cout << endl;
}

int main()
{
	char a, b, c;
	cin >> a >> b >> c;
	print(a, b, c);

	return 0;
}