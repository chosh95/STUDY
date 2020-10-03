#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
map<int, pair<int, int>> m;

int row[6];
int col[6];
int p[6][6];

bool isBingo() {
	for (int i = 1; i <= 5; i++)
		if (p[i][i] != -1) return false;
	return true;
}

bool isBingo2() {
	for(int i=1;i<=5;i++)
		if (p[i][6 - i] != -1) return false;
	return true;
}

int main()
{
	for (int i = 1; i <= 5; i++) 
		for (int tmp, j = 1; j <= 5; j++) {
			cin >> p[i][j];
			m[p[i][j]] = { i,j };
		}

	int bingo = 0, answer = 0;
	bool Bingo1 = false, Bingo2 = false;
	for (int i = 1; i <= 5; i++)
		for (int tmp, j = 1; j <= 5; j++) {
			cin >> tmp;
			if (answer != 0) continue;
			int r = m[tmp].first;
			int c = m[tmp].second;
			p[r][c] = -1;
			if (++row[r] == 5) {
				bingo++;
				if (bingo == 3 && answer==0) answer = (i-1) * 5 + j;
			}
			if (++col[c] == 5) {
				bingo++;
				if (bingo == 3 && answer==0) answer = (i - 1) * 5 + j;
			}
			if (!Bingo1 && isBingo()) {
				Bingo1 = true;
				bingo++;
				if (bingo == 3 && answer == 0) answer = (i - 1) * 5 + j;
			}
			if (!Bingo2 && isBingo2()) {
				Bingo2 = true;
				bingo++;
				if (bingo == 3 && answer == 0) answer = (i - 1) * 5 + j;
			}
		}
	cout << answer;
}