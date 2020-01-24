#include <iostream>
#include <queue>
using namespace std;

int N;
int p[17][17];
int visit[17][17][3]; //x, y, direction( 0 : 가로, 1 : 대각선, 2 : 세로)

void dp()
{
	visit[1][2][0] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 2; j <= N; j++) {
			if (i == 1 && j == 2) continue;
			if (p[i][j] == 1) continue;
			visit[i][j][0] = visit[i][j - 1][0] + visit[i][j - 1][1];
			visit[i][j][2] = visit[i - 1][j][2] + visit[i - 1][j][1];
			if (p[i - 1][j] == 0 && p[i][j - 1] == 0) {
				visit[i][j][1] = visit[i - 1][j - 1][0] + visit[i - 1][j - 1][1] + visit[i - 1][j - 1][2];
			}
		}
	}
}


int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= N; j++) 
			cin >> p[i][j];
	dp();
	cout << visit[N][N][0] + visit[N][N][1] + visit[N][N][2];
}