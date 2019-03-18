#include <iostream>
#include <algorithm>
using namespace std;
int gcd(int a, int b)
{
	if (b == 0) return a;
	else return gcd(b, a%b);
}
int main()
{
	int T;
	cin >> T;
	while (T--) {
		int p[101];
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) 
			cin >> p[i];
		sort(p + 1, p + n);
		long long sum = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				sum += gcd(p[i], p[j]);
			}
		}
		cout << sum << "\n";
	}
}