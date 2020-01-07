#include <iostream>
#include <memory.h>
#include <string>
using namespace std;
int p[31][31]; //p[i][j] = 1이면 벽, 0은 빈 공간
int C, H, W;
int res;
int blockType[4][3][2] = {
	{{0,0},{1,0},{0,1}},
	{{0,0},{0,1},{1,1}},
	{{0,0},{1,0},{1,1}},
	{{0,0},{1,0},{1,-1}}
};
void bfs()
{
	int x = -1, y = -1;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (p[i][j] == 0) {
				x = i, y = j;
				break;
			}
		}
		if (x != -1) break;
	}
	if (x == -1) {
		res++;
		return;
	}
	for (int i = 0; i < 4; i++) {
		bool check = true;
		for (int j = 0; j < 3; j++) {
			int nx = x + blockType[i][j][0];
			int ny = y + blockType[i][j][1];
			if (nx < 0 || ny < 0 || nx >= H || ny >= W) {
				check = false;
				continue;
			}
			if ((p[nx][ny] += 1) > 1) check = false;
		}
		if(check==true) bfs();
		for (int j = 0; j < 3; j++) {
			int nx = x + blockType[i][j][0];
			int ny = y + blockType[i][j][1];
			if (nx < 0 || ny < 0 || nx >= H || ny >= W) continue;
			p[nx][ny] -= 1;
		}
	}
}

int main()
{
	cin >> C;
	while (C--) {
		memset(p, 0, sizeof(p));
		cin >> H >> W;
		int spaceCnt = 0; //빈공간의 크기
		res = 0;
		for (int i = 0; i < H; i++) {
			string str;
			cin >> str;
			for (int j = 0; j < W; j++) {
				if (str[j] == '#') p[i][j] = 1;
				else {
					spaceCnt++;
					p[i][j] = 0;
				}
			}
		}
		if (spaceCnt % 3 != 0) {
			cout << "0\n";
			continue;
		}
		bfs();
		cout << res << "\n";
	}
}