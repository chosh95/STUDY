#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
typedef long long ll;
using namespace std;
int N;
int h[100001]; //직사각형 각 높이
int range[400001];

int init(int left, int right, int node) {
	if (left == right) return range[node] = left;

	int mid = (left + right) / 2;
	int lo = init(left, mid, node * 2);
	int hi = init(mid + 1, right, node * 2 + 1);

	if (h[lo] <= h[hi]) return range[node] = lo;
	else return range[node] = hi;
}

int query(int left, int right, int node, int nodeLeft, int nodeRight) {
	if (nodeRight < left || right < nodeLeft) return -1;
	if (left <= nodeLeft && nodeRight <= right) return range[node];
	int mid = (nodeLeft + nodeRight) / 2;
	int lo = query(left, right, node * 2, nodeLeft, mid);
	int hi = query(left, right, node * 2 + 1, mid + 1, nodeRight);
	if (lo == -1) return hi;
	if (hi == -1) return lo;
	if (h[lo] <= h[hi]) return lo;
	return hi;
}

ll solve(int left, int right) {
	int low_idx = query(left, right, 1, 0, N - 1);
	ll res = (ll)(right - left + 1) * h[low_idx];
	if(left<=low_idx-1)
		res = max(res, solve(left, low_idx - 1));
	if(low_idx+1<=right)
		res = max(res, solve(low_idx + 1, right));
	return res;
}

int main()
{
	while (true) {
		cin >> N;
		if (N == 0) return 0;
		for (int i = 0; i < N; i++) cin >> h[i];
		init(0,N-1,1);
		cout << solve(0, N - 1) << "\n";
	}
}