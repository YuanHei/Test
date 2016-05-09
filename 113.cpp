//算法提高 c++_ch02_02  
//　使用Switch语句编写一个模拟简单计算器的程序。依次输入两个整数和一个字符，并用空格隔开。如果该字符是一个“+”
//，则打印和；如果该字符是一个“-”，则打印差；如果该字符是一个“*”,则打印积；如果该字符是“/”，则打印商；如果该字
//符是一个“%”，则打印余数。打印结果后输出一个空行。

#include <stdio.h>
void Cal(int num1, int num2, char c)
{
	switch(c)
	{
	case '+':
		printf("%d\n", num1+num2);
		break;
	case '-':
		printf("%d\n", num1-num2);
		break;
	case '*':
		printf("%d\n", num1*num2);
		break;
	case '/':
		if(num2 == 0)
		{
			printf("\n");
		}
		else
		{
			printf("%d\n", num1/num2);
		}
		break;
	case '%':
		if(num2 == 0)
		{
			printf("\n");
		}
		else
		{
			printf("%d\n", num1%num2);
		}
		break;
	default:
		printf("\n");
		break;
	}
} 


int main()
{
	int a, b;
	char c;
	scanf("%d%d", &a, &b);
	getchar();
	scanf("%c", &c);
    Cal(a, b, c);
	return 0;
}