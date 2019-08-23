#include <iostream>
#include <queue>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
map<int, int> m;
void bfs(int start) {
	queue<int> q;
	q.push(start);
	m[start] = 0;
	while (!q.empty()) {
		int cur = q.front();
		string now = to_string(cur);
		q.pop();
		if (cur == 123456789) break;
		int z = now.find('9');
		int x = z / 3;
		int y = z % 3;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx<3 && ny>=0 && ny <3){
				string next = now;
				swap(next[z], next[nx * 3 + ny]);
				int num = stoi(next);
				if (m.count(num)==0) {
					m[num] = m[cur] + 1;
					q.push(num);
				}
			}
		}
	}
}

int main()
{
	int start = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int tmp;
			cin >> tmp;
			if (tmp == 0) tmp = 9;
			start = start * 10 + tmp;
		}
	}
	bfs(start);	
	if (m.count(123456789) == 0) cout << "-1\n";
	else cout << m[123456789];
}