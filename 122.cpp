
//122 算法提高 去注释 
/*
　　去注释
问题
　　给你一段C++代码，将其中的注释去除后输出剩余的代码。
　　注释共有两种形式：
　　1. 行注视：以//开头，一直作用到行尾为止。
　　例子：
　　int n;//n表示数据规模
　　int a;
　　去注释后：
　　int n;
　　int a;
　　注意：保留行尾换行符
　　2. 段注视：以/*开头，到\*\/结尾，中间部分都是注释，可以跨行。
　　例子：
　　int main() {
　　//我是一段注释
　　}
　　//去注释后：
　　int main() {

　　}
　　注意：由于在线评测系统（Online Judge）对网页显示文本作了格式化，一些空行会被删去，导致上面显示的删除后的结果不正确。删除注释后，剩余的代码应该是三行，两行代码之间有一个空行。这是因为：在段注释结尾符的后面有一个换行符，它不在注释内，需要保留。
输入格式
　　一段C++程序代码
输出格式
　　去掉注释部分后的程序
样例输入
int main() {
//我是一段注释

int n;
//n表示数据规模
}
样例输出
int main() {

int n;
}

注意：和之前题目中的解释一样，在int n;之前有一个空行，被在线评测系统删掉，实际程序输出应该有该空行。
输入方法
　　此题按字符输入，即不断输入下一个字符，直到字符流结束。
　　char c;
　　C函数方法：
　　while ((c = getchar()) != EOF) {
　　处理..
　　}
　　C++流方法：
　　while ((c = cin.get()) != EOF) {
　　处理..
　　}
*/
#include <stdio.h>
#include <string.h>
char a[10000]={0};
int main()
{
	int len=0,i=0,j;
	char c;
	while ((c = getchar()) != EOF)
	{
	 	a[len]=c;
	 	len++;
	}
	while(i<len)
	{
		if(strncmp(a+i,"//",2)==0)
		{
			j=i+2;
			while(j<len)
			{
				if(a[j]=='\n') 
				{
					i=j;
					break;
				}
				j++;
			}
		}
		else if(strncmp(a+i,"/*",2)==0)
		{
			j=i+2;
			while(j<len)
			{
				if(strncmp(a+j,"*/",2)==0)
				{
					i=j+2;
					break;
				}
				j++;
			}
		}
		else
		{
			printf("%c",a[i]);
		    i++;
		} 
	}
	
	return 0;
}