#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int C;
int dp[19628]; //3^9
int bijection(const vector<string>& board)
{
	int res = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			res *= 3;
			if (board[i][j] == 'o') ++res;
			else if (board[i][j] == 'x') res += 2;
		}
	}
	return res;
}
bool isFinished(const vector<string>& board, char turn)
{
	//가로
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			if (board[i][j] != turn) break;
			if (j == 2) return true;
		}
	}
	//세로
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			if (board[j][i] != turn)break;
			if (j == 2)	return true;
		}
	}
	//↘
	for (int i = 0; i < 3; i++){
		if (board[i][i] != turn) break;
		if (i == 2) return true;
	}
	// ↙
	for (int i = 0; i < 3; i++){
		if (board[i][2 - i] != turn) break;
		if (i == 2) return true;
	}
	return false;
}
int canWin(vector<string>& board, char turn)
{
	if (isFinished(board, 'o'+'x'-turn)) return -1;
	int& res = dp[bijection(board)];
	if (res != -2) return res;
	int minValue = 2;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == '.') {
				board[i][j] = turn;
				minValue = min(minValue, canWin(board, 'o'+'x'-turn));
				board[i][j] = '.';
			}
		}
	}
	if (minValue == 2 || minValue == 0) return res = 0;
	return res = -minValue;
}


int main()
{
	cin >> C;
	while (C--) {
		int cnt = 0;
		vector<string> board;
		string tmp;

		for (int i = 0; i < 19628; i++) dp[i] = -2;

		for (int i = 0; i < 3; i++) {
			cin >> tmp;
			for (int j = 0; j < 3; j++) {
				if (tmp[j] != '.') cnt++;
			}
			board.push_back(tmp);
		}
		char start = 'x';
		if (cnt % 2 == 1) start = 'o';

		int res = canWin(board, start);
		if (res == 1) cout << start << endl;
		else if (res == 0) cout << "TIE" << endl;
		else cout << (char)('x' + 'o' - start) << endl;
	}
}