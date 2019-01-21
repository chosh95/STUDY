#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <limits.h>
using namespace std;
vector<pair<int,int> > adj[20001];

vector<int> dijkstra(int s,int v,int e) 
{
	vector<int> dist(v,INT_MAX);
	dist[s] = 0;
	
	priority_queue<pair<int,int> > pq;
	pq.push(make_pair(0,s));
	while(!pq.empty()){
		int cost  = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if(dist[here]<cost) continue;
		for(int i=0;i<adj[here].size();i++){
			int there = adj[here][i].first;
			int nextdist = cost+adj[here][i].second;
			if(dist[there]>nextdist){
				dist[there] = nextdist;
				pq.push(make_pair(-nextdist,there));
			}
		}
	}
	return dist;
}

int main()
{
	int V,E,start;
	scanf("%d %d %d",&V,&E,&start);
	V++;
	for(int i=1;i<=E;i++){
		int from,to,weight;
		scanf("%d %d %d", &from, &to, &weight);
		adj[from].push_back(make_pair(to,weight));		
	}
	vector<int> ans = dijkstra(start,V,E);
	for(int i=1;i<V;i++){
		if(ans[i]==INT_MAX) printf("INF\n");
		else printf("%d\n",ans[i]);
	}	
	return 0;
}
