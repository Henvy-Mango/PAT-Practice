/*
1013 数素数 （20 分）

令 P i表示第 i 个素数。现任给两个正整数 M≤N≤10^4,

输入格式：
输入在一行中给出 M 和 N，其间以空格分隔。

输出格式：
输出从 P M到 P N的所有素数，每 10 个数字占 1 行，其间以空格分隔，但行末不得有多余空格。

输入样例：
5 27
输出样例：
11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103
*/

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int>N;
	bool flag[150005];
	for (int i = 2; i < 150005; i++)
	{
		flag[i] = true;
	}
	int p = 150000;
	int k,l;
	cin >>l>> k;

	//筛选法构造素数表
	for (int i = 2; i < p / 2 + 1; i++)
	{
		for (int j = 2; j*i <= p; j++)
		{
			flag[i*j] = false;
		}
	}

	for (int i = 2; i <= p; i++)
	{
		if (flag[i])
			N.push_back(i);
	}
	int time = 0;
	if (N.size() != 0)
		for (int i = l-1; i < k; i++)
		{
			cout << N[i];
			time++;
			if (time % 10 != 0&&i!=k-1)
				cout << " ";
			else
				cout << endl;  
		}

	return 0;
}