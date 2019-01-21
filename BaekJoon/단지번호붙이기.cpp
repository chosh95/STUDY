#include <iostream>
#include <algorithm>
using namespace std;
int p[26][26];
bool visit[26][26];
int res[500];
int N,current=0;

void dfs(int a,int b)
{
	visit[a][b] = true;
	res[current]++;
	if(p[a][b+1]==1 && !visit[a][b+1]) dfs(a,b+1);
	if(p[a+1][b]==1 && !visit[a+1][b]) dfs(a+1,b);		
	if(a!=1 && p[a-1][b]==1 && !visit[a-1][b]) dfs(a-1,b);		
	if(b!=1 && p[a][b-1]==1 && !visit[a][b-1]) dfs(a,b-1);		
}

int main()
{
	cin>>N;
	char c;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cin>>c;
			if(c=='0') p[i][j] = 0;
			else p[i][j] = 1;
		}
	}
	
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(p[i][j]==1 && !visit[i][j]){
				current++;
				dfs(i,j);
			}
		}
	}
	
	cout<<current<<endl;
	sort(res+1,res+current+1);
	for(int i=1;i<=current;i++) cout<<res[i]<<endl;	
}
