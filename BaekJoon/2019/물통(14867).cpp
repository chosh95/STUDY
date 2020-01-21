#include <iostream>
#include <queue>
#include <map>
using namespace std;
int A, B, C, D;
map<pair<int, int>, int> visit; //a, b, count

int bfs()
{
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	visit[{0, 0}] = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		int dist = visit[{x, y}];
		if (x == C && y == D) return dist;

		//Fill
		if (visit[{A, y}] == 0) {
			q.push({ A,y });
			visit[{A, y}] = dist + 1;
		}
		if (visit[{x, B}] == 0) {
			q.push({ x,B });
			visit[{x, B}] = dist + 1;
		}
		
		//Empty
		if (visit[{0, y}] == 0) {
			q.push({ 0,y });
			visit[{0, y}] = dist + 1;
		}
		if (visit[{x, 0}] == 0) {
			q.push({ x,0 });
			visit[{x, 0}] = dist + 1;
		}

		//A->B
		if (x + y <= B && visit[{0, x + y}] == 0) {
			q.push({ 0,x + y });
			visit[{0, x + y}] = dist + 1;
		}
		else if (x + y > B && visit[{x + y - B, B}] == 0) {
			q.push({ x + y - B,B });
			visit[{x + y - B, B}] = dist + 1;
		}
		
		//B->A
		if (x + y <= A && visit[{x + y, 0}] == 0) {
			q.push({ x + y,0 });
			visit[{x + y, 0}] = dist + 1;
		}
		else if (x + y > A && visit[{A, x + y - A}] == 0) {
			q.push({ A,x + y - A });
			visit[{A, x + y - A}] = dist + 1;
		}
	}
	return -1;
}
int main()
{
	cin >> A >> B >> C >> D;
	cout << bfs();
}