#include <string>
#include <iostream>
using namespace std;
int visit[12][12][12][12];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int solution(string dirs) {
	int answer = 0;
	int x = 5, y = 5;

	for (int i = 0; i < dirs.size(); i++) {
		char dir = dirs[i];
		int j = 0;
		if (dir == 'U') j = 0;
		else if (dir == 'D') j = 1;
		else if (dir == 'R') j = 2;
		else j = 3;

		int nx = x + dx[j];
		int ny = y + dy[j];
		if (nx < 0 || ny < 0 || nx>10 || ny>10) continue;
		if (visit[x][y][nx][ny] == 0) {
			visit[x][y][nx][ny] = 1;
			visit[nx][ny][x][y] = 1;
			answer++;
		}
		x = nx, y = ny;
	}
	return answer;
}

int main()
{
	cout << solution("ULURRDLLU");
}