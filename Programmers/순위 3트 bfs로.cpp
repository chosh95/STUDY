#include <string>
#include <queue>
#include <vector>
#include <memory.h>
#include <iostream>
using namespace std;

int p[101][101];
int visit[101];

//wl : win�̸� 1����, lose�� -1 ����
int bfs(int idx, int wl, int n) {
    memset(visit, 0, sizeof(visit));
    queue<int> q;
    q.push(idx);
    visit[idx] = 1;

    int cnt = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (int i = 1; i <= n; i++) {
            if (i == idx) continue; // �ڽ� ����
            if (visit[i] == 1) continue; // �湮�Ѱ�� ����
            if (p[x][i] != wl) continue; // 0�̰ų� wl�� �ٸ��� ����
            q.push(i);
            visit[i] = 1;
            cnt++; // win or lose ��� �� �߰�
        }
    }

    return cnt;
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    for (int i = 0; i < results.size(); i++) {
        int a = results[i][0], b = results[i][1];
        p[a][b] = 1; // �̱�
        p[b][a] = -1; // ��
    }

    for (int i = 1; i <= n; i++) {
        int cnt = bfs(i, 1, n); // �̱� ��� ���
        cnt += bfs(i, -1, n); // �� ��� ���
        if (cnt == n - 1) answer++; // ���ؼ� n-1�̸� �ڽ��� ������ �� �� �ִ�.
    }

    return answer;
}

int main()
{
    cout << solution(5, { {4,3},{4,2},{3,2},{1,2},{2,5} });
}