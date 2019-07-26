#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
using namespace std;
int p[100001];
int first[100001];
int visit[100001];

int dfs(int start, int cur, int cnt)
{
	first[cur] = start; //시작점 기록
	visit[cur] = cnt; //현재 노드의 방문횟수
	int next = p[cur];
	if (visit[next] == 0) dfs(start, next, cnt + 1); //미방문시 방문
	else if (visit[next] != 0 && start == first[next]) // 방문 했고 cycle의 시작점과 같으면
		return cnt - visit[next] + 1; //cycle의 개수 반환
	else return 0;
}

int main()
{
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		memset(visit, 0, sizeof(visit));
		memset(first, 0, sizeof(first));
		int res = 0;
		for (int i = 1; i <= N; i++) scanf("%d", &p[i]);
		for (int i = 1; i <= N; i++) {
			if (visit[i] == 0) res += dfs(i, i, 1);
		}
		cout << N-res << "\n";
	}

}