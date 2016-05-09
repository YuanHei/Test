//22 历届试题 国王的烦恼
/*问题描述
　　C国由n个小岛组成，为了方便小岛之间联络，C国在小岛间建立了m座大桥，每座大桥连接两座小岛。两个小岛间可能存在多座桥连接。然而，由于海水冲刷，有一些大桥面临着不能使用的危险。

　　如果两个小岛间的所有大桥都不能使用，则这两座小岛就不能直接到达了。然而，只要这两座小岛的居民能通过其他的桥或者其他的小岛互相到达，他们就会安然无事。但是，如果前一天两个小岛之间还有方法可以到达，后一天却不能到达了，居民们就会一起抗议。

　　现在C国的国王已经知道了每座桥能使用的天数，超过这个天数就不能使用了。现在他想知道居民们会有多少天进行抗议。
输入格式
　　输入的第一行包含两个整数n, m，分别表示小岛的个数和桥的数量。
　　接下来m行，每行三个整数a, b, t，分别表示该座桥连接a号和b号两个小岛，能使用t天。小岛的编号从1开始递增。
输出格式
　　输出一个整数，表示居民们会抗议的天数。
样例输入
4 4
1 2 2
1 3 2
2 3 1
3 4 3
样例输出
2
样例说明
　　第一天后2和3之间的桥不能使用，不影响。
　　第二天后1和2之间，以及1和3之间的桥不能使用，居民们会抗议。
　　第三天后3和4之间的桥不能使用，居民们会抗议。
数据规模和约定
　　对于30%的数据，1<=n<=20，1<=m<=100；
　　对于50%的数据，1<=n<=500，1<=m<=10000；
　　对于100%的数据，1<=n<=10000，1<=m<=100000，1<=a, b<=n， 1<=t<=100000。
*/
#include <iostream>
#include <algorithm>
#define maxn  10000+5
#define maxm  100000+5
using namespace std;

int f[maxn], lastday;
struct node
{
	int x, y, v;
} N[maxm];

bool cmp(node a, node b)
{
	return a.v>b.v;
}

int Find(int x)
{             //找 x 所在的树根
	return f[x] == x ? x : f[x] = Find(f[x]);
}

bool Union(int x, int y)
{
	int tx = Find(x), ty = Find(y);
	if (tx == ty)
	{
		return false;           //它俩在同一个连通分量
	}
	f[tx] = ty;                 //合并两个连通分量
	return true;
}
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> N[i].x >> N[i].y >> N[i].v;
	}
	sort(N, N + m, cmp);
	for (int i = 0; i <= n; i++)
	{
		f[i] = i;       //初始化并查集
	}
	int cnt = 0;
	lastday = -1;
	for (int i = 0; i < m; i++)
	{
		if (Union(N[i].x, N[i].y) && N[i].v != lastday)
		{ //两个小岛不连通，且与上一个大桥的天数不同
			cnt++;
			lastday = N[i].v;
		}
	}
	cout << cnt << endl;
	return 0;
}