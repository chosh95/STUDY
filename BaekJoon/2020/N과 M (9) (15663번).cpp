#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;
int N, M;
vector<int> v;
map<string, int> m;
int visit[10];

void dfs(int idx, int cnt, string str) {
	if (cnt == M) {
		if (m[str] == 0) {
			m[str] = 1;
			cout << str << "\n";
		}
		return;
	}

	for (int i = 0; i < N; i++) {
		if (visit[i]) continue;

		string next = str;
		next += to_string(v[i]);
		if(cnt != M-1)
			next += " ";

		visit[i] = true;
		dfs(i, cnt + 1, next);
		visit[i] = false;
	}
}

int main()
{
	cin >> N >> M;
	for (int tmp, i = 0; i < N; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	dfs(0, 0, "");
}