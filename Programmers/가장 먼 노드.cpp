#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v[20001];
int visit[20001];
int maxLen;

void dfs(int idx, int dist) {
	if (visit[idx] > dist) visit[idx] = dist;
	else if (visit[idx] != 0) return;
	visit[idx] = dist;

	for (int i = 0; i < v[idx].size(); i++) 
		dfs(v[idx][i], dist + 1);
}

int solution(int n, vector<vector<int>> edge) {
	int answer = 0;
	for (int i = 0; i < edge.size(); i++) {
		int a = edge[i][0];
		int b = edge[i][1];
		v[a].push_back(b);
		v[b].push_back(a);
	}
	maxLen = 0;
	dfs(1, 1);

	for (int i = 1; i <= n; i++)
		if (maxLen < visit[i])
			maxLen = visit[i];

	for (int i = 1; i <= n; i++)
		if (visit[i] == maxLen)
			answer++;
	return answer;
}

int main()
{
	cout << solution(6, { {3,6},{4,3},{3,2},{1,3},{1,2},{2,4},{5,2} });
	for (int i = 1; i <= 6; i++) {
		cout << visit[i] << " ";
	}
	cout << maxLen;
}
