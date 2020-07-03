#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
vector<int> v;
vector<int> res;
void dfs(int idx) {
	if (res.size() == M) {
		for (int i = 0; i < res.size(); i++) 
			cout << res[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = idx; i < N; i++) {
		res.push_back(v[i]);
		dfs(i);
		res.pop_back();
	}
}

int main()
{
	cin >> N >> M;
	for (int tmp, i = 1; i <= N; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	dfs(0);
}