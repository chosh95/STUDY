#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 987654321;
int C, N, K, M, L;
int prerequisite[12]; // i번째 과목의 선수과목
int classes[10]; // i번째 학기에 개설되는 과목의 집합
int dp[10][1 << 12];

int bitCount(int n)
{
	int cnt = 0;
	for (int i = 0; i < 12; i++)
		if (n & (1 << i)) cnt++;
	return cnt;
}

//현재 semester학기에서, 들은 과목의 집합 taken일때
//앞으로 다녀야 하는 최소 학기의 수
int graduate(int semester, int taken)
{
	//K개 이상의 과목을 이미 들은 경우
	if (bitCount(taken) >= K) return 0;
	//M학기가 지난 경우
	if (semester == M) return INF;

	int& res = dp[semester][taken];
	if (res != -1) return res;
	res = INF;

	//이번학기에 들을 수 있는 과목과 아직 안들은 과목
	int canTake = (classes[semester] & ~taken);

	//아직 선수과목을 다 듣지 않은 과목은 제외
	for (int i = 0; i < N; i++) {
		if ((canTake & (1 << i)) && (taken & prerequisite[i]) != prerequisite[i])
			canTake &= ~(1 << i);
	}

	//모든 부분집합 중에서 L개 이하의 과목을 듣는경우 다음 학기로 넘어간다.
	for (int take = canTake; take > 0; take = ((take - 1) & canTake)) {
		if (bitCount(take) > L) continue;
		res = min(res, graduate(semester + 1, taken | take) + 1);
	}

	//이번학기를 건너뛰는 경우
	res = min(res, graduate(semester + 1, taken));
	return res;
}
int main()
{
	cin >> C;
	while (C--) {
		cin >> N >> K >> M >> L;
		memset(classes, 0, sizeof(classes));
		memset(prerequisite, 0, sizeof(prerequisite));
		memset(dp, -1, sizeof(dp));

		for (int R, i = 0; i < N; i++) {
			cin >> R;
			for (int num, j = 0; j < R; j++) {
				cin >> num;
				prerequisite[i] |= (1 << num);
			}
		}
		for (int C, i = 0; i < M; i++) {
			cin >> C;
			for (int num, j = 0; j < C; j++) {
				cin >> num;
				classes[i] |= (1 << num);
			}
		}
		int res = graduate(0, 0);
		if (res >= INF)
			cout << "IMPOSSIBLE\n";
		else
			cout << res << "\n";
	}
	return 0;
}