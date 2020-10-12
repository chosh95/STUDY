#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {

        vector<pair<int, int>> graph[101];
        for (int i = 0; i < times.size(); i++)
            graph[times[i][0]].push_back({ times[i][1],times[i][2] });



        vector<int> visit(N + 1, 1e9);
        visit[K] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({ 0, K });

        int cur = 0, cost = 0, nx = 0, nextCost = 0;
        while (!q.empty()) {
            cur = q.top().second;
            cost = q.top().first;
            q.pop();

            for (int i = 0; i < graph[cur].size(); i++) {
                nx = graph[cur][i].first;
                nextCost = visit[cur] + graph[cur][i].second;
                if (visit[nx] > nextCost) {
                    q.push({ nextCost,nx });
                    visit[nx] = nextCost;
                }
            }
        }

        int answer = *max_element(visit.begin() + 1, visit.end());
        if (answer == 1e9) return -1;
        return answer;
    }
};

int main()
{
    Solution S;
    vector<vector<int>> inp = { {1,2,1},{2,3,2},{1,3,4} };
    cout << S.networkDelayTime(inp, 3,1);
}