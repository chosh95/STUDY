#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int main()
{
	int p[10001] = { 0 };
	int N,tmp;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &tmp);
		p[tmp]++;
	}
	for (int i = 1; i <= 10000; i++) {
		if (p[i] >= 1) {
			for (int j = 1; j <= p[i]; j++) {
				printf("%d\n", i);
			}
		}
	}
}