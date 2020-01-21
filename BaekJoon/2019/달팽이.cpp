#include <iostream>
using namespace std;

int p[1000][1000];
int N, res, xpos, ypos, cur, dir, cnt;
int xres, yres;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };


int main()
{
	cin >> N >> res;
	xpos = ypos = N / 2 + 1;
	cur = 1;
	cnt = 1; // 각 방향으로 cnt개수만큼 값 증가
	dir = 0; // 처음엔 북쪽 방향
	p[xpos][ypos] = cur;
	
	while (cur <= N * N) {
		for (int j = 1; j <= 2; j++) {
			for (int k = 1; k <= cnt; k++) {
				if (cur == res) xres = xpos, yres = ypos;
				xpos += dx[dir];
				ypos += dy[dir];
				p[xpos][ypos] = ++cur;
			}
			dir = (dir + 1) % 4;
		}
		cnt++;
	}


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << p[i][j] << " ";
		}
		cout << "\n";
	}
	cout << xres << " " << yres;
}