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
	if (setRank[u] > setRank[v]) swap(u, v); //��ũ�� ���� ��带 ���� ��忡 ��ģ��.
	parent[u] = v;
	if (setRank[u] == setRank[v]) setRank[v]++; 
	setSize[v] += setSize[u];
}

int main()
{
	cin >> N;
	parent.resize(N);
	for (int i = 0; i < N; i++) parent[i] = i; 	//������ ��Ʈ�� �ڱ��ڽ����� �ʱ�ȭ
	setRank.assign(N, 1); //���� �ʱ� ��ũ�� 1�̴�.
	setSize.assign(N, 1); //�ʱ� ��Ʈ�� ������ ���� 1
	
	Union(1, 2);
	Union(3, 4);
	cout << find(1) << " " << find(3);

}