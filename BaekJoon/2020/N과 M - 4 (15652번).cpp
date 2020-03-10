#include <iostream>
#include <vector>
using namespace std;
int N, M;
int visit[10];

void dfs(int idx, int cnt, vector<int>& v) {

	if (cnt == M) {
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = idx; i <= N; i++) {
		v.push_back(i);
		dfs(i, cnt + 1, v);
		v.pop_back();
	}
}

int main()
{
	cin >> N >> M;
	vector<int> v;
	dfs(1, 0, v);

	return 0;
}