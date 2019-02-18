/*
1012 数字分类 （20 分）

输入格式：
每个输入包含 1 个测试用例。每个测试用例先给出一个不超过 1000 的正整数 N，随后给出 N 个不超过 1000 的待分类的正整数。数字间以空格分隔。

输出格式：
对给定的 N 个正整数，按题目要求计算 A 1~A 5并在一行中顺序输出。数字间以空格分隔，但行末不得有多余空格。

若其中某一类数字不存在，则在相应位置输出 N。

输入样例 1：
13 1 2 3 4 5 6 7 8 9 10 20 16 18
输出样例 1：
30 11 2 9.7 9
输入样例 2：
8 1 2 4 5 6 7 9 16
输出样例 2：
N 11 2 N 9
*/

#include<iostream>
#include<vector>
using namespace std;

/*
PAT测试点八不过
查询资料发现，可能有A2正好为0的情况
所以不能以 R[i] 是否为0来判断数字是否存在
需要额外添加判断条件

真老奸巨猾。。。
*/

int main()
{
	int k;
	cin >> k;
	vector<int>num(k);
	vector<int>A1;
	vector<int>A2;
	vector<int>A3;
	vector<int>A4;
	vector<int>A5;
	vector<float>R(6);

	for (int i = 0; i < k; i++)
	{
		cin >> num[i];
		if (num[i] % 5 == 0)
			A1.push_back(num[i]);
		if (num[i] % 5 == 1)
			A2.push_back(num[i]);
		if (num[i] % 5 == 2)
			A3.push_back(num[i]);
		if (num[i] % 5 == 3)
			A4.push_back(num[i]);
		if (num[i] % 5 == 4)
			A5.push_back(num[i]);
	}

	R[1] = 0;
	for (auto p = A1.begin(); p != A1.end(); p++)
	{
		if (*p % 2 == 0)
			R[1] += *p;
	}

	R[2] = 0;
	for (int i = 0; i < A2.size(); i++)
	{
		if (i % 2 == 0)
			R[2] += A2[i];
		else
			R[2] -= A2[i];
	}

	R[3] = A3.size();

	R[4] = 0;
	for (int i = 0; i < A4.size(); i++)
	{
		R[4] += A4[i];
	}
	if (R[4] != 0)
		R[4] /= (float)A4.size();

	R[5] = 0;

	for (int i = 0; i < A5.size(); i++)
	{
		if (A5[i] > R[5])
			R[5] = A5[i];
	}

	R[0] = A2.size();

	for (int i = 1; i < 6; i++)
	{
		//注意A2可能交错相加减，可能正好为0
		//判断一下A2数组大小是否为0即可
		if (R[i] == 0)
		{
			if(i!=2)
				cout << "N";
			else if(i==2&&R[0]==0)
				cout << "N";
			else if (i == 2 && R[0] != 0)
				cout << R[i];
		}
		else if (i != 4)
			cout << R[i];
		else if (i == 4)
			printf("%.1f", R[i]);
		if (i != 5)
			cout << " ";
	}

	return 0;
}