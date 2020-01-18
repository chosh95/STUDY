#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
int N, K, res;
int dist[100001];
int cnt[100001];
bool chk[100001];

void bfs()
{
	queue<int> q;
	q.push(N);
	dist[N] = 0;
	cnt[N] = 1;
	chk[N] = true;

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (x + 1 <= 100000) {
			if (!chk[x + 1]) {
				dist[x + 1] = dist[x] + 1;
				chk[x + 1] = true;
				q.push(x + 1);
				cnt[x + 1] = cnt[x];
			}
			else if(dist[x+1]==dist[x]+1)
				cnt[x + 1] += cnt[x];
		}
		if (x * 2 <= 100000) {
			if (!chk[x * 2]) {
				dist[x * 2] = dist[x] + 1;
				chk[x * 2] = true;
				q.push(x * 2);
				cnt[x * 2] = cnt[x];
			}
			else if (dist[x * 2] == dist[x] + 1)
				cnt[x * 2] += cnt[x];
		}
		if (x - 1 >= 0) {
			if (!chk[x - 1]) {
				dist[x - 1] = dist[x] + 1;
				chk[x - 1] = true;
				q.push(x - 1);
				cnt[x - 1] = cnt[x];
			}
			else if (dist[x - 1] == dist[x] + 1)
				cnt[x - 1] += cnt[x];
		}
	}
}

int main()
{
	cin >> N >> K;
	memset(cnt, 0, sizeof(cnt));
	memset(chk, false, sizeof(chk));
	bfs();
	cout << dist[K] << endl << cnt[K];
}