#include <iostream>
#include <algorithm>
using namespace std;
int p[11][11];
int paper[6] = { 0,5,5,5,5,5 }; //각 색종이의 남은 개수
int res = 987654321;

// 색종이로 모두 채웠는지 확인
bool isZero() { 
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			if (p[i][j] == 1) return false;
		}
	}
	return true;
}

// (x,y)에서 size 크기만큼의 색종이를 채울 수 있는가 확인
bool isPossible(int x, int y, int size) { 
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (p[i][j] == 0) return false;
		}
	}
	return true;
}

// 다음으로 채워야 할 위치 확인
pair<int, int> checkPos() {
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			if (p[i][j] == 1) return { i,j };
		}
	}
}

void fill(int x, int y, int size, int color) {
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			p[i][j] = color;
		}
	}
}

void dfs(int cnt) {
	if (isZero()) { //종료조건
		res = min(res, cnt);
		return;
	}

	pair<int, int> pos = checkPos(); //색종이를 채워야 하는 다음 위치 검색
	for (int i = 5; i >= 1; i--) {
		if (paper[i] == 0) continue; // 색종이가 안 남아있으면 제외
		if (pos.first + i > 11 || pos.second + i > 11) continue; //경게 벗어나면 제외
		if (isPossible(pos.first, pos.second, i)) {
			paper[i]--; // i 크기의 색종이 개수 -1
			fill(pos.first, pos.second, i, 0); // 0으로 색종이를 덮는다.
			dfs(cnt + 1);
			fill(pos.first, pos.second, i, 1); // 1로 다시 복구
			paper[i]++; // i 크기의 색종이 개수 복구
		}
		continue;
	}
}

int main()
{
	for (int i = 1; i <= 10; i++)
		for (int j = 1; j <= 10; j++)
			cin >> p[i][j];

	dfs(0);

	if (res == 987654321) cout << "-1";
	else cout << res;
}