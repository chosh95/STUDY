#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, res;
vector<int> v[31]; // v[i] : i번째 사람의 치킨 선호도 벡터

// 치킨 인덱스, 현재까지 고른 치킨들
void dfs(int idx, vector<int> cur) {
	if (cur.size() == 3) {
		int cost = 0;
		for (int i = 1; i <= N; i++) {
			cost += max(max(v[i][cur[0]], v[i][cur[1]]), v[i][cur[2]]);
		}
		res = max(cost, res);
		return;
	}

	for (int i = idx + 1; i < M; i++) {
		cur.push_back(i);
		dfs(i, cur);
		cur.pop_back();
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int tmp, j = 0; j < M; j++) {
			cin >> tmp;
			v[i].push_back(tmp);
		}
	}

	dfs(-1, {});

	cout << res;
}