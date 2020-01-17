#include <iostream>
#include <vector>
#include <cstring>
#include <bitset>
using namespace std;
int C;
char dp[1 << 25 + 1];
vector<int> moves;
inline int cell(int x, int y) { return 1 << (x * 5 + y); }


//블록을 놓을 수 있는 위치 계산
void precalc()
{
	//L칸 짜리 블록 계산
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			vector<int> cells;
			for (int dx = 0; dx < 2; dx++) 
				for (int dy = 0; dy < 2; dy++) 
					cells.push_back(cell(i + dx, j + dy));
			int square = cells[0] + cells[1] + cells[2] + cells[3];
			for (int k = 0; k < 4; k++) moves.push_back(square - cells[k]);
		}
	}
	//두칸 짜리 블록 계산
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			moves.push_back(cell(i, j) + cell(i, j + 1));
			moves.push_back(cell(j, i) + cell(j + 1, i));
		}
	}
}

char play(int board)
{
	char& res = dp[board];
	if (res != -1) return res;
	res = 0;
	for (int i = 0; i < moves.size(); i++) {
		if ((moves[i] & board) == 0) {
			if (!play(board | moves[i])) {
				res = 1;
				break;
			}
		}
	}
	return res;
}
int main()
{
	cin >> C;
	while (C--) {
		memset(dp, -1, sizeof(dp));
		int score = 0;
		precalc();

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				char tmp;
				cin >> tmp;
				if (tmp == '#') score += cell(i, j);
			}
		}
		if (play(score)) cout << "WINNING" << endl;
		else cout << "LOSING" << endl;
	}
	return 0;
}