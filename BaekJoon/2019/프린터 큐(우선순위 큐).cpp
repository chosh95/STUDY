#include <iostream>
#include <queue>
using namespace std;
int main()
{
	int T;
	cin >> T;
	int N, M, tmp, count = 0;
	for (int i = 1; i <= T; i++) {
		count = 0;
		cin >> N >> M;
		queue<pair<int, int>> q;
		priority_queue <int> pq;
		for (int j = 0; j < N; j++) {
			cin >> tmp;
			q.push(make_pair(j, tmp));
			pq.push(tmp);
		}
		while (!q.empty()) {
			int idx = q.front().first;
			int weight = q.front().second;
			q.pop();
			if (weight == pq.top()) {
				count++;
				pq.pop();
				if (idx == M) {
					cout << count << endl;
					break;
				}
			}
			else q.push(make_pair(idx, weight));
		}
	}
}