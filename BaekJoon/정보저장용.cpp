#define _CRT_SECURE_NO_WARNINGS 
//scanf�� �� �߰� 
#include <iostream> // ������ �����
#include <algorithm>
#include <string>
#include <stdio.h>
#include <queue>
#include <stack>
using namespace std;
int v[10][10];
bool p[100]; // ���������� 0(false)�� �ʱ�ȭ

memset(v, 9999, sizeof(v)); // �迭 �ʱ�ȭ(2����,3���� ����) memory.h �߰�

getline(cin, s); //���� ���� �� �� �Է½�

stoi(string) // string�� int��
str = str2.substr(i,j) // str2�� �κн�Ʈ�� ����


do {		//��� ���� ������� ��� ex) 123, 132, 213, 231, 312, 321
	for (int i = 0; i < N; i++) {
		cout << p[i] << " ";
	}
	cout << "\n";
} while (next_permutation(p, p + N));

//union-find
int find(int a)
{
	if (parent[a] == a) return parent[a];
	else return parent[a] = find(parent[a]);
}
void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b) return;
	else parent[a] = b;
}




cd / d / git
git init
git add .
git commit - m "2019"
git push - u origin master
�ȵɶ� git pull origin master