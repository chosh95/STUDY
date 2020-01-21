#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int N, K;
int p[100001];
	
void bfs(int n)
{
	queue<int> q;
	q.push(N);
	while (!q.empty()) {
		int x = q.front();
		if (x == K) return;
		q.pop();
		if (x - 1 >= 0 && p[x - 1] > p[x] + 1) {
			p[x - 1] = p[x] + 1;
			q.push(x - 1);
		}
		if (x + 1 <= 100000 && p[x+1] > p[x] + 1) {
			q.push(x + 1);
			p[x + 1] = p[x] + 1;
		}
		if (x * 2 <= 100000 && p[x*2] > p[x] + 1) {
			q.push(x * 2);
			p[2 * x] = p[x] + 1;
		}
	}
}
int main()
{
	cin >> N >> K;
	for (int i = 0; i <= 100000; i++) p[i] = 987654321;
	p[N] = 0;
	bfs(N);
	cout << p[K] << endl;
}