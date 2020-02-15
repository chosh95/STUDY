#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M, K;
int a, b, c;
int p[1000001];
vector<int> range;

int init(int left, int right, int node) {
	//단말노드인 경우 값 저장
	if (left == right) return range[node] = p[left];
	int mid = (left + right) / 2;
	//node의 값은 좌,우 자손들의 구간 합
	return range[node] = init(left, mid, node * 2) + init(mid + 1, right, node * 2 + 1);
}

int query(int left, int right, int node, int nodeLeft, int nodeRight) {
	if (nodeRight < left || right < nodeLeft) return 0; //구하려는 구간에 포함되지 않는 경우
	if (left <= nodeLeft && nodeRight <= right) return range[node]; //구간에 완전히 포함된 경우
	int mid = (nodeLeft + nodeRight) / 2;
	//좌,우 자손들의 구간합을 모두 합해 반환.
	return query(left, right, node * 2, nodeLeft, mid) + query(left, right, node * 2 + 1, mid + 1, nodeRight);
}

void update(int idx, int newValue, int node, int nodeLeft, int nodeRight) {
	if (idx < nodeLeft || nodeRight < idx) return; //바꾸려는 idx 범위밖인 경우
	if (nodeLeft == nodeRight) { //바꾸려는 idx에 온 경우
		range[node] = newValue; //값 변경
		return;
	}
	int mid = (nodeLeft + nodeRight) / 2;
	update(idx, newValue, node * 2, nodeLeft, mid);
	update(idx, newValue, node * 2 + 1, mid + 1, nodeRight);
	range[node] = range[node * 2] + range[node * 2 + 1]; //좌,우 자손들의 값을 최신화해준 후 다시 구간합 계산
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
			update(b - 1, c, 1, 0, N - 1);
		}
		else {
			cout << query(b - 1, c - 1, 1, 0, N - 1) << "\n";
		}
	}
}