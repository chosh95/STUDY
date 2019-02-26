#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;

int N, p[17][17], dp[17][1 << 16];

int TSP(int cur, int visit)
{
	if (visit == (1 << N) - 1) { //다 방문한 경우
		if (p[cur][0]) return p[cur][0];
		else return 99999999;
	}
	int &ret = dp[cur][visit];
	if (ret != -1) return ret; //이미 계산한 경우
	ret = 99999999;
	for (int i = 0; i < N; i++) {
		if (visit & (1 << i)) continue; //i번째 지역을 방문한 경우
		if (p[cur][i] == 0) continue; //해당 지역이 비용이 0일 때
		ret = min(ret, TSP(i, visit | (1 << i)) + p[cur][i]); //현재에서 i로 가는 비용
	}
	return ret;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			cin >> p[i][j];

	memset(dp, -1, sizeof(dp));
		
	cout << TSP(0, 1);
	return 0;
}