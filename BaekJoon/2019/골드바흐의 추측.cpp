#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <memory.h>
#include <string>
using namespace std;
bool p[1000000 + 1];

int main()
{
	memset(p, true, sizeof(p));
	p[1] = false;
	for (int i = 2; i*i <= 1000000; i++) {
		if (p[i] == false) continue;
		for (int j = i+i; j <= 1000000; j += i) {
			p[j] = false;
		}
	}

	int N;
	while (true) {
		bool tmp = false;
		scanf("%d", &N);
		if (N==0) break;
		for (int i = 3; i <= N / 2 + 1; i+=2) {
			if (p[i] == true && p[N - i] == true) {
				printf("%d = %d + %d\n", N, i, N - i);
				tmp = true;
				break;
			}
		}
		if (tmp == false) printf("Goldbach's conjecture is wrong.\n");
	}
	return 0;
}