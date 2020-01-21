#include <iostream>
#include <queue>
using namespace std;

int p[102][102];
int cp[102][102];
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
int maxnum = 0;
int res;

void bfs(int a,int b,int n)
{
	queue<pair<int,int> > q;
	q.push(make_pair(a,b));
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			int nx = x+dx[i];
			int ny = y+dy[i];
			if(nx>=1 && nx<=n && ny>=1 && ny<=n){
				if(cp[nx][ny]==1){
					cp[nx][ny] = 0;
					q.push(make_pair(nx,ny));
				}
				else continue;
			}			
		}
	}
}

void copy_matrix(int a,int n)
{
	int tmp = 0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(p[i][j]<=a) cp[i][j] = 0;
			else cp[i][j] = 1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(cp[i][j]==1){
				bfs(i,j,n);
				tmp++;
			}
		}
	}
	if(res<tmp) res = tmp;
}

int main()
{
	int N;
	cin>>N;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cin>>p[i][j];
			if(maxnum<p[i][j]) maxnum = p[i][j];
		}
	}
	for(int i=1;i<=maxnum;i++){
		copy_matrix(i,N);
	}
	if(res==0)res=1;
	cout<<res;
}
