#include <iostream>
#include <vector>
using namespace std;
int N, M;
int visit[10];

void dfs(int idx, int cnt, vector<int> &v) {

	if (cnt == M) {
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (i == idx) continue;
		if (visit[i] == 1) continue;
		visit[i] = 1;
		v.push_back(i);
		dfs(i, cnt + 1, v);
		v.pop_back();
		visit[i] = 0;
	}
}

int main()
{
	cin >> N >> M;
	vector<int> v;
	dfs(0, 0, v);

	return 0;
}