#include <iostream>
#include <string>
#include <queue>
using namespace std;
int p[102][102];
int dist[102][102];
bool pp[102][102];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 }; 

void maze(int n,int m){
	queue<pair<int,int> > q;
	q.push(make_pair(1,1));
	pp[1][1] = true;
	dist[1][1] = 1;
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();		
		if(x==n && y==m) break;
		for(int i=0;i<4;i++){
			int nx = x+dx[i];
			int ny = y+dy[i];
			if(nx <= n && ny <= m && nx > 0 && ny > 0){
				if(p[nx][ny]==1 && pp[nx][ny]==false){
					dist[nx][ny] = dist[x][y]+1;
					pp[nx][ny] = true;
					q.push(make_pair(nx,ny));
				}	
			}
		}
	}
}


int main()
{
	int N,M;
	string S;
	cin>>N>>M;
	for(int i=0;i<=101;i++){
		p[0][i]=0;
		p[i][0]=0;
		pp[0][i] = true;
		pp[i][0] = true;
	}
	for(int i=1;i<=N;i++){
		cin>>S;
		for(int j=1;j<=M;j++){
			pp[i][j] = false;
			dist[i][j] = 0;
			if(S[j-1]=='1') p[i][j]=1;
			else p[i][j]=0;
		}
	}
	maze(N,M);
	cout<<dist[N][M];
	return 0;
}
