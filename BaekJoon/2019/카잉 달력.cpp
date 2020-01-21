#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
int M, N, x, y,max_year;
int gcd(int x, int y)
{
	if (x == 0) return y;
	return gcd(y%x, x);
}

int lcm(int x, int y)
{
	int z = gcd(x, y);
	return (x / z)*y;
}

void calender()
{
	for (int i = 0; i*M+x <= max_year; i++) {
		if ((i*M + x - y) % N == 0) {
			printf("%d\n", (i*M + x));
			return;
		}
	}
	printf("-1\n");
}

int main()
{
	int T;
	cin >> T;
	while (T--) {
		scanf("%d%d%d%d",&M,&N,&x,&y);
		max_year = lcm(M, N);
		calender();
	}
}