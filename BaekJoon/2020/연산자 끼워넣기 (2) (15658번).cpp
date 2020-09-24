#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
int p[12];
int op[5];
int maxRes = -987654321, minRes = 987654321;

void dfs(int cur, int idx) {
	if (idx == N) {
		maxRes = max(maxRes, cur);
		minRes = min(minRes, cur);
		return;
	}
	
	for (int i = 1; i <= 4; i++) {
		if (op[i] == 0) continue;
		int next = cur;
		op[i]--;

		if (i == 1)
			next += p[idx + 1];
		else if (i == 2)
			next -= p[idx + 1];
		else if (i == 3)
			next *= p[idx + 1];
		else if (i == 4)
			next /= p[idx + 1];

		dfs(next, idx + 1);

		op[i]++;
	}
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) 
		cin >> p[i];
	for (int i = 1; i <= 4; i++) 
		cin >> op[i];
	

	dfs(p[1], 1);

	cout << maxRes << endl << minRes;
}