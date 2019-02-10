#include <iostream> 
#include <algorithm>
#include <queue>
using namespace std;
int p[103][103];
bool v[103][103];
int res[100003] = { 0 };
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
int c;

void bfs(int i, int j, int n, int m)
{
	queue<pair<int,int>> q;
	q.push(make_pair(i, j));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx > 0 && ny > 0 && nx <= m && ny <= n) {
				if (p[nx][ny] == 0 && v[nx][ny] == false) {
					res[c]++;
					v[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
			else continue;
		}
	}
}

int main()
{
	int N, M, K;
	cin >> M >> N >> K;
	for (int i = 1; i <= K; i++) {
		int x, y, nx, ny;
		cin >> x >> y >> nx >> ny;
		for (int j = x + 1; j <= nx; j++) {
			for (int k = y + 1; k <= ny; k++) {
				p[k][j] = 1;
			}
		}
	}
	for (int i = 1; i <= M; i++){
		for (int j = 1; j <= N; j++) {
			if (p[i][j] == 0 && v[i][j] == false) {
				res[++c]++;
				v[i][j] = true;
				bfs(i,j,N,M);
			}
		}
	}
	cout << c << endl;
	sort(res, res + c + 1 );
	for (int i = 1; i <= c; i++) cout << res[i] << " ";
}