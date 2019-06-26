#define _CRT_SECURE_NO_WARNINGS 
//scanf쓸 때 추가 
#include <iostream> // 귀찮은 헤더들
#include <algorithm>
#include <string>
#include <stdio.h>
#include <queue>
#include <stack>
using namespace std;
int v[10][10];
bool p[100]; // 전역변수시 0(false)로 초기화

memset(v, 9999, sizeof(v)); // 배열 초기화(2차원,3차원 가능) memory.h 추가

getline(cin, s); //공백 포함 한 줄 입력시

stoi(string) // string을 int로
str = str2.substr(i,j) // str2의 부분스트링 추출


do {		//모든 순열 순서대로 출력 ex) 123, 132, 213, 231, 312, 321
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
안될땐 git pull origin master