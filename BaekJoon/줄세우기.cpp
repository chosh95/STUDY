#include <iostream>
using namespace std;
int p[201];
int dp[201];
int N;

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> p[i];
		dp[i] = 1;
	}
	int res = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			if (p[i] > p[j] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
				if (res < dp[i]) res = dp[i];
			}
		}
	}
	//���� �� �����ϴ� ������ ������ ���ϰ� ��üũ�⿡�� ���ش�.
	cout << N - res;
}