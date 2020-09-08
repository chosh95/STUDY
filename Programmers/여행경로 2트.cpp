#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int visit[10001];
bool isPossible;

void dfs(string cur, vector<vector<string>> tickets, vector<string> &answer) {
    if (isPossible) return;
    if (answer.size() == tickets.size() + 1) {
        isPossible = true;
        return;
    }

    for (int i = 0; i < tickets.size(); i++) {
        if (visit[i] == 1) continue;
        if (tickets[i][0] == cur) {
            visit[i] = 1;
            answer.push_back(tickets[i][1]);
            dfs(tickets[i][1], tickets, answer);
            if (isPossible) return;
            answer.pop_back();
            visit[i] = 0;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    vector<string> answer;

    answer.push_back("ICN");
    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i][0] == "ICN") {     
            visit[i] = 1;
            answer.push_back(tickets[i][1]);
            dfs(tickets[i][1], tickets, answer);
            if (isPossible) break;
            answer.pop_back();
            visit[i] = 0;
        }
    }

    return answer;
}

int main()
{
    vector<string> res = solution({ {"ICN", "SFO"},{"ICN", "ATL"},{"SFO", "ATL"}, {"ATL", "ICN"},{"ATL", "SFO"} });
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
}