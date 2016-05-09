//125  算法提高 促销购物 
/*
问题描述
　　张超来到了超市购物。
　　每个物品都有价格，正好赶上商店推出促销方案。就是把许多东西一起买更便宜（保证优惠方案一定比原价便宜）。物品要买正好的个数，而且不能为了便宜而买不需要的物品。
　　张超拿到了优惠方案，和需要购买的物品清单，当然想求出最小的花费。他是信息学选手，自然地想到写个程序解决问题。
输入格式
　　第一行促销物品的种类数（0 <= s <= 99）。
　　第二行..第s+1 行每一行都用几个整数来表示一种促销方式。
　　第一个整数 n （1 <= n <= 5），表示这种优惠方式由 n 种商品组成。
　　后面 n 对整数 c 和 k 表示 k （1 <= k <= 5）个编号为 c （1 <= c <= 999）的商品共同构成这种方案。
　　最后的整数 p 表示这种优惠的优惠价（1 <= p <= 9999）。也就是把当前的方案中的物品全买需要的价格。
　　第 s+2 行这行一个整数b （0 <= b <= 5），表示需要购买 b 种不同的商品。
　　第 s+3 行..第 s+b+2 行这 b 行中的每一行包括三个整数：c ，k ，和 p 。
　　C 表示唯一的商品编号（1 <= c <= 999），
　　k 表示需要购买的 c 商品的数量（1 <= k <= 5）。
　　p 表示 c 商品的原价（1 <= p <= 999）。
　　最多购买 5*5=25 个商品。
输出格式
　　一个整数ans，表示需要花的最小费用
样例输入
2
1 7 3 5
2 7 1 8 2 10
2
7 3 2
8 2 5
样例输出
14
*/

#include <iostream>
#include <string.h>

#define INF 0x3f3f3f3f
#define min(a,b) (a)>(b)?(b):(a)
using namespace std;

struct Data1
{
	int num[1010], money;
}a[110];

struct Data2
{
	int c, k, p;
}b[10];

int n, m, res[6][6][6][6][6];

int main()
{
	cin >> n;
	int i, j;
	for (i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		for (j = 0; j < t; j++)
		{
			int k, l;
			cin >> k >> l;
			a[i].num[k] = l;
		}
		cin >> a[i].money;
	}
	cin >> m;
	for (i = 0; i < m; i++)
	{
		cin >> b[i].c >> b[i].k >> b[i].p;
		a[n].money = b[i].p;
		a[n++].num[b[i].c] = 1;
	}

	memset(res, INF, sizeof(res));

	res[0][0][0][0][0] = 0;
	int b1, b2, b3, b4, b5, m1, m2, m3, m4, m5;
	for (i = 0; i < n; i++)
	{
		m1 = a[i].num[b[0].c];
		m2 = a[i].num[b[1].c];
		m3 = a[i].num[b[2].c];
		m4 = a[i].num[b[3].c];
		m5 = a[i].num[b[4].c];
		for (b1 = m1; b1 <= b[0].k; b1++)
		{
			for (b2 = m2; b2 <= b[1].k; b2++)
			{
				for (b3 = m3; b3 <= b[2].k; b3++)
				{
					for (b4 = m4; b4 <= b[3].k; b4++)
					{
						for (b5 = m5; b5 <= b[4].k; b5++)
						{
							res[b1][b2][b3][b4][b5] = min(res[b1][b2][b3][b4][b5], res[b1 - m1][b2 - m2][b3 - m3][b4 - m4][b5 - m5] + a[i].money);
						}
					}
				}
			}
		}
	}
	cout << res[b[0].k][b[1].k][b[2].k][b[3].k][b[4].k] << endl;

	return 0;
}