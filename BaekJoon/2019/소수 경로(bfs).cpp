#include <iostream>
#include <queue>
#include <memory.h>
#include <math.h>
using namespace std;
bool p[10000];
bool visit[10000];
int change(int n, int i, int j)
{
	int k = n;
	if (i == 1) {
		k -= (n / 1000) * 1000;
		k += j * 1000;
	}
	else if (i == 2) {
		k -= ((n / 100) % 10) * 100;
		k += j * 100;
	}
	else if (i == 3) {
		k -= ((n % 100) / 10) * 10;
		k += j * 10;
	}
	else if (i == 4) {
		k -= n % 10;
		k += j;
	}
	return k;
}
void bfs(int a, int b)
{
	memset(visit, false, sizeof(visit));
	queue<pair<int, int>> q;
	q.push({ a,0 });
	visit[a] = true;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (x == b) {
			cout << y << "\n";
			return;
		}
		for (int i = 1; i <= 4; i++) {
			for (int j = 0; j <= 9; j++) {
				int n = change(x, i, j);
				if (n < 1000 || visit[n] == true || p[n] == false) continue;
				else {
					visit[n] = true;
					q.push({ n,y + 1 });
				}
			}
		}
	}
	cout << "Impossible\n";
}

int main()
{
	memset(p, true, sizeof(p));
	for (int i = 2; i <= 5000; i++) {
		if (p[i] == false) continue;
		for (int j = i*2; j < 10000; j += i) {
			p[j] = false;
		}
	}
	int T, a, b;
	cin >> T;
	while (T--) {
		cin >> a >> b;
		bfs(a, b);
	}
}