//24 历届试题 邮局 
/*问题描述
　　C村住着n户村民，由于交通闭塞，C村的村民只能通过信件与外界交流。为了方便村民们发信，C村打算在C村建设k个邮局，这样每户村民可以去离自己家最近的邮局发信。

　　现在给出了m个备选的邮局，请从中选出k个来，使得村民到自己家最近的邮局的距离和最小。其中两点之间的距离定义为两点之间的直线距离。
输入格式
　　输入的第一行包含三个整数n, m, k，分别表示村民的户数、备选的邮局数和要建的邮局数。
　　接下来n行，每行两个整数x, y，依次表示每户村民家的坐标。
　　接下来m行，每行包含两个整数x, y，依次表示每个备选邮局的坐标。
　　在输入中，村民和村民、村民和邮局、邮局和邮局的坐标可能相同，但你应把它们看成不同的村民或邮局。
输出格式
　　输出一行，包含k个整数，从小到大依次表示你选择的备选邮局编号。（备选邮局按输入顺序由1到m编号）
样例输入
5 4 2
0 0
2 0
3 1
3 3
1 1
0 1
1 0
2 1
3 2
样例输出
2 4
数据规模和约定
　　对于30%的数据，1<=n<=10，1<=m<=10，1<=k<=5；
　　对于60%的数据，1<=m<=20；
　　对于100%的数据，1<=n<=50，1<=m<=25，1<=k<=10。
*/


#include<iostream>
#include<stdlib.h>
#include<math.h>

using namespace std;
int n, m, k, j, c[55][2], y[27][2], d[12], f1, f2, f[55] = { 0 };
double yc[27][55], s = 1000000000;

void dfs(int t, int i, int o[12], double w[55], double sum)
{
	if (i <= m + 1)
	{
		if (t == k)
		{
			if (sum < s)
			{
				s = sum;
				for (j = 0; j < k; j++)
				{
					d[j] = o[j];
				}
			}
		}
		else if (i <= m && t < k)
		{
			double ww[55];
			for (j = 1; j <= n; j++)
			{
				ww[j] = w[j];
			}
			dfs(t, i + 1, o, w, sum);
			f1 = 1, f2 = 0;
			if (!f[i])
			{
				o[t] = i;
				if (t > 0)
				{
					f2 = 1;
					for (j = 1; j <= n; j++)
					{
						if (ww[j]>yc[i][j])
						{
							sum = sum - ww[j] + yc[i][j];
							ww[j] = yc[i][j];
							f1 = 0;
						}
					}
				}
				else
				{
					for (j = 1; j <= n; j++)
					{
						sum += yc[i][j];
						ww[j] = w[j] = yc[i][j];
					}
				}
				if (f1 && f2)
				{
					f[i] = 1;
					dfs(t, i + 1, o, w, sum);
				}
				else
				{
					dfs(t + 1, i + 1, o, ww, sum);
				}
			}
		}
	}
}

int main()
{
	int i, j, o[12];
	double w[55], ww[55];
	cin >> n >> m >> k;
	for (i = 1; i <= n; i++)
	{
		cin >> c[i][0] >> c[i][1];
	}
	for (i = 1; i <= m; i++)
	{
		cin >> y[i][0] >> y[i][1];
		for (j = 1; j <= n; j++)
		{
			yc[i][j] = sqrt((c[j][0] - y[i][0])*(c[j][0] - y[i][0]) + (c[j][1] - y[i][1])*(c[j][1] - y[i][1]));
		}
	}
	dfs(0, 1, o, w, 0);
	for (i = 0; i < k; i++)
	{
		cout << d[i] << " ";
	}
	cout << endl;
	return 0;
}
