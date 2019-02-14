/*
输入格式:
以指数递降方式输入多项式非零项系数和指数（绝对值均为不超过 1000 的整数）。数字间以空格分隔。

输出格式:
以与输入相同的格式输出导数多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。
注意“零多项式”的指数和系数都是 0，但是表示为 0 0。

输入样例:
3 4 -5 2 6 1 -2 0
输出样例:
12 3 -10 1 6 0
*/

#include <cstdio>

int main()
{
	int m, n;
	int flag = 1;
	while (scanf("%d %d", &m, &n) != EOF) 
	{
		if (n > 0) 
		{
			if (flag == 1) 
			{
				printf("%d %d", m*n, n - 1);
				flag = 0;
			}
			else 
			{
				printf(" %d %d", m*n, n - 1);
			}
		}
	}
	if (flag == 1)
		printf("0 0");

	return 0;
}