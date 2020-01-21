#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int p[1001][1001];
int d[6] = { 0,0,0,0,0,0 }; //0:¹Ù´Ú 1:µ¿ 2:¼­ 3:ºÏ 4:³² 5:À­¸é
int N, M, x, y, K;
void dice(int dir)
{
	if (dir == 1) {
		int tmp = d[0];
		d[0] = d[1];
		d[1] = d[5];
		d[5] = d[2];
		d[2] = tmp;
	}
	else if (dir == 2) {
		int tmp = d[0];
		d[0] = d[2];
		d[2] = d[5];
		d[5] = d[1];
		d[1] = tmp;
	}
	else if (dir == 3) {
		int tmp = d[0];
		d[0] = d[3];
		d[3] = d[5];
		d[5] = d[4];
		d[4] = tmp;
	}
	else if (dir == 4) {
		int tmp = d[0];
		d[0] = d[4];
		d[4] = d[5];
		d[5] = d[3];
		d[3] = tmp;
	}
}

int main()
{
	scanf("%d%d%d%d%d", &N, &M, &x, &y, &K);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &p[i][j]);
		}
	}
	int tmp;
	for (int i = 0; i < K; i++) {
		scanf("%d", &tmp);
		if (tmp == 1) { //µ¿
			if (y + 1 >= M) continue;
			y += 1;
		}else if (tmp == 2) { //¼­
			if (y - 1 < 0) continue;
			y -= 1;
		}else if (tmp == 3) { //ºÏ
			if (x - 1 < 0) continue;
			x -= 1;
		}
		else if (tmp == 4) { //³²
			if (x + 1 >= N) continue;
			x += 1;
		}

		if (p[x][y] == 0) {
			p[x][y] = d[tmp];
		}
		else if(p[x][y] > 0){
			d[tmp] = p[x][y];
			p[x][y] = 0;
		}
		dice(tmp);
		cout << d[5] <<"\n"; //À­¸é Ãâ·Â
	}
}