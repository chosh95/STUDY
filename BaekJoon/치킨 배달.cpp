#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int N, M, res;
int map[52][52];
int used[16]; //치킨집 골랐는지 여부 저장
vector<pair<int, int>> ch; //chicken
vector<pair<int, int>> ho; //house

void dfs(int cur, int cnt)
{
	if (cur > ch.size()) return;
	if (cnt == M) {
		int mindist = 0;
		for (int i = 0; i < ho.size(); i++) {
			int dist = 9999999;
			int x = ho[i].first;
			int y = ho[i].second;
			for (int j = 0; j < ch.size(); j++) {
				if (used[j] == 1){
					int tmp = abs(x - ch[j].first) + abs(y - ch[j].second);
					dist = min(tmp, dist);
				}
			}
			mindist += dist;
		}
		res = min(mindist, res);
		return;
	}
	used[cur] = 1;
	dfs(cur + 1, cnt + 1);
	used[cur] = 0;

	dfs(cur + 1, cnt);
}
int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) ho.push_back({ i,j });
			else if (map[i][j] == 2) ch.push_back({ i,j });
		}
	}
	res = 9999999;
	dfs(0, 0);
	cout << res;
}