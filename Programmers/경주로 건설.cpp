#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
int visit[26][26];
int dx[4] = { -1,0,0,1 }; // ºÏ, ¼­, µ¿, ³²
int dy[4] = { 0,-1,1,0 };

struct Node {
    int x;
    int y;
    int dir;
    int cost;
    Node(int x, int y, int dir, int cost) {
        this->x = x;
        this->y = y;
        this->dir = dir;
        this->cost = cost;
    }
};

int solution(vector<vector<int>> board) {
    int answer = 987654321;
    queue<Node> q;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            visit[i][j] = 987654321;
        }
    }
    q.push(Node(0, 0, -1, 0));
    visit[0][0] = 0;

    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int dir = q.front().dir;
        int cost = q.front().cost;
        q.pop();
        //cout << x << " " << y << " " << dir << " " << cost << endl;
        if (x == board.size()-1 && y == board.size()-1) {
            answer = min(answer, cost);
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nextCost = 100;
            if (nx<0 || ny<0 || nx>=board.size() || ny>=board.size()) continue;
            if (board[nx][ny] == 1) continue;
            if (dir != -1 && dir != i) nextCost += 500;
            if (visit[nx][ny] < cost + nextCost) continue;
            visit[nx][ny] = cost + nextCost;
            q.push(Node(nx, ny, i, cost + nextCost));
        }
    }

    return answer;
}

int main()
{
    cout << solution({ {0,0,1,0},{0,0,0,0},{0,1,0,1},{1,0,0,0 } });
}