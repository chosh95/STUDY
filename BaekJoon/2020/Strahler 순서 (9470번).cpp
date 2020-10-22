#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <map>
using namespace std;
int T;
int K, M, P;
vector<int> v[1001];
int indeg[1001];
int order[1001]; // i번 강의 순서
int cnt[1001]; // i번 강으로 들어오는 가장 큰 순서 값의 개수

void bfs() {
	queue<int> q; // 강 번호
	for (int i = 1; i <= M; i++) 
		if (indeg[i] == 0) {
			q.push(i);
			order[i] = 1;
		}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int nx : v[cur]) {
			if (order[nx] < order[cur]) { // 새로운 가장 큰 순서가 나타나면 기록하고 cnt = 1
				order[nx] = order[cur];
				cnt[nx] = 1;
			}
			else if (order[nx] == order[cur]) { // 가장 큰 순서가 2개 이상인 경우 order + 1
				cnt[nx]++;
				if (cnt[nx] == 2) order[nx]++;
			}

			indeg[nx]--;
			if (indeg[nx] == 0)
				q.push(nx);
		}
		
	}
}

int main()
{
	cin >> T;
	while (T--) {
		memset(indeg, 0, sizeof(indeg));
		memset(order, 0, sizeof(order));
		for (int i = 0; i <= 1000; i++) v[i].clear();

		cin >> K >> M >> P;
		for (int a, b, i = 1; i <= P; i++) {
			cin >> a >> b;
			v[a].push_back(b);
			indeg[b]++;
		}

		bfs();

		cout << K << " " << order[M] << "\n";
	}
}