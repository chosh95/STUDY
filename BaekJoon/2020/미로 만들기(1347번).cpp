#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

string str;
int N, dir;
int dx[4] = { 1,0,-1,0 }; //dir = 0,1,2,3 일때 이동방향
int dy[4] = { 0,-1,0,1 }; 
char p[110][110];

int main()
{
	cin >> N;
	cin >> str;
	for (int i = 0; i < 110; i++) 
		for (int j = 0; j < 110; j++) 
			p[i][j] = '#';

	int x = 55, y = 55; //홍준이의 현재 위치
	int minX = 55, maxX = 55, minY = 55, maxY = 55;
	p[x][y] = '.';
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'R') {
			dir++;
			if (dir > 3) dir = 0;
		}
		else if (str[i] == 'L') {
			dir--;
			if (dir < 0) dir = 3;
		}
		else {
			x += dx[dir];
			y += dy[dir];
			p[x][y] = '.';
		}
		minX = min(x, minX);
		minY = min(y, minY);
		maxX = max(x, maxX);
		maxY = max(y, maxY);
	}

	for (int i = minX; i <= maxX; i++) {
		for (int j = minY; j <= maxY; j++) {
			cout << p[i][j];
		}
		if(i!=maxX) cout << "\n";
	}
		
}