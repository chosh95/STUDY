#include <iostream>
using namespace std;
int N, m, M, T, R;

int main()
{
	cin >> N >> m >> M >> T >> R;
	int totalTime = 0, nTime = 0; // 총 소요시간, 운동시간
	int heart = m; // 현재 심장 박동
	while (nTime < N) {
		totalTime++;
		if (heart + T <= M) {
			heart += T;
			nTime++;
		}
		else {
			heart -= R;
			if (heart < m) heart = m;
		}
		if (heart + T > M && heart == m) { //예외조건
			cout << -1;
			return 0;
		}
	}
	cout << totalTime;
	return 0;
}