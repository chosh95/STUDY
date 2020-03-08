#include <iostream>
#include <algorithm>
using namespace std;
int p[100001];
int N, S, res = 100001;

void partSum() {
	int lo = 0, hi = 0;
	int sum = p[lo];

	while (lo <= hi && hi <= N){
		if (sum < S) {
			sum += p[++hi];
		}
		else if (sum == S) {
			res = min(res, hi - lo + 1);
			sum -= p[lo++];
		}
		else {
			res = min(res, hi - lo + 1);
			sum -= p[lo++];
		}
	}
}

int main()
{
	cin >> N >> S;
	for (int i = 0; i < N; i++) cin >> p[i];

	partSum();

	if (res == 100001) res = 0;
	cout << res;
}