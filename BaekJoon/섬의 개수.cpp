<<<<<<< HEAD
#include <iostream>
#include <queue>
using namespace std;
int p[53][53];
bool v[53][53];
int dx[8] = { -1,0,1,1,1,0,-1,-1 };
int dy[8] = { 1,1,1,0,-1,-1,-1,0 };
int cnt;
int w, h;
void bfs(int a, int b)
{
	queue<pair<int, int> > q;
	q.push(make_pair(a, b));
	v[a][b] = true;
	while (true) {
		if (q.empty()) return;
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 1 && ny >= 1 && nx <= h && ny <= w) {
				if (p[nx][ny] == 1 && v[nx][ny] == false) {
					v[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int main()
{
	while (true)
	{
		cnt = 0;
		cin >> w >> h;
		if (w == 0 && h == 0) break;
		// visit 행렬 초기화
		for (int i = 1; i <= h; i++) 
			for (int j = 1; j <= w; j++) 
				v[i][j] = false;
		// 지도 정보 입력
		for (int i = 1; i <= h; i++) 
			for (int j = 1; j <= w; j++) 
				cin >> p[i][j];
		//	섬의 개수 파악			
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				if (p[i][j] == 1 && v[i][j] == false){
					bfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
=======
#include <iostream>
#include <queue>
using namespace std;
int p[53][53];
bool v[53][53];
int dx[8] = { -1,0,1,1,1,0,-1,-1 };
int dy[8] = { 1,1,1,0,-1,-1,-1,0 };
int cnt;
int w, h;
void bfs(int a, int b)
{
	queue<pair<int, int> > q;
	q.push(make_pair(a, b));
	v[a][b] = true;
	while (true) {
		if (q.empty()) return;
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 1 && ny >= 1 && nx <= h && ny <= w) {
				if (p[nx][ny] == 1 && v[nx][ny] == false) {
					v[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int main()
{
	while (true)
	{
		cnt = 0;
		cin >> w >> h;
		if (w == 0 && h == 0) break;
		// visit 행렬 초기화
		for (int i = 1; i <= h; i++) 
			for (int j = 1; j <= w; j++) 
				v[i][j] = false;
		// 지도 정보 입력
		for (int i = 1; i <= h; i++) 
			for (int j = 1; j <= w; j++) 
				cin >> p[i][j];
		//	섬의 개수 파악			
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				if (p[i][j] == 1 && v[i][j] == false){
					bfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
>>>>>>> 7f36c76f4ad21fe245254ea3f1b3c6e1e3bbbd90
}