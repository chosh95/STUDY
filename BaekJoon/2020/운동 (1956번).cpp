#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int V, E;
long long dist[402][402];

int main()
{
	cin >> V >> E;
	
	//초기화
	for (int i = 1; i <= V; i++) 
		for (int j = 1; j <= V; j++) 
			dist[i][j] = 987654321;
	
	//입력
	for (int a, b, c, i = 0; i < E; i++) {
		cin >> a >> b >> c;
		dist[a][b] = c;
	}

	//플로이드-와샬 게산
	for (int i = 1; i <= V; i++) 
		for (int j = 1; j <= V; j++) 
			for (int k = 1; k <= V; k++) 
					dist[j][k] = min(dist[j][k],dist[j][i] + dist[i][k]);
	
	//사이클 최소값 구하기
	long long res = 987654321;
	for (int i = 1; i <= V; i++)
		res = min(res, dist[i][i]);
		
	//출력
	if (res == 987654321) res = -1;
	cout << res;
}