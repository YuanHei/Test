//算法提高 进制转换
/*
问题描述
　　程序提示用户输入三个字符，每个字符取值范围是0-9，A-F。然后程序会把这三个字符转化为相应的十六进制整数，并分别以十六进制，十进制，八进制输出。
　　输入格式：输入只有一行，即三个字符。
　　输出格式：输出只有一行，包括三个整数，中间用空格隔开。
　　输入输出样例
样例输入
FFF
样例输出
FFF 4095 7777
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
