#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int visit[10001];

void dfs(string cur, int cnt, vector<string>& answer, vector<vector<string>> tickets, vector<string> tmp){

	tmp.push_back(cur);

	if (cnt == tickets.size() && answer.empty()) {
		answer = tmp;
		return;
	}
	for (int i = 0; i < tickets.size(); i++) {
		if (tickets[i][0] == cur && visit[i] == 0) {
			visit[i] = 1;
			dfs(tickets[i][1], cnt + 1, answer, tickets, tmp);
			visit[i] = 0;
		}
	}
	tmp.pop_back();
}

vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer;
	sort(tickets.begin(), tickets.end());
	vector<string> tmp;
	dfs("ICN", 0, answer, tickets, tmp);

	return answer;
}

int main()
{
	vector<string> ans = solution({ {"ICN", "SFO"},{"ICN", "ATL"}, {"SFO", "ATL"},{"ATL", "ICN"},{"ATL", "SFO"} });
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
}