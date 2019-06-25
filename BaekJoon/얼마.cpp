#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;

int main()
{
	int T, s, n;
	cin >> T;
	while (T--) {
		int sum = 0;
		scanf("%d %d", &s, &n);
		sum = s;
		for (int i = 1; i <= n; i++) {
			int p, q;
			scanf("%d %d", &p, &q);
			sum += (p * q);
		}
		cout << sum << "\n";
	}
}