#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
string S, T;

bool bfs() {
	queue<string> q;
	q.push(T);

	while (!q.empty()) {
		string cur = q.front();
		q.pop();
		
		if (cur == S) {
			return true;
		}
		if (cur.size() < S.size()) continue;

		if (cur[cur.size() - 1] == 'B') {
			cur.pop_back();
			reverse(cur.begin(), cur.end());
			q.push(cur);
		}
		else {
			cur.pop_back();
			q.push(cur);
		}
	}

	return false;
}

int main()
{
	cin >> S >> T;
	if (bfs())
		cout << 1;
	else
		cout << 0;
}