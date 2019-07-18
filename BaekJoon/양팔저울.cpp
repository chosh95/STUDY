#include <iostream>
#include <cmath>
#include <memory.h>
using namespace std;
int p[31];
int dp[31][15001];
int N;

void weight(int idx, int sum)
{
	if (idx > N) return;
	if (dp[idx][sum] == 1 ) return;

	dp[idx][sum] = 1;
	
	weight(idx + 1, sum); //idx번째 추를 더하지 않는 경우
	weight(idx + 1, sum + p[idx]); //idx번째 추를 더한 경우
	weight(idx + 1, abs(sum - p[idx])); //idx번째 추를 뺀 경우
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> p[i];
	memset(dp, -1, sizeof(dp));

	weight(0, 0);

	int T;
	cin >> T;
	while (T--) {
		int w;
		cin >> w;
		if (w > 15000) {
			cout << "N ";
			continue;
		}
		else if (dp[N][w] == 1) cout << "Y ";
		else cout << "N ";
	}
}