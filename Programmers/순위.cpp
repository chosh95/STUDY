#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int visit[101][101];

int solution(int n, vector<vector<int>> results) {
	int answer = 0;
	for (int i = 0; i < results.size(); i++)
		visit[results[i][0]][results[i][1]] = 1;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				if (visit[j][i] == 1 && visit[i][k] == 1) visit[j][k] = 1;

	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (visit[i][j] == 1 || visit[j][i] == 1) cnt++;
		}
		if (cnt == n - 1) answer++;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << visit[i][j] << " ";
		}
		cout << endl;
	}
	return answer;
}

int main()
{
	cout << solution(5, { {4,3},{4,2},{3,2},{1,2},{2,5} });
}