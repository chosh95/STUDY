#include <string>
#include <stack>
#include <iostream>
#include <vector>
using namespace std;
int pick(int cur, vector<vector<int>>& board) {
	for (int i = 0; i < board.size(); i++) {
		if (board[i][cur] != 0) {
			int res = board[i][cur];
			board[i][cur] = 0;
			return res;
		}
	}
	return 0;
}
int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	stack<int> st;

	for (int i = 0; i < moves.size(); i++) {
		int cur = moves[i];
		int item = pick(cur-1, board);
		if (item != 0) {
			if (!st.empty() && st.top() == item) {
				st.pop();
				answer += 2;
			}
			else
				st.push(item);
		}
	}

	return answer;
}

int main()
{
	cout << solution({ {0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1} }, { 1,5,3,5,1,2,1,4 });
}