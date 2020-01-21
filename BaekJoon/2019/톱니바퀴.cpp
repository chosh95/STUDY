#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
int p[5][9]; // i번째 바퀴의 j번째 톱니
int d[5], v[5]; //i번째 바퀴가 회전할 방향, i번째 바퀴의 방문 여부
int K, res;
void circular(int num)
{
	int tmp = p[num][8];
	for (int i = 8; i >= 2; i--) 
		p[num][i] = p[num][i - 1];
	p[num][1] = tmp;
}
void reverse(int num)
{
	int tmp = p[num][1];
	for (int i = 1; i <= 7; i++)
		p[num][i] = p[num][i + 1];
	p[num][8] = tmp;
}
void wheel(int num, int dir) //num번째 톱니를 dir로 회전
{
	memset(d, 0, sizeof(d));
	memset(v, 0, sizeof(v));
	queue<pair<int, int>> q; // 톱니, 방향
	q.push({ num,dir });
	d[num] = dir;
	v[num] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (x + 1 <= 4 && v[x+1]==0) {
			if (p[x][3] != p[x + 1][7]) {
				d[x + 1] = -1 * y;
				q.push({ x + 1,-1 * y });
				v[x + 1] = 1;
			}				
		}
		if (x - 1 >= 1 && v[x-1]==0) {
			if (p[x][7] != p[x - 1][3]) {
				d[x - 1] = -1 * y;
				q.push({ x - 1,-1 * y });
				v[x - 1] = 1;
			}
		}
	}
	for (int i = 1; i <= 4; i++) {
		if (d[i] == 1) 
			circular(i);
		if (d[i] == -1)
			reverse(i);
	}
}

void count(void)
{
	for (int i = 1,j = 1; i <= 4; i++, j*=2) {
		if (p[i][1] == 1) res += j;
	}
}
int main()
{
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 8; j++)
			scanf(" %1d", &p[i][j]);
	}
	cin >> K;
	int a, b;
	while (K--) {
		cin >> a >> b;
		wheel(a, b);
	}
	count();
	cout << res;
}