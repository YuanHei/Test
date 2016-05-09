// 算法提高 c++_ch06_02  
/*
问题描述
　　编写并测试如下函数：
　　void Add (int a[], int m, int b[], int n);
　　该函数将数组b的前n个元素追加到数组a的前m个元素后，假定数组a具有至少存放m+n个元素的空间。例如，如果数组a为{22,33,44,55,66,77,88,99}，数组b为{20,30,40,50,60,70,80,90}，则调用Add(a,5,b,3)后，将把数组a变为{22,33,44,55,66,20,30,40}。注意数组b并没有改变，而且数组a中只需改变n个元素。
测试
　　输入：4行。第一行为两个整数：m，n，并以空格隔开，分别表示将要输入的数组a和数组b的元素的个数。第二行为m个整数，为数组a的元素；第三行为n个整数，为数组b的元素。第四行为两个整数m1，n1，表示把数组b的前n1个元素追加到数组a的前m1个元素后。
　　输出：1行。第一行为最后数组a中的元素，两个元素之间以逗号隔开。最后一个元素输出后，输出一个空行。
参考程序
　　#include <cassert>
　　#include <iostream>
　　using namespace std;

　　void Disp(int a[], int n)
　　{
　　for (int i=0; i<n-1; i++)
　　cout << a[i] << ", ";
　　cout << a[n-1] << endl;
　　}

　　void Add(int a[], int m, int b[], int n)
　　{
　　//...请补充完整
　　}

　　int main()
　　{
　　int* a = NULL;
　　int* b = NULL;
　　int i = 0;
　　int m, n;
　　cin >> m >> n;
　　a = new int[m + n];
　　b = new int[n];
　　for(i = 0; i < m; i++)
　　cin >> a[i];
　　for(i = 0; i < n; i++)
　　cin >> b[i];

　　int m1, n1;
　　cin >> m1 >> n1;

　　// 请补充完整


　　return 0;
　　}
*/

#include <cassert>
#include <iostream>
using namespace std;

void Disp(int a[], int n)
{
	for (int i = 0; i<n - 1; i++)
		cout << a[i] << ", ";
	cout << a[n - 1] << endl;
}

void Add(int a[], int m, int b[], int n)
{
	int k = 0;
	for (int i = m; i < m + n ; ++i)
	{
		a[i] = b[k++];
	}
}

int main()
{
	int* a = NULL;
	int* b = NULL;
	int i = 0;
	int m, n;
	cin >> m >> n;
	a = new int[m + n];
	b = new int[n];
	for (i = 0; i < m; i++)
		cin >> a[i];
	for (i = 0; i < n; i++)
		cin >> b[i];

	int m1, n1;
	cin >> m1 >> n1;

	Add(a, m1, b, n1);
	int len = (m >(m1 + n1)) ? m : (m1 + n1);
	Disp(a, len);

	return 0;
}
