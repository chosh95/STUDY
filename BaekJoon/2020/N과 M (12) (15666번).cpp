#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
int N, M;
vector<int> inp;
vector<int> res;
map<vector<int>, int> m;
void dfs(int idx)
{
	if (res.size() == M) {
		if (m[res] != 0) return;
		m[res]++;
		for (int i = 0; i < M; i++)
			cout << res[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = idx; i < N; i++) {
		if (inp[idx] > inp[i]) continue;
		res.push_back(inp[i]);
		dfs(i);
		res.pop_back();
	}
}

int main()
{
	cin >> N >> M;
	for (int tmp, i = 0; i < N; i++) {
		cin >> tmp;
		inp.push_back(tmp);
	}
	sort(inp.begin(), inp.end());
	dfs(0);

}