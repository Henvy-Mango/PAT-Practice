/*
1007 素数对猜想 （20 分）
让我们定义d n为：d ​n =p ​n+1−p ​n，其中p i是第i个素数。显然有d 1=1，且对于n>1有d ​n是偶数。
“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。

现给定任意正整数N(<10^5)，请计算不超过N的满足猜想的素数对的个数

输入格式:
输入在一行给出正整数N。

输出格式:
在一行中输出不超过N的满足猜想的素数对的个数。

输入样例:
20
输出样例:
4
*/

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int>N;
	bool flag[100005];
	for (int i = 2; i < 100005; i++)
	{
		flag[i] = true;
	}

	int k;
	int time = 0;
	cin >> k;

	//段错误	超出数组范围
	//for (int i = 2; i < k; i++)
	//{
	//	if (flag[i])
	//		for (int j = i * i; j <= k; j += i)
	//			flag[j] = false;
	//}

	//筛选法构造素数表
	for (int i = 2; i < k / 2 + 1; i++) 
	{
		for (int j = 2; j*i <= k; j++) 
		{
			flag[i*j] = false;
		}
	}

	for (int i = 2; i <= k; i++)
	{
		if (flag[i])
			N.push_back(i);
	}

	if (N.size() != 0)
		for (int i = 0; i < N.size() - 1; i++)
		{
			if (N[i + 1] - N[i] == 2)
				time++;
		}

	cout << time;
	return 0;
}