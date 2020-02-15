#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;
vector<int> parent, setRank, setSize;
int C, F;

int Find(int u) {
	if (parent[u] == u) return u;
	return parent[u] = Find(parent[u]);
}

void Union(int u, int v) {
	u = Find(u), v = Find(v);
	if (u == v) return;
	if (setRank[u] > setRank[v]) swap(u, v);
	parent[u] = v;
	if (setRank[u] == setRank[v]) setRank[v]++;
	setSize[v] += setSize[u];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> C;
	while (C--) {
		cin >> F;

		parent.resize(2*F + 1);
		for (int i = 0; i < 2*F + 1; i++) parent[i] = i;
		setSize.assign(2*F + 1, 1);
		setRank.assign(2*F + 1, 1);

		map<string, int> m;

		int cnt = 0;
		string a, b;
		for (int i = 0; i < F; i++) {
			cin >> a >> b;
			if (m.find(a) == m.end()) {
				m.insert({ a,cnt++ });
			}
			if (m.find(b) == m.end()) {
				m.insert({ b,cnt++ });
			}
			Union(m[a], m[b]);
			cout << setSize[Find(m[a])] << "\n";
		}
	}
}