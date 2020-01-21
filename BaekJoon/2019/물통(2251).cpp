#include <iostream>
#include <queue>
using namespace std;
int A, B, C;
int res[201];
bool visit[201][201][201];
void bfs()
{
	queue < pair<pair<int, int>,int>> q;	
	q.push({ {0,0},C });
	res[C] = 1;
	while (!q.empty()) {
		int a = q.front().first.first;
		int b = q.front().first.second;
		int c = q.front().second;
		q.pop();

		if (visit[a][b][c]) continue;
		visit[a][b][c] = true;
		if (a == 0) res[c] = 1;

		if (a + b <= B) q.push({ {0,a + b },c });
		else q.push({ {a + b - B,B},c });

		if (a + c > C) q.push(make_pair(make_pair(a + b - C, b), C));
		else q.push(make_pair(make_pair(0, b), a + c));

		if (b + a > A) q.push(make_pair(make_pair(A, b + a - A), c));
		else q.push(make_pair(make_pair(b + a, 0), c));

		if (b + c > C) q.push(make_pair(make_pair(a, b + c - C), C));
		else q.push(make_pair(make_pair(a, 0), b + c));

		if (c + a > A)	q.push(make_pair(make_pair(A, b), c + a - A));
		else q.push(make_pair(make_pair(c + a, b), 0));

		if (c + b > B) q.push(make_pair(make_pair(a, B), c + b - B));
		else q.push(make_pair(make_pair(a, c + b), 0));
	}
}

int main()
{
	cin >> A >> B >> C;
	bfs();
	for (int i = 0; i <= C; i++) {
		if (res[i] == 1) cout << i << " ";
	}
}