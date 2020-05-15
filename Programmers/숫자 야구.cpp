#include <string>
#include <iostream>
#include <vector>

using namespace std;

int cnt;
int visit[10];

bool isPossible(int ballIdx, string str, vector<vector<int>> baseball) {
	int strike = 0, ball = 0;
	int qStrike = baseball[ballIdx][1];
	int qBall = baseball[ballIdx][2];
	string qStr = to_string(baseball[ballIdx][0]);

	for (int i = 0; i < 3; i++) {
		if (str[i] == qStr[i]) 
			strike++;
		else if (qStr.find(str[i])!=string::npos) 
			ball++;
	}
	if (strike == qStrike && ball == qBall) return true;
	return false;
}

void dfs(int idx, string str, vector<vector<int>> baseball) {
	if (idx == 3) {
		for (int i = 0; i < baseball.size(); i++) {
			if (!isPossible(i, str, baseball)) {
				return;
			}
		}
		cnt++;
		return;
	}
	for (int i = 1; i <= 9; i++) {
		if (visit[i] == 1) continue;
		visit[i] = 1;
		str += to_string(i);
		dfs(idx + 1, str, baseball);
		visit[i] = 0;
		str.erase(idx);
	}
}

int solution(vector<vector<int>> baseball) {
	int answer = 0;
	
	dfs(0, "", baseball);
	answer = cnt;
	return answer;
}

int main()
{
	cout << solution({ {123,1,1},{356,1,0},{327,2,0},{489,0,1} });
}