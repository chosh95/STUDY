#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M;
int visit[10];
vector<int> input;

void dfs(int idx, int cnt, vector<int> v) {
	if (cnt == M) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < N; i++) {
		v.push_back(input[i]);
		dfs(i, cnt + 1, v);
		v.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int tmp, i = 0; i < N; i++) {
		cin >> tmp;
		input.push_back(tmp);
	}
	sort(input.begin(), input.end());
	vector<int> tmp;

	dfs(-1, 0, tmp);

	return 0;
}