#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int dx[4] = { -1,0,0,1 };
    int dy[4] = { 0,-1,1,0 };
    int visit[11][11];
    queue<pair<int, int>> q;

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++) 
                if (grid[i][j] == 2) {
                    q.push({ i,j });
                    visit[i][j] = 0;
                }

        int answer = 0;

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            answer = max(answer, visit[x][y]);

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if (visit[nx][ny] != 0) continue;
                if (grid[nx][ny] != 1) continue;
                q.push({ nx,ny });
                visit[nx][ny] = visit[x][y] + 1;
            }
         }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 1 && visit[i][j] == 0)
                    return -1;

        return answer;
    }
};

int main()
{
    vector<vector<int>> input = { {2,1,1},{1,1,0},{0,1,1} };
    //vector<vector<int>> input = { {0,1} };
    Solution s;
    cout << s.orangesRotting(input);
}