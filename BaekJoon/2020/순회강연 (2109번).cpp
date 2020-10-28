#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N;
vector<pair<int, int>> v;
int visit[10001];

int main()
{
	cin >> N;

	for (int p, d, i = 0; i < N; i++) {
		cin >> p >> d;
		v.push_back({ p,d });
	}

	sort(v.begin(), v.end(),greater<pair<int,int>>());

	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		int cur = v[i].second;
		while (visit[cur]==1)
			cur--;
		if (cur == 0) continue;
		visit[cur] = 1;
		sum += v[i].first;
	}
	cout << sum;
}