#include <string>
#include <queue>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

bool visit[200001];
int first[200001]; // first[A] = B : A를 B보다 먼저 방문해야함
int second[200001]; // 반대
int indeg[200001]; 
vector<int> v[200001];

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    for (int i = 0; i < order.size(); i++) {
        first[order[i][0]] = order[i][1];
        second[order[i][1]] = order[i][0];
    }

    for (int i = 0; i < path.size(); i++) {
        int a = path[i][0];
        int b = path[i][1];
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    queue<int> q;
    if (second[0] != 0) return false;
    q.push(0);
    visit[0] = 1;
    set<int> wait;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        second[first[cur]] = 0;

        if (wait.find(first[cur]) != wait.end()) {
            wait.erase(first[cur]);
            q.push(first[cur]);
            visit[first[cur]] = 1;
        }

        for (int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i];
            if (visit[next] == 1) continue;
            if (second[next] != 0) {
                wait.insert(next);
                continue;
            }
            q.push(next);
            visit[next] = 1;
        }
    }

   
    for (int i = 0; i < n; i++) 
        if (visit[i] == 0) 
            return false;
    
    return true;
}

int main()
{
    cout << solution(9, { {0,1} ,{0,3},{0,7},{8,1},{3,6},{1,2},{4,7},{7,5 } }, {{4,1 }, { 8,7 }, { 6,5 } });
}