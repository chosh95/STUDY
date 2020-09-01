#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <string>
using namespace std;
long long N;
long long dp[1000001];
long long idx = 0;

void bfs(){
	queue<long long> q;
	for (int i = 0; i <= 9; i++) {
		dp[idx++] = i;
		q.push(i);
	}

	while (!q.empty()) {
		long long cur = q.front();
		q.pop();

		for (int i = 0; i <= 9; i++) {
			string str = to_string(cur);
			if (str[str.size() - 1] - '0' <= i) break;
			long long next = cur * 10 + i;
			q.push(next);
			dp[idx++] = next;
		}
	}
}

int main()
{
	cin >> N;

	bfs();

	if (N != 0 && dp[N] == 0) cout << -1;
	else cout << dp[N];
}