#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
int p[1000001];
vector<int> range;

int init(int left, int right, int node) {
	if (left == right) return range[node] = p[left];
	int mid = (left + right) / 2;
	return range[node] = max(init(left, mid, node * 2),init(mid + 1, right, node * 2 + 1));
}

int query(int left, int right, int node, int nodeLeft, int nodeRight) {
	if (nodeRight < left || right < nodeLeft) return 0;
	if (left <= nodeLeft && nodeRight <= right) return range[node];
	int mid = (nodeLeft + nodeRight) / 2;
	return max(query(left, right, node * 2, nodeLeft, mid), (query(left, right, node * 2 + 1, mid + 1, nodeRight)));
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> p[i];
	range.resize(N * 4);
	init(0,N-1,1);
	for (int i = M - 1; i <= N - M + 1 - 1; i++) {
		int lo = i - M + 1;
		int hi = i + M - 1;
		cout << query(lo, hi, 1, 0, N - 1) << " ";
	}
}