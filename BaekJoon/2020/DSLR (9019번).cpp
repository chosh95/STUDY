#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int visit[10001];
char strList[4] = { 'D','S','L','R' };
int T, A, B;

int dslr(int idx, int x) {
	if (idx == 0) {
		return (x * 2) % 10000;
	}
	else if (idx == 1) {
		if (x == 0) return 9999;
		else return x - 1;
	}
	else if (idx == 2) {
		int thousand = x / 1000;
		x -= thousand * 1000;
		x *= 10;
		x += thousand;
		return x;
	}
	else if (idx == 3) {
		int digit = x % 10;
		x /= 10;
		x += digit * 1000;
		return x;
	}
}


void bfs()
{
	queue<pair<int, string>> q;
	q.push({ A,"" });
	visit[A] = 0;
	while (!q.empty()) {
		int x = q.front().first;
		string str = q.front().second;
		q.pop();

		if (x == B) {
			cout << str << "\n";
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nx = dslr(i, x);
			if (visit[nx] != 0) continue;
			q.push({ nx,str +strList[i] });
			visit[nx] = 1;
		}
	}
}
int main()
{
	cin >> T;
	while (T--) {
		memset(visit, 0, sizeof(visit));
		cin >> A >> B;
		bfs();
	}
}