#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <string>
#include <cstdio>
#include <map>
using namespace std;
int N, M;

int main()
{
	map<string, int> m1;
	map<int, string> m2;
	scanf("%d %d", &N, &M);
	char tmp[22];
	string str;

	for (int i = 1; i <= N; i++) {
		scanf("%s", tmp);
		m1[tmp] = i;
		m2[i] = tmp;
	}

	for (int i = 1; i <= M; i++) {
		scanf("%s", tmp);
		str = tmp;
		if (tmp[0] >= 'A' && tmp[0] <= 'Z') {
			printf("%d\n", m1[str.c_str()]);
		}
		else
			printf("%s\n", m2[atoi(tmp)].c_str());
	}
}