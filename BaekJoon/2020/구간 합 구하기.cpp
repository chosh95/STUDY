#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M, K;
int a, b, c;
long long p[1000001];
vector<long long> range;

long long init(int left, int right, int node) {
	if (left == right) return range[node] = p[left];
	int mid = (left + right) / 2;
	range[node] = init(left, mid, node * 2) + init(mid + 1, right, node * 2 + 1);
	return range[node];
}
long long query(int left, int right, int node, int nodeLeft, int nodeRight) {
	if (nodeRight < left || right < nodeLeft) return 0;
	if (left <= nodeLeft && nodeRight <= right) return range[node];
	int mid = (nodeLeft + nodeRight) / 2;
	return query(left, right, node * 2, nodeLeft, mid) + query(left, right, node * 2 + 1, mid + 1, nodeRight);
}
/*
long long update(int idx, int newValue, int node, int nodeLeft, int nodeRight) {
	if (nodeLeft > idx || idx > nodeRight) return range[node];
	if (nodeLeft == nodeRight) return range[node] = newValue;
	int mid = (nodeLeft + nodeRight) / 2;
	range[node] = update(idx, newValue, node * 2, nodeLeft, mid) + update(idx, newValue, node * 2 + 1, mid + 1, nodeRight);
	return range[node];
}

void update(int idx, int newValue) {
	update(idx, newValue, 1, 0, N - 1);
}*/

void update(int idx, int newValue, int node, int nodeLeft, int nodeRight) {
	if (nodeLeft > idx || idx > nodeRight) return;
	if (nodeLeft == nodeRight) {
		range[node] = newValue;
		return;
	}
	int mid = (nodeLeft + nodeRight) / 2;
	update(idx, newValue, node * 2, nodeLeft, mid);
	update(idx, newValue, node * 2 + 1, mid + 1, nodeRight);
	range[node] = range[node * 2] + range[node * 2 + 1];
}
int main()
{
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) cin >> p[i];
	range.resize(N * 4);
	init(0, N - 1, 1);
	for (int i = 0; i < M + K; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			update(b-1, c,1,0,N-1);
		}
		else {
			cout << query(b - 1 , c - 1, 1, 0, N - 1) << "\n";
		}
	}
}