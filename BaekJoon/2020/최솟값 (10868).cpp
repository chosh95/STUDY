#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
vector<int> p;
vector<int> range;

int init(int left, int right, int node) {
	if (left == right) return range[node] = p[left];
	int mid = (left + right) / 2;
	return range[node] = min(init(left, mid, node * 2),init(mid + 1, right, node * 2 + 1));
}

int query(int left, int right, int node, int nodeLeft, int nodeRight) {
	if (nodeRight < left || right < nodeLeft) return 987654321;
	if (left <= nodeLeft && nodeRight <= right) return range[node];
	int mid = (nodeLeft + nodeRight) / 2;
	int res = min(query(left, right, node * 2, nodeLeft, mid),query(left, right, node * 2 + 1, mid + 1,nodeRight));
	return res;	
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	p.resize(N);
	range.resize(N * 4);
	for (int i = 0; i < N; i++) cin >> p[i];
	int tmp = init(0,N-1,1);
	
	for (int a, b, j = 0; j < M; j++) {
		cin >> a >> b;
		cout << query(a-1, b-1,1,0,N-1) << "\n";
	}
}