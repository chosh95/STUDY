#include <iostream>
#include <memory.h>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int T, N, K, D;
vector<int> v[1001]; // 그래프 벡터
int time[1001]; // 각 노드 소요 시간
int indeg[1001]; // node 이전에 방문해야 하는 수 저장
int res[1001]; // node까지 소요되는 시간 결과값 저장

void bfs() {
	queue<pair<int,int>> q; // {Node, 소요시간}

	for (int i = 1; i <= N; i++)
		if (indeg[i] == 0) { // 방문 가능한 지점 q에 push
			res[i] = time[i];
			q.push({ i,time[i] });
		}
			
	
	while (!q.empty()) {
		int cur = q.front().first; // 현재 노드
		int cost = q.front().second; // 현재까지 소요 시간
		q.pop();

		if (cur == D) { // 목표 노드에 방문했으면
			cout << res[cur] << "\n"; // 결과값 출력 후 종료
			return;
		}

		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i]; // 다음 지점
			res[next] = max(res[next], cost + time[next]); // 다음 지점까지 소요되는 시간값 최신화
			indeg[next]--; // 다음 지점까지 방문해야 하는 노드 수 감소
			if (indeg[next] == 0) {
				q.push({ next, res[next] }); // 다음 지점 큐에 삽입
			}
		}
	}
}

int main()
{
	cin >> T;
	while (T--) {
		// 배열, 벡터 초기화
		memset(time, 0, sizeof(time));
		memset(indeg, 0, sizeof(indeg));
		memset(res, 0, sizeof(res));
		for (int i = 0; i <= 1000; i++)
			v[i].clear();

		//입력
		cin >> N >> K;
		for (int i = 1; i <= N; i++)
			cin >> time[i];
		for (int a, b, i = 0; i < K; i++) {
			cin >> a >> b;
			v[a].push_back(b);
			indeg[b]++;
		}
		cin >> D;

		//위상정렬
		bfs();
	}
}