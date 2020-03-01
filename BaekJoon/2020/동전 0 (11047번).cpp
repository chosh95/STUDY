#include <iostream>
using namespace std;
int N, K;
int p[11];

int main()
{
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> p[i];
	int sum = 0;
	int cnt = 0, idx = N;
	while (sum <= K && idx>=1) {
		if (sum + p[idx] <= K) {
			sum += p[idx];
			cnt++;
		}
		else
			idx--;
	}
	cout << cnt;
}