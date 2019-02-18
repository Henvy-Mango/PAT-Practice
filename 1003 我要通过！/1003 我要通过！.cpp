/*
只要读入的字符串满足下列条件，系统就输出“答案正确”，否则输出“答案错误”。

得到“答案正确”的条件是：

字符串中必须仅有 P、 A、 T这三种字符，不可以包含其它字符；
任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串；
如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a、 b、 c 均或者是空字符串，或者是仅由字母 A 组成的字符串。
现在就请你为 PAT 写一个自动裁判程序，判定哪些字符串是可以获得“答案正确”的。

输入格式：
每个测试输入包含 1 个测试用例。第 1 行给出一个正整数 n (<10)，是需要检测的字符串个数。
接下来每个字符串占一行，字符串长度不超过 100，且不包含空格。

输出格式：
每个字符串的检测结果占一行，如果该字符串可以获得“答案正确”，则输出 YES，否则输出 NO。

输入样例：
8
PAT
PAAT
AAPATAA
AAPAATAAAA
xPATx
PT
Whatever
APAAATAA
输出样例：
YES
YES
YES
YES
NO
NO
NO
NO
*/

#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	int time, P_L, T_L, cout_T = 0, cout_P = 0;
	char A[10][100];
	int id = -1;
	cin >> time;
	for (int i = 0; i < time; i++)
	{
		cin >> A[i];
	}
	//字符串中必须仅有 P、 A、 T这三种字符，不可以包含其它字符；
	//任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串；
	//如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a、 b、 c 均或者是空字符串，或者是仅由字母 A 组成的字符串。
	for (int i = 0; i < time; i++)
	{
		if (strcmp(A[i], "PAT") == 0)
		{
			cout << "YES" << endl;
			continue;
		}
		P_L = -1;
		T_L = -1;
		cout_P = 0;
		cout_T = 0;
		for (int j = 0; j < strlen(A[i]); j++)
		{
			if (A[i][j] != 'P'&&A[i][j] != 'A'&&A[i][j] != 'T')
			{
				id = 0;
				break;
			}
			if (A[i][j] == 'P')
			{
				P_L = j;
				cout_P++;
			}
			if (A[i][j] == 'T')
			{
				T_L = j;
				cout_T++;
			}
			if (cout_T > 1 || cout_P > 1)
			{
				id = 0;
			}
		}
		if (T_L == P_L + 1)
		{
			id = 0;
		}
		//如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a、 b、 c 均或者是空字符串，或者是仅由字母 A 组成的字符串。
		//注意！其中a*b=c
		//APAAATAA为NO
		//AAPATAA为YES
		//AAPAATAAAA为YES
		else if (P_L*(T_L - P_L - 1) == strlen(A[i]) - T_L - 1 && id != 0)
			id = 1;
		else
			id = 0;
		if (id)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}