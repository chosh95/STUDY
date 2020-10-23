#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<pair<int, int>> v; // 끝내야 하는 시간, 소요 시간

bool isPossible(int mid) {
	int cur = mid;
	for (int i = 0; i < N; i++) {
		if (cur + v[i].second > v[i].first) return false;
		cur += v[i].second;
	}
	return true;
}

int main()
{
	cin >> N;
	for (int a, b, i = 1; i <= N; i++) {
		cin >> a >> b;
		v.push_back({ b,a });
	}
	
	sort(v.begin(), v.end());

	int lo = 0, hi = v[0].first - v[0].second;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		if (isPossible(mid)) {
			lo = mid + 1;
		}
		else {
			hi = mid - 1;
		}
	}

	if (lo != 0) cout << hi;
	else cout << -1;
}