#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
long long p[1000001]; // i번째 감소하는 수
int N, idx = 10;
queue<long long> q;

void bfs()
{
	while (!q.empty()) {
		long long cur = q.front();
		q.pop();
		int last = cur % 10;
		for (int i = 0; i < last; i++) {
			q.push((long long)cur * 10 + i);
			p[idx++] = (long long)cur * 10 + i;
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 1; i < 10; i++) {
		q.push(i);
		p[i] = i;
	}

	bfs();
	
	if (p[N] == 0 && N != 0)
		cout << -1;
	else
		cout << p[N];

}