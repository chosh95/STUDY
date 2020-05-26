#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int,int>> v[51];
int visit[52][52];

void dfs(int idx, int sum, int N, int K) {

	for (int i = 0; i < v[idx].size(); i++) {
		int next = v[idx][i].first;
		int time = v[idx][i].second;
		if (sum + time > K) continue;
		if (visit[idx][next] !=0 && visit[idx][next] <= sum + time) continue;
		visit[next][0] = 1;
		visit[idx][next] = sum + time;
		dfs(next, sum + time, N, K);
	}
}

int solution(int N, vector<vector<int> > road, int K) {
	int answer = 0;
	for (int i = 0; i < road.size(); i++) {
		int a = road[i][0], b = road[i][1], time = road[i][2];
		v[a].push_back({ b,time });
		v[b].push_back({ a,time });
	}
	dfs(1,0,N,K);
	visit[1][0] = 1;
	for (int i = 1; i <= N; i++)
		if (visit[i][0] == 1)
			answer++;
	return answer;
}

int main()
{
	cout << solution(5, { {1,2,1},{2,3,3},{5,2,2},{1,4,2},{5,3,1},{5,4,2} }, 3) << endl;
	cout << solution(6, { {1,2,1},{1,3,2},{2,3,2},{3,4,3},{3,5,2},{3,5,3},{5,6,1} }, 4);
}