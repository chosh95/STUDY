#include <iostream>
using namespace std;
bool err[11];
int p[7];
int main()
{
	int N, M, a;
	cin >> N>>M;
	for (int i = 1; i <= M; i++) {
		cin >> a;
		err[a] = false;
	}
	int count = 1;
	for (int i = 100000; i > 0; i /= 10) {
		if (N >= i) {
			p[count] = N /= i;
			N %= i;
		}
		else continue;
	}
	for (int i = 1; i <= 6; i++) cout << p[i];
}