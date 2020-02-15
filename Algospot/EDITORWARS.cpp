#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int C, N, M;
struct UnionFind {
	vector<int> parent, rank, size, enemy; // 노드의 부모 노드, 트리의 랭크, 트리의 크기, 적대관계인 집합의 루트
	UnionFind(int n) : parent(n), rank(n, 0), enemy(n, -1), size(n, 1) {
		for (int i = 0; i < n; i++) parent[i] = i;
	}
	//루트를 찾는다.
	int find(int u) {
		if (parent[u] == u) return u;
		return parent[u] = find(parent[u]);
	}
	//u와 v를 합쳐서 루트번호를 반환
	int merge(int u, int v) {
		//공집합인 경우 나머지 반환
		if (u == -1 || v == -1) return max(u, v);
		u = find(u), v = find(v);
		//루트가 같은 경우
		if (u == v) return u;
		if (rank[u] > rank[v]) swap(u, v);
		if (rank[u] == rank[v]) rank[v]++;
		//랭크가 낮은 노드를 더 높은곳에 합친다.
		parent[u] = v;
		size[v] += size[u];
		return v;
	}

	//u와 v가 서로 적인가.
	bool dis(int u, int v) {
		u = find(u), v = find(v);
		if (u == v) return false; //서로 동지라면 거짓
		//적의 적은 동지
		int a = merge(u, enemy[v]), b = merge(v, enemy[u]);
		enemy[a] = b, enemy[b] = a;
		return true;
	}
	bool ack(int u, int v) {
		u = find(u), v = find(v);
		if (enemy[u] == v) return false;
		//동지의 적은 나의 적
		int a = merge(u, v), b = merge(enemy[u], enemy[v]);
		enemy[a] = b;
		if (b != -1) enemy[b] = a;
		return true;
	}
};

int maxParty(const UnionFind t) {
	int res = 0;
	for (int node = 0; node < N; node++) {
		if (t.parent[node] == node) {
			int enemy = t.enemy[node];

			//같은 모임을 두 번 이상 세지 않으려고 한 경우만 센다.
			if (enemy > node) continue;

			int Size = t.size[node];
			int enemySize = (enemy == -1 ? 0 : t.size[enemy]);
			res += max(Size, enemySize);
		}
	}
	return res;
}

int main()
{
	cin >> C;
	while (C--) {
		cin >> N >> M;
		UnionFind t(N);
		bool makeSense = true;
		int resLine = 0;
		for(int j=0;j<M;j++) {
			string str;
			int n, m;
			cin >> str >> n >> m;
			if (!makeSense) continue;
			if (str == "ACK") {
				if (!t.ack(n, m)) {
					makeSense = false;
					resLine = j + 1;
				}
			}
			else {
				if (!t.dis(n, m)) {
					makeSense = false;
					resLine = j + 1;
				}
			}
		}
		if (makeSense)
			cout << "MAX PARTY SIZE IS "<<maxParty(t)<<endl;
		else
			cout << "CONTRADICTION AT " << resLine << endl;
	}
}