#include <iostream>
#include <queue>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
map<int, int> visit;
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,1,-1,0 };

void bfs(int start) {
	queue<int> q;
	q.push(start);
	visit[start] = 0;
	while (!q.empty()) {
		int cur = q.front();
		string now = to_string(cur);
		q.pop();
		if (cur == 123456789) return;
		int z = now.find('9');
		int x = z / 3;
		int y = z % 3;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx>=3 || ny>=3) continue;
			string next = now;
			swap(next[z], next[nx * 3 + ny]);
			int num = stoi(next);
			if (visit.count(num) == 0) {
				visit[num] = visit[cur] + 1;
				q.push(num);
			}
		}

	}
}
int main()
{
	int start = 0;
	for (int tmp, i = 0; i < 9; i++) {
		cin >> tmp;
		if (tmp == 0) tmp = 9;
		start = start * 10 + tmp;
	}
	bfs(start);

	if (visit.count(123456789) != 0)
		cout << visit[123456789];
	else
		cout << -1;

}