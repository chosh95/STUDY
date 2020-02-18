#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int C, G, H, res;
int p[1001][1001];
int check[1001];
const int UNWATCHED = 0;
const int WATCHED = 1;
const int INSTALLED = 2;

int dfs(int x) { 
	check[x] = true;
	int child[3] = { 0,0,0 };
	for (int i = 0; i < G; i++) {
		if (!check[i] && p[x][i] == 1) 
			++child[dfs(i)];
	}
	//설치 안된 자손이 있는 경우 x에 설치
	if (child[UNWATCHED]) {
		++res;
		return INSTALLED;
	}
	//모든 자손이 감시 중이고, 설치된 게 있으면 x도 감시중
	if (child[INSTALLED]) {
		return WATCHED;
	}

	//모든 자손이 감시중이기만 하면 x는 감시 안됨
	return UNWATCHED;
}

int main()
{
	cin >> C;
	while (C--) {
		cin >> G >> H;
		memset(p, 0, sizeof(p));
		memset(check, 0, sizeof(check));

		for (int a, b, i = 0; i < H; i++) {
			cin >> a >> b;
			p[a][b] = p[b][a] = 1; //a와 b지점이 연결됐다.
		}
		
		res = 0;
		for (int i = 0; i < G; i++) {
			if (!check[i]) {
				if (dfs(i) == 0) res++;
			}
		}
		cout << res << "\n";
	}
}