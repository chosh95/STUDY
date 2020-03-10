#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M;
int visit[10];
vector<int> input;

void dfs(int idx, int cnt, vector<int>& v) {
	if (cnt == M) {
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (visit[i] == 1) continue;
		v.push_back(input[i]);
		visit[i] = 1;
		dfs(i, cnt+1, v);
		visit[i] = 0;
		v.pop_back();
	}
}

int main()
{
	cin >> N >> M;
	input.push_back(0);
	for (int tmp, i = 1; i <= N; i++) {
		cin >> tmp;
		input.push_back(tmp);
	}
	sort(input.begin(), input.end());

	vector<int> v;
	dfs(0, 0, v);

	return 0;
}