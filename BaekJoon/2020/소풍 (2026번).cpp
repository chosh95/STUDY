#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int K, N, F;
int p[901][901];
int visit[901];
vector<int> res;

void dfs(int idx, int cnt, vector<int> cur) {
	if (!res.empty()) return;
	if (cnt == K) {
		res = cur;
		return;
	}

	for (int i = idx + 1; i <= N; i++) {
		if (visit[i] == 1) continue;
		bool isFriend = true;
		for (int j = 0; j < cur.size(); j++) {
			if (p[cur[j]][i] == 0) {
				isFriend = false;
				break;
			}
		}
		if (isFriend) {
			visit[i] = 1;
			cur.push_back(i);
			dfs(i, cnt + 1, cur);
			cur.pop_back();
			visit[i] = 0;
		}
	}
}

int main()
{
	cin >> K >> N >> F;
	for (int a, b, i = 0; i < F; i++) {
		cin >> a >> b;
		p[a][b] = p[b][a] = 1;
	}

	for (int i = 1; i <= N; i++) {
		if (!res.empty()) break;
		visit[i] = 1;
		dfs(i, 1, { i });
		visit[i] = 0;
	}
	
	if (res.empty()) cout << "-1";
	else {
		for (int x : res)
			cout << x << "\n";
	}
		
}