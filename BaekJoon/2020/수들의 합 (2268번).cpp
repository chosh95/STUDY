#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;
int N, M;
vector<long long> range;
int p[1000001];

long long init(int left, int right, int node) {
	if (left == right) return range[node] = p[left];
	int mid = (left + right) / 2;
	return range[node] = init(left, mid, node * 2) + init(mid + 1, right, node * 2 + 1);
}

long long query(int left, int right, int node, int nodeLeft, int nodeRight) {
	if (left <= nodeLeft && nodeRight <= right) return range[node];
	if (right < nodeLeft || nodeRight < left) return 0;
	int mid = (nodeLeft + nodeRight) / 2;
	return query(left, right, node * 2, nodeLeft, mid) + query(left, right, node * 2 + 1, mid + 1, nodeRight);
}

void update(int idx, int value, int node, int nodeLeft, int nodeRight){
	if (idx < nodeLeft || nodeRight < idx) return;
	if (nodeLeft == nodeRight) {
		p[idx-1] = range[node] = value;
		return;
	}
	int mid = (nodeLeft + nodeRight) / 2;
	update(idx, value, node * 2, nodeLeft, mid);
	update(idx, value, node * 2 + 1, mid + 1, nodeRight);
	range[node] = range[node * 2] + range[node * 2 + 1];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	range.resize(N * 4);
	init(0, N - 1, 1);
	for (int a, b, c, i = 0; i < M; i++) {
		cin >> a >> b >> c;
		if (a == 0) {
			if (b > c) swap(b, c);
			cout << query(b - 1, c - 1, 1, 0, N - 1) << "\n";
		}
		else {
			update(b - 1, c, 1, 0, N - 1);
		}
	}
}