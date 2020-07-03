#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, T, res;
vector<int> truth; // 진실을 아는 사람들
vector<int> party[51]; // i번 파티에 참여하는 사람 모임
int parent[51]; // i번 사람의 부모

int find(int u) {
	if (parent[u] == u) return u;
	return parent[u] = find(parent[u]);
}

void Union(int u, int v) {
	u = find(u);
	v = find(v);
	parent[v] = u;
}

int main()
{
	cin >> N >> M;
	cin >> T;
	for (int tmp, i = 1; i <= T; i++) {
		cin >> tmp;
		truth.push_back(tmp);
	}
		
	for (int cnt, i = 1; i <= M; i++) {
		cin >> cnt;
		for (int tmp, j = 1; j <= cnt; j++) {
			cin >> tmp;
			party[i].push_back(tmp);
		}
	}

	for (int i = 1; i <= N; i++) parent[i] = i; //parent 초기화

	for (int i = 1; i <= M; i++) { // 각 파티에 참여한 사람끼리 묶는다.
		int cur = party[i][0];
		for (int j = 1; j < party[i].size(); j++) 
			Union(cur, party[i][j]);
	}

	for (int i = 1; i <= M; i++) { // 각 파티에서 진실을 아는 사람과 묶여있다면 과장할 수 없다.
		bool isPossible = true;
		int cur = party[i][0];
		for (int j = 0; j < truth.size(); j++) {
			if (find(cur) == find(truth[j])) {
				isPossible = false;
				break;
			}
		}
		if (isPossible) res++;
	}
	cout << res;
}