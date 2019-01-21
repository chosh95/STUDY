#include <iostream>
#include <queue>
using namespace std;
int minnum;
bool visit[100001];

int bfs(int n,int k)
{
	queue<pair<int,int> > q;
	q.push(make_pair(n,0));
	visit[n]=true;
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		if(x==k) return y; 		
		if(x-1>=0 && visit[x-1]==false){
			visit[x-1] = true;
			q.push(make_pair(x-1,y+1));
		}
		if(x+1<=100000 && visit[x+1]==false){
			visit[x+1] = true;
			q.push(make_pair(x+1,y+1));
		}
		if(x*2<=100000 && visit[x*2]==false){
			visit[x*2] = true;
			q.push(make_pair(x*2,y+1));
		}
	}
}


int main()
{
	int N,K;
	cin>>N>>K;
	minnum = K-N;
	for(int i=0;i<=100000;i++) visit[i] = false;
	cout<<bfs(N,K);
}
