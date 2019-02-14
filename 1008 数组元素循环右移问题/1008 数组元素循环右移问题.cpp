/*
输入格式:
每个输入包含一个测试用例，第1行输入N（1≤N≤100）和M（≥0）；第2行输入N个整数，之间用空格分隔。

输出格式:
在一行中输出循环右移M位以后的整数序列，之间用空格分隔，序列结尾不能有多余空格。

输入样例:
6 2
1 2 3 4 5 6
输出样例:
5 6 1 2 3 4
*/

//取巧法
/*
#include<iostream>
using namespace std;

int main()
{
	int N, M, num[105];
	cin >> N >> M;
	if (M > N)
		M = M % N;
	for (int i = 0; i < N; i++)
		cin >> num[i];

	for (int i = N - M; i < N; i++)
	{
		cout << num[i] << " ";
	}

	for (int i = 0; i < N - M; i++)
	{
		cout << num[i];
		if (i != N - M - 1)
			cout << " ";
	}

	return 0;
}
*/

#include<iostream>
#include<queue>
using namespace std;

int main()
{
	queue <int> Q;
	int N, M, num[105];

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> num[i];

	M %= N;

	for (int i = N - M; i < N; i++)
		Q.push(num[i]);

	for (int i = 0; i < N - M; i++)
		Q.push(num[i]);

	int t = 0;
	while (!Q.empty())
	{
		num[t] = Q.front();
		Q.pop();
		t++;
	}

	for (int i = 0; i < N; i++)
	{
		cout << num[i];
		if (i != N - 1)
			cout << " ";
	}

	return 0;
}