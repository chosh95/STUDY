#include <iostream>
#include <vector>
using namespace std;
int p[10][10];
bool res;
vector<pair<int, int>> pos;

bool isTrue(int x, int y, int num) {
	for (int i = 1; i <= 9; i++) {
		if (p[x][i] == num && i!=y) return false;
		if (p[i][y] == num && i!=x) return false;
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
			if (p[nx + i][ny + j] == num && x != nx+i && y != ny +j) return false;
		}
	}

	return true;
}

void sudoku(int idx) {
	if (res) return;
	if (idx == pos.size()) { //9개 칸을 모두 채웠으면
		for (int i = 1; i <= 9; i++) {
			for (int j = 1; j <= 9; j++) {
				cout << p[i][j] << " ";
			}
			cout << "\n";
		}
		res = true;
		return;
	}

	int x = pos[idx].first;
	int y = pos[idx].second;

	for (int i = 1; i <= 9; i++) {
		p[x][y] = i;
		if(isTrue(x,y,i)) sudoku(idx+1);
		p[x][y] = 0;
	}
}

int main()
{
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> p[i][j];
			if (p[i][j] == 0) {
				pos.push_back({ i,j });
			}
		}
	}

	res = false;
	
	sudoku(0);
	
}