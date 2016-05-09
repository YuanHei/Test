// 126 算法提高 扫雷  
/*
问题描述
　　扫雷游戏你一定玩过吧！现在给你若干个n×m的地雷阵，请你计算出每个矩阵中每个单元格相邻单元格内地雷的个数，每个单元格最多有8个相邻的单元格。 0<n,m<=100
输入格式
　　输入包含若干个矩阵，对于每个矩阵，第一行包含两个整数n和m，分别表示这个矩阵的行数和列数。接下来n行每行包含m个字符。安全区域用‘.’表示，有地雷区域用'*'表示。
当n=m=0时输入结束。
输出格式
　　对于第i个矩阵，首先在单独的一行里打印序号：“Field #i:”,接下来的n行中，读入的'.'应被该位置周围的地雷数所代替。输出的每两个矩阵必须用一个空行隔开。
样例输入
4 4
*...
....
.*..
....
3 5
**...
.....
.*...
0 0
样例输出
Field #1:
*100
2210
1*10
1110

Field #2:
**100
33200
1*100
（注意两个矩阵之间应该有一个空行，由于oj的格式化这里不能显示出来）
数据规模和约定
　　0<n,m<=100
*/

#include <stdio.h>
#include <malloc.h>
typedef struct Mine
{
	int n;
	int m;
	char a[100][100];
	struct Mine *next;
}Mine;

int main()
{
	int n, m, i, j, t, sign = 1, num, k = 1;
	Mine *p = NULL, *head = NULL, *q = NULL;
	scanf("%d%d", &n, &m);
	while (m != 0 && n != 0)
	{
		p = (Mine *)malloc(sizeof(Mine));
		p->n = n; p->m = m;
		for (i = 0; i<n; i++)
		{
			scanf("%c", &t);//去掉换行符 
			for (j = 0; j < m; j++)
			{
				scanf("%c", &p->a[i][j]);
			}
		}
		if (sign)//第一次分配空间 
		{
			sign = 0;
			head = p;
			q = p;
		}
		else
		{
			q->next = p;
			q = p;
		}
		scanf("%d%d", &n, &m);
	}
	p->next = 0;
	while (head != 0)
	{
		for (i = 0; i < head->n; i++)
		{
			for (j = 0; j<head->m; j++)
			{
				if (head->a[i][j] != '*')
				{
					num = 0;
					if (i>0) //不是顶边 
					{
						if (head->a[i - 1][j] == '*')
						{
							num++;//上 
						}
						if (j > 0 && head->a[i - 1][j - 1] == '*')
						{
							num++;  //左上 
						}
						if (j + 1 < head->m && head->a[i - 1][j + 1] == '*')
						{
							num++; //右上 
						}
					}
					if (i + 1<head->n) //不是底边
					{
						if (head->a[i + 1][j] == '*')
						{
							num++;//下 
						}
						if (j > 0 && head->a[i + 1][j - 1] == '*')
						{
							num++; //左下 
						}
						if (j + 1<head->m && head->a[i + 1][j + 1] == '*')
						{
							num++; //右下
						}
					}
					if (j > 0 && head->a[i][j - 1] == '*')
					{
						num++; //左
					}
					if (j + 1 < head->m && head->a[i][j + 1] == '*')
					{
						num++; //右
					}
					head->a[i][j] = num;
				}
			}
		}
		printf("Field #%d:\n", k);
		for (i = 0; i<head->n; i++)
		{
			for (j = 0; j < head->m; j++)
			{
				if (head->a[i][j] != '*')
				{
					printf("%d", head->a[i][j]);
				}
				else
				{
					printf("*");
				}
			}
			printf("\n");
		}
		printf("\n");
		k++;
		head = head->next;
	}
	return 0;
}