#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
bool p[10000 + 1];

void bach(int N)
{
	for (int i = N/2; i >= 2; i--) {
		if (p[i] == true && p[N - i] == true) {
			cout << i << " " << N - i << "\n";
			return;
		}
	}
}

int main()
{
	int T,N;
	scanf("%d", &T);
	for (int i = 0; i <= 10000; i++) p[i] = true;
	p[1] = false;
	for (int i = 2; i*i <= 10000; i++) {
		if (p[i] == false) continue;
		for (int j = i + i; j <= 10000; j += i) {
			p[j] = false;
		}
	}

	while (T--) {
		scanf("%d",&N);
		bach(N);
	}
}
