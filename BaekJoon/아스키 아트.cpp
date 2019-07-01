#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int N, M;
char cal(int a, int b, int c)
{
	int tmp = 2126 * a + 7152 * b + 722 * c;
	if (tmp < 510000) return '#';
	else if (tmp < 1020000) return 'o';
	else if (tmp < 1530000) return '+';
	else if (tmp < 2040000) return '-';
	else return '.';
}

int main()
{
	cin >> N >> M;
	int a, b, c;
	char t;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d %d %d", &a, &b, &c);
			cout << cal(a, b, c);
		}
		cout << "\n";
	}
}