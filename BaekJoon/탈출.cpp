#include <iostream>
#include <queue>
using namespace std;
int dist[100000];

void bsf(int n, int t, int g)
{
	queue<int> q;
	q.push(n);
	dist[n] = 0;

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		if (x == g) break;
		if ((dist[x+1]==-1 || dist[x + 1] > dist[x]) && x+1<=99999 && dist[x]+1<=t) {
			dist[x + 1] = dist[x] + 1;
			q.push(x + 1);
		}
		if (2 * x <= 99999) {
			int nx = x*2;
			if (nx >= 10000) nx -= 10000;
			else if (nx >= 1000) nx -= 1000;
			else if (nx >= 100) nx -= 100;
			else if (nx >= 10) nx -= 10;
			else nx--;
			if ((dist[nx]==-1 || dist[x] < dist[nx]) && dist[x]+1<=t) {
				dist[nx] = dist[x] + 1;
				q.push(nx);
			}
		}
	}
}
int main()
{
	int  N, T, G;
	cin >> N >> T >> G;
	for (int i = 0; i <= 99999; i++) dist[i] = -1;

	bsf(N, T, G);
	if (dist[G] != -1) cout << dist[G];
	else cout << "ANG";
}