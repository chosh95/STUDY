#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int N, K;
int res;
vector<string> words;
bool alpha[27];

int check() {
	int cnt = 0;
	for (int i = 0; i < words.size(); i++) {
		string cur = words[i];
		bool isTrue = true;
		for (int j = 0; j < cur.size(); j++) {
			if (alpha[cur[j] - 'a'] == false) {
				isTrue = false;
				break;
			}
		}
		if (isTrue)cnt++;
	}
	return cnt;
}

void dfs(int idx, int cnt) {
	if (cnt >= K) {
		res = max(res, check());
		return;
	}

	for (int i = idx; i < 26; i++) {
		if (alpha[i] == true) continue;
		alpha[i] = true;
		dfs(i + 1, cnt + 1);
		alpha[i] = false;
	}
}

int main()
{
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		string str; 
		cin >> str;
		words.push_back(str);
	}

	alpha['a' - 'a'] = true;
	alpha['n' - 'a'] = true;
	alpha['t' - 'a'] = true;
	alpha['i' - 'a'] = true;
	alpha['c' - 'a'] = true;

	K = K - 5;

	dfs(0, 0);
	if (K < 0) cout << 0;
	else cout << res;
}