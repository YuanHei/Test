//算法提高 c++_ch02_03
/*
编写程序实现“剪刀，石头，布”游戏。在这个游戏中，两个人同时说“剪刀”，“石头”或“布”，压过另一方的为胜者。规则是：“布”胜过“石头”，“石头”胜过“剪刀”，“剪刀”胜过“布”。要求：选择结构中使用枚举类型，结果的输出也使用枚举类型表示。
　　输入：两个数，范围为{0,1,2}，用空格隔开。0表示石头，1表示布，2表示剪刀。这两个数分别表示两个人所说的物品。
　　输出：如果前者赢，输出1。如果后者赢，输出-1。如果是平局，输出0。
*/

#include <iostream>
#include <cstdio>
using namespace std;

enum{SHITOU, BU, JIANDAO}a,b;
enum{L = 1, M = 0, R = -1}result;

int main()
{
	int a, b;
	cin >> a >> b;

	if((a == SHITOU && b == JIANDAO) || (a == BU && b == SHITOU) || (a == JIANDAO && b == BU))
	{
		result = L;
	}
	else if(a == b)
	{
		result = M;
	}
	else
	{
		result = R;
	}

	cout << result << endl;

	return 0;
}