#include <string>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct node {
	int x;
	int y;
	int cost;
	node(int x, int y, int cost) :x(x), y(y), cost(cost) {}
};

struct cmp {
	bool operator()(node a, node b) {
		return a.cost > b.cost;
	}
};

int visit[101];
int parent[101];
int find(int n) {
	if (parent[n] == n) return n;
	return parent[n] = find(parent[n]);
}

int solution(int n, vector<vector<int>> costs) {
	int answer = 0;
	priority_queue<node, vector<node>, cmp> q;
	for (int i = 0; i < costs.size(); i++)
		q.push(node(costs[i][0], costs[i][1], costs[i][2]));

	for (int i = 0; i < n; i++) parent[i] = i;

	while (!q.empty()) {
		int x = find(q.top().x);
		int y = find(q.top().y);
		int cost = q.top().cost;
		q.pop();
		if (x == y) continue;
		if (x > y) parent[y] = x;
		else parent[x] = y;
		answer += cost;
	}
	return answer;
}

int main()
{
	cout << solution(4, { {0,1,1},{0,2,2},{1,2,5},{1,3,1},{2,3,8} });
}