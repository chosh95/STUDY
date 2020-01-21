#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;
int p[10][10];
vector<pair<int, int>> v;
bool tmp = false;
bool ispromising(int x, int y, int num)
{
	for (int i = 1; i <= 9; i++) {
		if (p[x][i] == num && i != y)
			return false;
		if (p[i][y] == num && i != x) 
			return false;
	}
	int nx, ny;
	if (x <= 3) nx = 1;
	else if (x <= 6) nx = 4;
	else nx = 7;
	if (y <= 3) ny = 1;
	else if (y <= 6) ny = 4;
	else ny = 7;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (p[nx + i][ny + j] == num && nx+i!=x && ny+j != y)
				return false;
		}
	}
	return true;
}
void back(int cur)
{
	if (tmp) return;
	if (cur == v.size()) {
		for (int i = 1; i <= 9; i++) {
			for (int j = 1; j <= 9; j++) {
				cout << p[i][j] << " ";
			}
			cout << "\n";
		}
		tmp = true;
	}
	int x = v[cur].first;
	int y = v[cur].second;
	for (int i = 1; i <= 9; i++) {
		p[x][y] = i;
		if (ispromising(x, y, i)) {
			back(cur + 1);
		}
		p[x][y] = 0;
	}
}

int main()
{
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> p[i][j];
			if (p[i][j] == 0) 
				v.push_back({ i,j });
		}
	}
	back(0);
}