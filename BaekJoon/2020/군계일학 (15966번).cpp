#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int dp[1000001];

int main()
{
	int answer = 0;

	cin >> N;
	for (int value, i = 1; i <= N; i++) {
		cin >> value;
		dp[value] = max(dp[value], dp[value - 1] + 1);
		answer = max(answer, dp[value]);
	}

	cout << answer;
}