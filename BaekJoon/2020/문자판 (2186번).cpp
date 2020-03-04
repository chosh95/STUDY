#include <iostream>
#include <cstring>
using namespace std;
int N, M, K, wordLen, ans;
string word;
char map[102][102];
int visit[102][102][81];
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };

int dfs(int x, int y, int idx) {
	if (visit[x][y][idx] != -1) return visit[x][y][idx]; //방문한 지점의 visit 값 반환
	if (idx >= wordLen) return 1; //기저사례, 정답인 경우 가능하다는 의미의 1 반환. 

	visit[x][y][idx] = 0;
	for (int j = 1; j <= K; j++) {
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i] * j;
			int ny = y + dy[i] * j;
			if (nx < 1 || ny <1 || nx > N || ny > M) continue;
			if (map[nx][ny] != word[idx]) continue;
			visit[x][y][idx] += dfs(nx, ny, idx + 1);
		}
	}
	return visit[x][y][idx];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= M; j++) 
			cin >> map[i][j];
			
	cin >> word;
	wordLen = word.size();
	memset(visit, -1, sizeof(visit));

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			if (map[i][j] == word[0])
				ans += dfs(i, j, 1);

	cout << ans;
}