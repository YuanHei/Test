// 算法提高 3-2字符串输入输出函数  
/*
描述
　　编写函数GetReal和GetString，在main函数中分别调用这两个函数。在读入一个实数和一个字符串后，将读入的结果依次用printf输出。
　　两次输入前要输出的提示信息分别是"please input a number:\n”和"please input a string:\n"
样例输入
9.56
hello
样例输出
please input a number:
please input a string:
9.56
hello
*/

#include <iostream>
#include <cstdio>
using namespace std;

void GetReal(double num1)
{
	printf("%0.2f\n", num1);
}

void GetString(char* num2)
{
	printf("%s\n", num2);
}

int main()
{
	double number;
	char string[1000];
	printf("please input a number:\n");
	printf("please input a string:\n");
	cin >> number;
	cin >> string;
	GetReal(number);
	GetString(string);

	return 0;
}
