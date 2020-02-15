#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<int> parent, setRank, setSize;

int find(int u) {
	if (parent[u] == u) return u;
	return parent[u] = find(parent[u]);
}

void Union(int u, int v) {
	u = find(u), v = find(v);
	if (u == v) return;
	if (setRank[u] > setRank[v]) swap(u, v); //랭크가 낮은 노드를 높은 노드에 합친다.
	parent[u] = v;
	if (setRank[u] == setRank[v]) setRank[v]++; 
	setSize[v] += setSize[u];
}

int main()
{
	cin >> N;
	parent.resize(N);
	for (int i = 0; i < N; i++) parent[i] = i; 	//각자의 루트는 자기자신으로 초기화
	setRank.assign(N, 1); //각자 초기 랭크는 1이다.
	setSize.assign(N, 1); //초기 루트의 사이즈 역시 1
	
	Union(1, 2);
	Union(3, 4);
	cout << find(1) << " " << find(3);

}