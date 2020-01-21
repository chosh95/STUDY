#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int N, K, res = -1;
bool visit[2][500001] = { false }; //È¦¼ö¹øÂ°, Â¦¼ö¹øÂ°

void bfs()
{
	queue<int> q;
	q.push(N);
	int time = 1;
	visit[0][N] = true;
	while (!q.empty()) {
		K += time;
		if (K > 500000) return;
		if (visit[time % 2][K]) {
			res = time;
			return;
		}
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int x = q.front();
			q.pop();
			for (int nx : {x - 1, x + 1, 2 * x}) {
				if (nx == K) {
					res = time;
					return;
				}
				if (nx < 0 || nx>500000) continue;
				if (visit[time % 2][nx]) continue;
				visit[time % 2][nx] = true;
				q.push(nx);
			}
		}
		time++;
	}
}


int main()
{
	cin >> N >> K;
	if (N == K) {
		cout << "0";
		return 0;
	}
	memset(visit, false, sizeof(visit));
	bfs();
	cout << res;
}