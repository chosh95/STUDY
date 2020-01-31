#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int chu[31];
bool isPossible[31][40001];
int N, M;

void dfs(int cnt, int weight)
{
	if (cnt > N) return;
	if (isPossible[cnt][weight]) return;

	isPossible[cnt][weight] = true;

	dfs(cnt + 1, weight + chu[cnt]);
	dfs(cnt + 1, weight);
	dfs(cnt + 1, abs(weight - chu[cnt]));
}


int main()
{
	memset(isPossible, false, sizeof(isPossible));
	cin >> N;
	for (int a, i = 0; i < N; i++) {
		cin >> a;
		chu[i] = a;
	}
	dfs(0, 0);
	cin >> M;
	for (int a, i = 0; i < M; i++) {
		cin >> a;
		if (isPossible[N][a])
			cout << "Y ";
		else
			cout << "N ";
	}
}