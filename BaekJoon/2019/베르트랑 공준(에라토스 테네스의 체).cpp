#include <iostream>
using namespace std;
int p[123456 * 2 + 1];
int main()
{
	for (int i = 2; i <= 123456 * 2; i++) {
		p[i] = 1;
	}
	for (int i = 2; i*i <= 123456 * 2; i++) {
		if (p[i] == 0) continue;
		for (int j = i + i; j <= 123456*2; j += i) {
			p[j] = 0;
		}
	}
	int N;
	while (true)
	{
		cin >> N;
		if (N == 0) break;
		int res = 0;
		for (int i = N + 1; i <= N * 2; i++) {
			if (p[i]==1) res++;
			else continue;
		}
		cout << res << endl;
	}
}