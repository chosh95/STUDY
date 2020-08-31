#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string origin;
int res;
int p[27];

void dfs(int idx, string cur) {

	if (idx == origin.size()) {
		res++;
		return;
	}

	for (int i = 0; i < 26; i++) {
		if (p[i] == 0) continue;
		if (cur != "" && cur[cur.size() - 1] == (char)('a' + i)) continue;
		p[i]--;
		dfs(idx + 1, cur + (char)('a' + i));
		p[i]++;
	}
}

int main()
{
	cin >> origin;
	for (int i = 0; i < origin.size(); i++)
		p[origin[i] - 'a']++;
	
	dfs(0, "");

	cout << res;
}