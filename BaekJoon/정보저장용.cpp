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
string str = to_string(num); // int�� string���� 
if (str.find("666") != string::npos)//string�� Ư�� ���ڿ� ���Կ��� Ȯ�� string::npos��� -1�� ����

//���ڿ� cin���� �ð��ʰ��� char �迭 �Է� �޾Ƽ� string���� ��ȯ
char tmp[22];
string str;
scanf("%s", tmp);
str = tmp;

//�ִ�����
int gcd(int a, int b)
{
	if (b == 0) return a;
	else gcd(b, a%b);
}

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

//for���� ���� ������ ����ϴ¹�
for (int i = 2, j = 2; i <= N; i++, j++) {
	p[i] = p[i - 1] + j;
}

// num!�� 2�� ��� ���� ���ϴ� ��
for (ll i = 2; i <= num; i *= 2) {
	t += num / i;
}

cd / d / git
git init
git add .
git commit - m "2019"
git push - u origin master
�ȵɶ� git pull origin master