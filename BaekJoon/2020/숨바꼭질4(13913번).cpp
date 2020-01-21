#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N, K;
int dist[100001];
vector<int> v;

void bfs()
{
	queue<int> q;
	q.push(N);
	dist[N] = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (x == K) return;
		for (int nx : {x - 1, x + 1, 2 * x}) {
			if (nx < 0 || nx>100000) continue;
			if (dist[nx] > dist[x] + 1) {
				dist[nx] = dist[x] + 1;
				q.push(nx);
			}
		}
	}
}
void trace()
{
	queue<int> q;
	q.push(K);
	v.push_back(K);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (x == N) return;
		for (int nx : {x - 1, x + 1, x / 2}) {
			if (nx < 0 || nx>100000) continue;
			if (dist[nx] == dist[x] - 1) {
				v.push_back(nx);
				q.push(nx);
				break;
			}
		}
	}
}
int main()
{
	cin >> N >> K;
	for (int i = 0; i <= 100000; i++) dist[i] = 987654321;
	bfs();
	trace();
	cout << dist[K] << endl;
	for (int i = v.size() - 1; i >= 0; i--) 
		cout << v[i] << " ";
}