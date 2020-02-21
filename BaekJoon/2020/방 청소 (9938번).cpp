#include <iostream>
#include <cstring>
using namespace std;
int parent[300001];
bool visit[300001];
int N, L;

int find(int u) {
	if (parent[u] == u) return u;
	return parent[u] = (find(parent[u]));
}

void merge(int u, int v) {
	u = find(u);
	v = find(v);
	parent[u] = v;
}

int main()
{
	ios::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> L;
	for (int i = 0; i <= L; i++) parent[i] = i;
	for (int a, b, i = 0; i < N; i++) {
		cin >> a >> b;
		if (!visit[a]) {
			visit[a] = true;
			merge(a, b);
			cout << "LADICA\n";
		}
		else if (!visit[b]) {
			visit[b] = true;
			merge(b, a);
			cout << "LADICA\n";
		}
		else if (!visit[find(a)]) {
			visit[find(a)] = true;
			merge(a, b);
			cout << "LADICA\n";
		}
		else if (!visit[find(b)]) {
			visit[find(b)] = true;
			merge(b, a);
			cout << "LADICA\n";
		}
		else
			cout << "SMECE\n";
	}
}