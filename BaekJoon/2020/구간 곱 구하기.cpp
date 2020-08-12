#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int p[1000001];
vector<long long> range;
long long N, M, K;

long long init(int left, int right, int node) {
	if (left == right) return range[node] = p[left];
	int mid = (left + right) / 2;
	return range[node] = (init(left, mid, node * 2) * init(mid + 1, right, node * 2 + 1)) % 1000000007;
}

long long query(int left, int right, int node, int nodeLeft, int nodeRight) {
	if (nodeRight < left || right < nodeLeft) return 1;
	if (left <= nodeLeft && nodeRight <= right) return range[node];
	int mid = (nodeLeft + nodeRight) / 2;
	return (query(left, right, node * 2, nodeLeft, mid) * query(left, right, node * 2 + 1, mid + 1, nodeRight)) % 1000000007;
}

void update(int idx, long long value, int node, int nodeLeft, int nodeRight) {
	if (idx < nodeLeft || nodeRight < idx) return;
	if (nodeLeft == nodeRight) {
		range[node] = value;
		return;
	}
	int mid = (nodeLeft + nodeRight) / 2;
	update(idx, value, node * 2, nodeLeft, mid);
	update(idx, value, node * 2 + 1, mid + 1, nodeRight);
	range[node] = (range[node * 2] * range[node * 2 + 1]) % 1000000007;
}

int main()
{
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
		cin >> p[i];
	range.resize(N * 4);
	init(0,N-1,1);

	for (int i = 0; i < M + K; i++) {
		long long a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			update(b-1, c, 1, 0, N-1);
		}
		else {
			cout << query(b-1, c-1, 1, 0, N - 1) << "\n";
		}
	}

}