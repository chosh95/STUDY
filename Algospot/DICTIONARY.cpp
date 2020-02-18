#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int C, N;
int p[27][27]; //p[i][j] : 알파벳 i가 j보다 먼저와야 한다.
bool check[27];
vector<string> str;
vector<char> res;

void makeGraph() {
	for (int j = 1; j < N; j++) {
		int i = j - 1;
		int len = min(str[i].length(), str[j].length());
		for (int k = 0; k < len; k++) {
			if (str[i][k] == str[j][k]) continue;
			int a = str[i][k] - 'a';
			int b = str[j][k] - 'a';
			p[a][b] = 1;
			break;
		}
	}
}

void dfs(int x) {
	check[x] = true;
	for (int nx = 0; nx < 26; nx++) {
		if (p[x][nx] == 1 && !check[nx])
			dfs(nx);
	}
	res.push_back(char(x + 'a'));
}

bool makeResult() {
	reverse(res.begin(), res.end());
	for (int i = 0; i < 26; i++) {
		for (int j = i+1; j < 26; j++) {
			if (p[(int)(res[j] - 'a')][(int)(res[i] - 'a')] == 1)
				return false;
		}
	}
	return true;
}
int main()
{
	cin >> C;
	while (C--) {
		cin >> N;

		str.resize(N);
		res.clear();
		memset(p, 0, sizeof(p));
		memset(check, false, sizeof(check));

		for (int i = 0; i < N; i++) cin >> str[i];
		makeGraph();
		for (int i = 0; i < 26; i++) {
			if (!check[i]) dfs(i);
		}

		if (!makeResult())
			cout << "INVALID HYPOTHESIS\n";
		else {
			for (int i = 0; i < 26; i++)
				cout << res[i];
			cout << "\n";
		}

	}
}
