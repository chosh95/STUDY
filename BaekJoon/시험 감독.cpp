#include <iostream>
using namespace std;
long long p[1000001];
long long q[1000001];

int main()
{
	long long N;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> p[i];
	long long B, C;
	long long res = 0;
	cin >> B >> C;
	for (int i = 1; i <= N; i++) {
		if (p[i] >= B) {
			p[i] -= B;
			res += 1;
		}
		else {
			p[i] = 0;
			res += 1;
		}
	}
	for (int i = 1; i <= N; i++) {
		if (p[i] == 0)
			continue;
		else {
			if (p[i] % C == 0) res += (p[i] / C);
			else res += (p[i] / C + 1);
		}
	}
	cout << res;
}