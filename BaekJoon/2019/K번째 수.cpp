#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
int p[5000000 + 1];
int main()
{
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &p[i]);
	}
	sort(p + 1, p + N + 1);
	cout << p[K];
}