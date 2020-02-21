#include <iostream>
using namespace std;
int J, A, res;
int p[1000001];
int parent[1000001];

int find(int u) {
	if (parent[u] == u) return u;
	return parent[u] = find(parent[u]);
}


int main()
{
	cin >> J >> A;
	char tmp;
	for (int i = 0; i <= J; i++) parent[i] = i;

	for (int i = 1; i <= J; i++) {
		cin >> tmp;
		if (tmp == 'S') p[i] = 1;
		else if (tmp == 'M') p[i] = 2;
		else p[i] = 3;
	}

	for (int idx, i = 1; i <= A; i++) {
		cin >> tmp >> idx;
		if (find(idx) != idx) continue;
		else {
			if (tmp == 'L' && p[idx] != 3) continue;
			else if (tmp == 'M' && p[idx] < 2) continue;
			parent[idx] = 0;
			res++;
		}
	}
	cout << res;
}