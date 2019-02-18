/*
1014 福尔摩斯的约会 （20 分）
大侦探福尔摩斯接到一张奇怪的字条：我们约会吧！ 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm。
大侦探很快就明白了，字条上奇怪的乱码实际上就是约会的时间星期四 14:04，
因为前面两字符串中第 1 对相同的大写英文字母（大小写有区分）是第 4 个字母 D，代表星期四；
第 2 对相同的字符是 E ，那是第 5 个英文字母，代表一天里的第 14 个钟头
（于是一天的 0 点到 23 点由数字 0 到 9、以及大写字母 A 到 N 表示）；
后面两字符串第 1 对相同的英文字母 s 出现在第 4 个位置（从 0 开始计数）上，代表第 4 分钟。
现给定两对字符串，请帮助福尔摩斯解码得到约会的时间。

输入格式：
输入在 4 行中分别给出 4 个非空、不包含空格、且长度不超过 60 的字符串。

输出格式：
在一行中输出约会的时间，格式为 DAY HH:MM，其中 DAY 是某星期的 3 字符缩写，
即 MON 表示星期一，TUE 表示星期二，WED 表示星期三，THU 表示星期四，FRI 表示星期五，SAT 表示星期六，SUN 表示星期日。
题目输入保证每个测试存在唯一解。

输入样例：
3485djDkxh4hhGE
2984akDfkkkkggEdsb
s&hgsfdk
d&Hyscvnm
输出样例：
THU 14:04
*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
	string A, B, C, D;
	cin >> A >> B >> C >> D;
	int flag = 0;
	char day, hour;
	int minute;

	int n = A.size() < B.size() ? A.size() : B.size();
	//审题重要!!!
	//字符相同且位置也相同
	for (int i = 0; i < n; i++)
	{
		if (A[i] == B[i] && flag == 0)
		{
			//条件一定要仔细看!!!
			if (A[i] >= 'A' && A[i] <= 'G')
			{
				day = A[i];
				flag = 1;
			}
		}
		else if (A[i] == B[i] && flag == 1)
		{
			if ((A[i] >= 'A'&&A[i] <= 'N') || (A[i] >= '0'&&A[i] <= '9'))
			{
				hour = A[i];
				break;
			}
		}
	}
	n = C.size() < D.size() ? C.size() : D.size();
	for (int i = 0; i < n; i++)
	{
		if (C[i] == D[i])
		{
			if ((C[i] >= 'A'&&C[i] <= 'Z') || (C[i] >= 'a'&&C[i] <= 'z'))
			{
				minute = i;
				break;
			}
		}
	}

	if (day == 'A')
		cout << "MON" << " ";
	if (day == 'B')
		cout << "TUE" << " ";
	if (day == 'C')
		cout << "WED" << " ";
	if (day == 'D')
		cout << "THU" << " ";
	if (day == 'E')
		cout << "FRI" << " ";
	if (day == 'F')
		cout << "SAT" << " ";
	if (day == 'G')
		cout << "SUN" << " ";

	if (hour >= '0'&&hour <= '9')
		cout << "0" << hour << ":";
	else
		printf("%d:", hour - 55);

	if (minute <= 9)
		cout << "0" << minute;
	else
		cout << minute;
	return 0;
}