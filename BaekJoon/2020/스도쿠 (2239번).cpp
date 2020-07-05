#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int p[10][10];
bool res = false;

bool isPossible(int x, int y, int num) {
	for (int i = 0; i < 9; i++) 
		if (p[x][i] == num || p[i][y] == num) return false;

	int nx = (x / 3) * 3;
	int ny = (y / 3) * 3;
	for (int i = nx; i < nx + 3; i++) 
		for (int j = ny; j < ny + 3; j++) 
			if (p[i][j] == num) return false;
	
	return true;
}

void dfs(int num)
{
	if (res) return;
	if (num==81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << p[i][j];
			}
			cout << "\n";
		}
		res = true;
		return;
	}
	int x = num / 9;
	int y = num % 9;

	if (p[x][y] != 0) dfs(num + 1);
	else {
		for (int k = 1; k <= 9; k++) {
			if (isPossible(x, y, k)) {
				p[x][y] = k;
				dfs(num + 1);
				p[x][y] = 0;
			}
		}
	}
	
}

int main()
{
	string str;
	for (int i = 0; i < 9; i++) {
		cin >> str;
		for (int j = 0; j < 9; j++) {
			p[i][j] = str[j] - '0';
		}
	}

	dfs(0);
}