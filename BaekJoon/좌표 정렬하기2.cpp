#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <algorithm>
using namespace std;
pair<int, int> p[100000 + 1]; // (y,x)��ǥ

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &p[i].second, &p[i].first);
	}
	sort(p, p + N);
	for (int i = 0; i < N; i++) {
		printf("%d %d\n", p[i].second, p[i].first);
	}
}