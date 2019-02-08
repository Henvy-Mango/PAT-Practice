/*
1002 写出这个数 （20 分）
读入一个正整数 n，计算其各位数字之和，用汉语拼音写出和的每一位数字。

输入格式：
每个测试输入包含 1 个测试用例，即给出自然数 n 的值。这里保证 n 小于 10^100

输出格式：
在一行内输出 n 的各位数字之和的每一位，拼音数字间有 1 空格，但一行中最后一个拼音数字后没有空格。

输入样例：
1234567890987654321123456789
输出样例：
yi san wu
*/

#include<iostream>
#include<string.h>
using namespace std;

string inttostring(int n);	//int转string 

int main()
{
	char num[100];

	cin >> num;

	int n = 0, time = strlen(num);

	for (int i = 0; i < time; i++)
	{
		n += num[i] - '0';
	}

	string S;
	S = inttostring(n);

	time = S.size();

	for (int i = 0; i < time; i++)
	{
		if (S[i] == '0')
			cout << "ling";
		else if (S[i] == '1')
			cout << "yi";
		else if (S[i] == '2')
			cout << "er";
		else if (S[i] == '3')
			cout << "san";
		else if (S[i] == '4')
			cout << "si";
		else if (S[i] == '5')
			cout << "wu";
		else if (S[i] == '6')
			cout << "liu";
		else if (S[i] == '7')
			cout << "qi";
		else if (S[i] == '8')
			cout << "ba";
		else if (S[i] == '9')
			cout << "jiu";
		if (i != time - 1)
			cout << " ";
	}
	return 0;
}

string inttostring(int n) //int转string 
{
	const int max = 100;
	int m = n;
	char s[max];	//从个位开始记录
	char ss[max];	//逆序
	int i = 0, j = 0;

	if (n < 0)
	{
		m = 0 - m;
		j = 1;
		ss[0] = '-';
	}

	while (m > 0)
	{
		s[i++] = m % 10 + '0';	//'0'=48,存储个位数到字符串
		m /= 10;	//求十位数，如此重复
	}
	s[i] = '\0';	//设置结束符
	i = i - 1;

	while (i >= 0)
	{
		ss[j++] = s[i--];	//逆序存储
	}
	ss[j] = '\0';

	return ss;	//设置结束符
}