#include <iostream>
#include <queue>
using namespace std;
int N, a, b, res = 999;
int visit[610]; //최소 이동횟수

void bfs()
{
	queue<pair<pair<int, int>, int>> q; //현재 점수, 현재 이동횟수, 2배 횟수
	visit[0] = 0;
	q.push({ { 0,0 },0 });
	while (!q.empty()) {
		int s = q.front().first.first; // score
		int t = q.front().first.second; // turn
		int d = q.front().second;
		q.pop();
		if (s >= N) {
			if (t < res) res = t;
			return;
		}
		int ns = s + a;
		if (visit[ns] < t + 1 && ns < N + a) {
			q.push({ {ns,t + 1},d });
			visit[ns] = t + 1;
		}
		ns = s + b;
		if (visit[ns] < t + 1 && ns < N + a) {
			q.push({ {ns,t + 1},d });
			visit[ns] = t + 1;
		}
		if (10 * (d + 1) <= t + 1) {
			ns = s * 2;
			if (ns >= N + a) continue;
			q.push({ {ns,t + 1},d + 1 });
			if (visit[ns] < t + 1) visit[ns] = t + 1;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> N >> a >> b;
	bfs();
	cout << res;
}