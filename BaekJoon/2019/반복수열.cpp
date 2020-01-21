#include <iostream>
#include <cmath>
#include <queue>
using namespace std;
int c[1000000];
int A, P, res;


void bfs()
{
	c[A] = 1;
	queue<int> q;
	q.push(A);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		int nx = 0;
		int num = x;
		while (num) {
			nx += (int)pow((num % 10), P);
			num /= 10;
		}
		if (c[nx] != 0) {
			cout << c[nx]-1;
			return;
		}
		c[nx] = c[x] + 1;
		q.push(nx);
	}
}

int main()
{
	cin >> A >> P;
	bfs();
}