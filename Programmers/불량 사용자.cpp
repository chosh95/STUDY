#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<int> v[10];
int visit[10];
set<string> s;

void dfs(int idx, int N) {
	if (idx == N) {
		string tmp = "";
		for (int i = 0; i < 10; i++)
			if (visit[i]==1) tmp += to_string(i);
		s.insert(tmp);
		return;
	}

	for (int j = 0; j < v[idx].size(); j++) {
		int cur = v[idx][j];
		if (visit[cur] == 1) continue;
		visit[cur] = 1;
		dfs(idx + 1, N);
		visit[cur] = 0;
	}
}

int solution(vector<string> user_id, vector<string> banned_id) {
	int answer = 0;
	for (int i = 0; i < banned_id.size(); i++) {
		for (int j = 0; j < user_id.size(); j++) {
			if (banned_id[i].length() != user_id[j].length()) continue;
			bool isTrue = true;
			for (int k = 0; k < user_id[j].size(); k++) {
				if (banned_id[i][k] == '*') continue;
				if (banned_id[i][k] == user_id[j][k]) continue;
				isTrue = false;
				break;
			}
			if (isTrue) v[i].push_back(j);
		}
	}

	dfs(0, banned_id.size());

	answer = s.size();

	return answer;
}

int main()
{
	cout << solution({"frodo", "fradi", "crodo", "abc123", "frodoc"},{ "*rodo", "*rodo", "******" });
}