#include<iostream>
#include<string.h>

#include <sstream>

using namespace std;
//ע�⣡������Ҫ�ĳ�main
int main0()
{
	char num[100];

	cin >> num;

	int n = 0, time = strlen(num);

	for (int i = 0; i < time; i++)
	{
		n += num[i] - '0';
	}

	//����������⣬stringstream ss�������²�ͬ�����ͣ�Ȼ���³���ͬ�����͡�
	/*
		//stringתint						//intתstring
		string s = "17";					int aa = 30;

		stringstream ss;					stringstream ss;
		ss << s;							ss << aa;

		int i;								string s2;
		ss >> i;							ss >> s2;
		cout << i << endl; // 17			cout<<s2<<endl;	// 30
	*/
	stringstream ss;
	ss << n;
	string S = ss.str();	//��һ��д��

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