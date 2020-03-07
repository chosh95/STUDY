#include <iostream>
using namespace std;
int N, M;
int p[10001];

int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> p[i];
	long long res = 0;

	for (int i = 1; i <= N; i++) {
		long long sum = 0;
		for (int j = i; j <= N; j++) {
			sum += p[j];
			if (sum == M) {
				res++;
				break;
			}
			else if (sum > M)
				break;
		}
	}
	cout << res;
}