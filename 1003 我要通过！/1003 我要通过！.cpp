/*
ֻҪ������ַ�����������������ϵͳ�����������ȷ��������������𰸴��󡱡�

�õ�������ȷ���������ǣ�

�ַ����б������ P�� A�� T�������ַ��������԰��������ַ���
�������� xPATx ���ַ��������Ի�á�����ȷ�������� x �����ǿ��ַ����������ǽ�����ĸ A ��ɵ��ַ�����
��� aPbTc ����ȷ�ģ���ô aPbATca Ҳ����ȷ�ģ����� a�� b�� c �������ǿ��ַ����������ǽ�����ĸ A ��ɵ��ַ�����
���ھ�����Ϊ PAT дһ���Զ����г����ж���Щ�ַ����ǿ��Ի�á�����ȷ���ġ�

�����ʽ��
ÿ������������� 1 �������������� 1 �и���һ�������� n (<10)������Ҫ�����ַ���������
������ÿ���ַ���ռһ�У��ַ������Ȳ����� 100���Ҳ������ո�

�����ʽ��
ÿ���ַ����ļ����ռһ�У�������ַ������Ի�á�����ȷ��������� YES��������� NO��

����������
8
PAT
PAAT
AAPATAA
AAPAATAAAA
xPATx
PT
Whatever
APAAATAA
���������
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
	//�ַ����б������ P�� A�� T�������ַ��������԰��������ַ���
	//�������� xPATx ���ַ��������Ի�á�����ȷ�������� x �����ǿ��ַ����������ǽ�����ĸ A ��ɵ��ַ�����
	//��� aPbTc ����ȷ�ģ���ô aPbATca Ҳ����ȷ�ģ����� a�� b�� c �������ǿ��ַ����������ǽ�����ĸ A ��ɵ��ַ�����
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
		//��� aPbTc ����ȷ�ģ���ô aPbATca Ҳ����ȷ�ģ����� a�� b�� c �������ǿ��ַ����������ǽ�����ĸ A ��ɵ��ַ�����
		//ע�⣡����a*b=c
		//APAAATAAΪNO
		//AAPATAAΪYES
		//AAPAATAAAAΪYES
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