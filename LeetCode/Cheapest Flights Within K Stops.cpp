#include <iostream>
#include <algorithm>
#include <queue>
#include <memory.h>
using namespace std;


class Solution {
public:
    vector<pair<int,int>> v[101]; //v[i] = (j,c) i에서 j까지 c 비용
    int visit[101];

    void bfs(int src, int dst, int k) {
        queue<pair<pair<int,int>,int>> q; // (node,cost), kCnt
        q.push({ {src,0},0 });
        visit[src] = 0;

        while (!q.empty()) {
            int cur = q.front().first.first;
            int cost = q.front().first.second;
            int cnt = q.front().second;
            q.pop();

            if (cnt == k + 1) continue;

            for (int i = 0; i < v[cur].size(); i++) {
                int nx = v[cur][i].first;
                int nextCost = v[cur][i].second;
                if (visit[nx] > cost + nextCost) {
                    visit[nx] = cost + nextCost;
                    q.push({ {nx,visit[nx]},cnt + 1 });
                }
            }
        }
    }


    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        for (int i = 0; i < flights.size(); i++) {
            int s = flights[i][0];
            int d = flights[i][1];
            int c = flights[i][2];
            v[s].push_back({ d,c });
        }

        for (int i = 0; i < n; i++) visit[i] = 987654321;

        bfs(src, dst, K);

        if (visit[dst] == 987654321) return -1;
        return visit[dst];
    }
};

int main()
{
    Solution s;
    vector<vector<int>> input = { {0,1,1},{0,2,5},{1,2,1},{2,3,1} };
    cout << s.findCheapestPrice(4, input, 0, 3, 1);
}