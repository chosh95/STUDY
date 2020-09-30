#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int N;
int p[51][51];

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) {
		string str;
		cin >> str;
		for (int j = 1; j <= N; j++) {
			if (i == j) p[i][j] = 0;
			else if (str[j - 1] == 'Y') p[i][j] = 1;
			else p[i][j] = 987654321;
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (i == j || i == k || j == k) continue;
				if (p[j][k] > p[j][i] + p[i][k]) p[j][k] = p[j][i] + p[i][k];
			}
		}
	}

	int answer = 0;
	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		for (int j = 1; j <= N; j++) {
			if (i == j) continue;
			if (p[i][j]  <= 2) cnt++;
		}
		answer = max(answer, cnt);
	}

	cout << answer;
}