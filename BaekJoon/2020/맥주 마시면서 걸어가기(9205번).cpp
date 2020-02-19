#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
bool isTrue;
int C, N;
pair<int, int> con[103]; //편의점 좌표 배열 con[0] = 시작점, con[N+1] = 끝점
bool visit[103]; 
int distance(int idx1, int idx2)
{
	int max1 = max(con[idx1].first, con[idx2].first);
	int min1 = min(con[idx1].first, con[idx2].first);
	int max2 = max(con[idx1].second, con[idx2].second);
	int min2 = min(con[idx1].second, con[idx2].second);
	return abs(max1 - min1) + abs(max2 - min2);
}
void bfs() {
	queue<int> q;
	q.push(0);
	visit[0] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 1; i <= N+1; i++) {
			if (visit[i]==false && distance(x,i) <= 1000) {
				q.push(i);
				visit[i] = true;
				if (i == N + 1) {
					isTrue = true;
					return;
				}
			}
		}
	}

}


int main()
{
	cin >> C;
	while (C--) {
		//초기화
		isTrue = false;
		memset(visit, false, sizeof(visit));
		memset(con, 0, sizeof(con));

		//입력
		cin >> N;
		for (int i = 0; i <= N+1; i++) cin >> con[i].first >> con[i].second;

		//구현
		bfs();

		//결과
		if (isTrue)
			cout << "happy\n";
		else
			cout << "sad\n";

	}
}

