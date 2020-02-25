#include <iostream>
using namespace std;
int T, N;
int p[101];

int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}

long long sumGcd(){
	long long res = 0;
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			res += gcd(p[i], p[j]);
		}
	}
	return res;
}

int main()
{
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) cin >> p[i];
		cout << sumGcd() << endl;
	}
}