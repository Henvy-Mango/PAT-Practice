/*
输入格式：
输入在一行中依次给出 A、DA 、B、DB，中间以空格分隔，其中 0<A,B<10^1​0

输出格式：
在一行中输出 PA+PB的值。

输入样例 1：
3862767 6 13530293 3
输出样例 1：
399

输入样例 2：
3862767 1 13530293 8
输出样例 2：
0
*/

#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main() {
	string A, B, DA, DB, TA, TB;
	int count_A = 0, count_B = 0;
	cin >> A >> DA >> B >> DB;
	stringstream PA, PB;

	for (int i = 0; i < A.size(); i++) {
		if (A[i] == DA[0])
			count_A++;
	}

	for (int i = 0; i < B.size(); i++) {
		if (B[i] == DB[0])
			count_B++;
	}
	TA = DA;
	for (int i = 0; i < count_A - 1; i++) {
		DA += TA;
	}
	TB = DB;
	for (int i = 0; i < count_B - 1; i++) {
		DB += TB;
	}
	if (count_A == 0)
		DA = '0';
	if (count_B == 0)
		DB = '0';

	PA << DA;
	PB << DB;

	int N1, N2;

	PA >> N1;
	PB >> N2;

	cout << N1 + N2;

	return 0;
}