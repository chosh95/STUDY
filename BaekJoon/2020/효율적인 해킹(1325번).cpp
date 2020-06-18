#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int N, M;
vector<int> v[10001];
int visit[10001];
int res, cnt;
vector<int> result;
void dfs(int idx)
{
	visit[idx] = 1;
	for (int i = 0; i < v[idx].size(); i++) {
		int cur = v[idx][i];
		if (visit[cur]) continue;
		dfs(cur);
		cnt++;
	}
}


int main()
{
	cin >> N >> M;
	for (int a, b, i = 0; i < M; i++) {
		cin >> a >> b;
		v[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		memset(visit, 0, sizeof(visit));
		cnt = 0;
		dfs(i);
		if (res < cnt) {
			result.clear();
			result.push_back(i);
			res = cnt;
		}
		else if (res == cnt) {
			result.push_back(i);
		}
	}

	for (int i = 0; i < result.size(); i++)
		cout << result[i] << " ";
}