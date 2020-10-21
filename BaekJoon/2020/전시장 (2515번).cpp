#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, S;
vector<pair<int, int>> p;
vector<int> dp;
vector<int> h;

int main()
{
	cin >> N >> S;
	
	p.resize(N + 1);
	dp.resize(N+1);
	h.resize(N+1);

	for (int i = 1, a, b; i <= N; i++) {
		cin >> a >> b;
		p[i] = { a,b };
	}

	sort(p.begin(), p.end());
	
	for (int i = 1; i <= N; i++) {
		for (int j = h[i-1]; j < i; j++) {
			if (p[j].first + S <= p[i].first) {
				h[i] = j;
			}
			else break;
		}
	}

	for (int i = 1; i <= N; i++) {
		dp[i] = max(dp[i - 1], dp[h[i]] + p[i].second);
	}

	cout << dp[N];
}