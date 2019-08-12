#include <iostream>
#include <algorithm>
using namespace std;
int N;
long long dist[100010], cost[100010];

int main()
{
	cin >> N;
	for (int i = 1; i <= N-1; i++) cin >> dist[i];
	for (int i = 1; i <= N; i++) cin >> cost[i];
	long long cur = 1000000000;
	long long ans = 0;
	for (int i = 1; i < N; i++) {
		cur = min(cur, cost[i]);
		ans += cur * dist[i];
	}
	cout << ans;
}