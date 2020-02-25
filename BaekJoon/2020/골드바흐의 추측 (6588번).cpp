#include <iostream>
#include <cstring>
using namespace std;
int N;
bool isPrime[1000001];

void era() {
	memset(isPrime, true, sizeof(isPrime));
	isPrime[1] = false;

	for (int i = 2; i * i<= 1000000; i++) {
		if (!isPrime[i]) continue;
		for (int j = i + i; j <= 1000000; j += i) {
			isPrime[j] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	era();
	while (true) {
		cin >> N;
		if (N == 0) break;

		bool isPossible = false;
		for (int i = 3; i <= N/2; i+=2) {
			if (!isPrime[i]) continue;
			if (!isPrime[N - i]) continue;
			cout << N << " = " << i << " + " << N - i << "\n";
			isPossible = true;
			break;
		}
		if(!isPossible) cout<<"Goldbach's conjecture is wrong.\n";
	}
}