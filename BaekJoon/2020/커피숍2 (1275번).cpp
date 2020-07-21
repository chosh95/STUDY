#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;
int p[100001];
vector<ll> range;
int N, Q;

ll init(int left, int right, int node) {
	if (left == right) return range[node] = p[left];
	int mid = (left + right) / 2;
	return range[node] = init(left, mid, node * 2) + init(mid + 1, right, node * 2 + 1);
}

//left, right는 구하고자 하는 범위, nodeLeft, nodeRight는 현재 조사하는 범위, node는 현재 위치
ll query(int left, int right, int node, int nodeLeft, int nodeRight) {
	if (nodeRight < left || right < nodeLeft) return 0;
	if (left <= nodeLeft && nodeRight <= right) return range[node];
	int mid = (nodeLeft + nodeRight) / 2;
	return query(left, right, node * 2, nodeLeft, mid) + query(left, right, node * 2 + 1, mid + 1, nodeRight);
	
}

void update(int idx, int value, int node, int nodeLeft, int nodeRight) {
	if (idx < nodeLeft || nodeRight < idx) return;
	if (nodeLeft == nodeRight) {
		range[node] = value;
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
	int x, y, a, b;
	cin >> N >> Q;
	range.resize(N * 4);
	for (int i = 0; i < N; i++) 
		cin >> p[i];

	init(0,N-1,1);

	for (int i = 0; i < Q; i++) {
		cin >> x >> y >> a >> b;
		if (x > y) swap(x, y);
		cout << query(x-1, y-1, 1, 0, N-1)<<"\n";
		update(a-1, b, 1, 0, N-1);
	}
}
