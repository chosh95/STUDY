#include <iostream>
#include <algorithm>
using namespace std;
int p[501][501];
int N, M, B;
int minH=987654321, maxH;

int mine(int height)
{
	int time = 0;
	int inven = B;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (p[i][j] < height) {
				inven -= (height - p[i][j]);
				time += (height - p[i][j]);
			}
			else if (p[i][j] > height) {
				inven += (p[i][j] - height);
				time += (p[i][j] - height)*2;
			}
		}
	}

	if (inven < 0) return -1;
	return time;
}

int main()
{
	cin >> N >> M >> B;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> p[i][j];
			minH = min(minH, p[i][j]);
			maxH = max(maxH, p[i][j]);
		}
	}

	int res = 987654321, cur = 0, resH = 0;
	for (int i = minH; i <= maxH; i++) {
		cur = mine(i);

		if (cur == -1) continue;
		if (res >= cur) {
			res = cur;
			resH = i;
		}
	}
	cout << res << " " << resH;
}