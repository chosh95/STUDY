#include <iostream>
#include <vector>
using namespace std;
int res;
int x, y, d, g;
int map[101][101];
int dx[4] = { 0,-1,0,1 }; //오른쪽, 위, 왼쪽, 아래
int dy[4] = { 1,0,-1,0 };
vector<int> dir;

void dragon()
{
	int s = dir.size();
	for (int i = s - 1; i >= 0; i--) {
		int tmp_dir = (dir[i] + 1) % 4;
		x += dx[tmp_dir];
		y += dy[tmp_dir];
		map[x][y] = 1;
		dir.push_back(tmp_dir);
	}
}

void count()
{
	res = 0;
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			if (map[i][j] == 1 && map[i + 1][j] == 1 && map[i + 1][j + 1] == 1 && map[i][j + 1] == 1) {
				res++;
			}
		}
	}
}
int main()
{
	int N;
	cin >> N;
	while (N--) {
		cin >> y >> x >> d >> g;
		dir.clear();
		map[x][y] = 1;
		x += dx[d];
		y += dy[d];
		map[x][y] = 1;
		dir.push_back(d);
		for (int i = 0; i < g; i++) {
			dragon();
		}
	}
	count();
	cout << res;
}