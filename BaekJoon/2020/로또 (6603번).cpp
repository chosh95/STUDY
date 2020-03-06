#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int K, p[51];
vector<int> v;

void dfs(int idx, int cnt)
{
	if (cnt == 6) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
		return;
	}
	if (idx >= K) return;

	/*for (int i = idx + 1; i <= K; i++) {
		v.push_back(p[i]);
		dfs(i, cnt + 1);
		v.pop_back();
	}*/

	v.push_back(p[idx + 1]);
	dfs(idx + 1, cnt + 1);
	v.pop_back();
	dfs(idx + 1, cnt);
}

int main()
{
	while (true) {
		cin >> K;
		if (K == 0) return 0;

		memset(p, 0, sizeof(p));
		v.clear();

		for (int i = 1; i <= K; i++) cin >> p[i];

		dfs(0, 0);

		cout << "\n";
	}
}
