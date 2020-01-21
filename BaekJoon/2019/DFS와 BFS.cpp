#include <iostream>
#include <queue>
using namespace std;
int ad[1001][1001];
bool p[1001];
bool pp[1001];
void dfs(int a,int n)
{
	p[a] = true;
	cout<<a<<' ';
	for(int i=1;i<=n;i++){
		if(ad[a][i]==1 && !p[i]){
			dfs(i,n);
		}
	}
}
void bfs(int a,int n)
{
	queue<int> q;
	q.push(a);
	pp[a] = true;
	cout<<a<<' ';
	while(!q.empty())
	{
		int c = q.front();
		q.pop();
		for(int i=1;i<=n;i++){
			if(ad[c][i]==1 && !pp[i]){
				q.push(i);
				pp[i] = true;
				cout<<i<<' ';
			}
		}
	}
}
int main()
{
	int N,M,V,a,b;
	cin>>N>>M>>V;
	for(int i=1;i<=M;i++){
		cin>>a>>b;
		ad[a][b] = 1;
		ad[b][a] = 1;
	}
	dfs(V,N);
	cout<<endl;
	bfs(V,N);
}
