#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<char> inp;
int visit[10];
string minRes = "9999999999", maxRes = "0";
void dfs(int idx, vector<int> cur) {
	if (idx == N) {
		string str;
		for (int x : cur)
			str += to_string(x);
		minRes = min(minRes, str);
		maxRes = max(maxRes, str);
		return;
	}

	if (inp[idx] == '<') {
		for (int i = cur.back() + 1; i <= 9; i++) {
			if (visit[i] == 1) continue;
			visit[i] = 1;
			cur.push_back(i);
			dfs(idx + 1, cur);
			cur.pop_back();
			visit[i] = 0;
		}
	}
	else if(inp[idx]=='>'){
		for (int i = cur.back() - 1; i >= 0; i--) {
			if (visit[i] == 1) continue;
			visit[i] = 1;
			cur.push_back(i);
			dfs(idx + 1, cur);
			cur.pop_back();
			visit[i] = 0;
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		char a; cin >> a;
		inp.push_back(a);
	}

	for (int i = 0; i < 10; i++) {
		visit[i] = 1;
		dfs(0, {i});
		visit[i] = 0;
	}
	cout << maxRes << "\n" << minRes;
}