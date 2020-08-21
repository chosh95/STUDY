#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int N;
int p[100001];
vector<int> range;

int init(int left, int right, int node) {
	if (left == right) return range[node] = left; // 인덱스를 저장

	int mid = (left + right) / 2;
	int lo = init(left, mid, node * 2);
	int hi = init(mid + 1, right, node * 2 + 1);

	if (p[lo] <= p[hi]) return range[node] = lo; // 구간 내에 최소값을 가지는 인덱스를 저장
	else return range[node] = hi;
}

int query(int left, int right, int node, int nodeLeft, int nodeRight) {
	if (left <= nodeLeft && nodeRight <= right) return range[node]; // 구하는 범위 내에 있을 경우 반환
	if (nodeRight < left || right < nodeLeft) return -1; // 범위 벗어나면 -1

	int mid = (nodeLeft + nodeRight) / 2;
	int lo = query(left, right, node * 2, nodeLeft, mid); // (nodeLeft, mid) 사이의 최소값 인덱스
	int hi = query(left, right, node * 2 + 1, mid + 1, nodeRight); // (mid+1, nodeRight) 사이의 최소값 인덱스

	if (lo == -1) return hi; 
	if (hi == -1) return lo;
	if (p[lo] <= p[hi]) return lo; // 최소값을 갖는 인덱스 반환.
	else return hi;
}

ll solve(int left, int right) {
	if (left > right) return -1; // 종료조건

	int loIdx = query(left, right, 1, 0, N - 1); // (left,right) 범위의 최소값을 갖는 인덱스 구하기
	ll res = (ll)((ll)right - (ll)left + 1) * p[loIdx]; // (left, right) 범위를 모두 포함하게 만들 수 있는 직사각형 넓이

	if (loIdx != left)
		res = max(res, solve(left, loIdx - 1)); // (left, loIdx-1) 까지 범위로 만들 수 있는 직사각형의 최대 넓이 최신화
	if (loIdx != right) 
		res = max(res, solve(loIdx + 1, right)); // (loIdx+1, right) 범위
	
	return res; // 최대 넓이 반환
}

int main()
{
	cin >> N;
	range.resize(N * 4);
	for (int i = 0; i < N; i++)
		cin >> p[i];
	
	init(0, N - 1, 1); // 세그먼트 트리 초기화
	
	cout << solve(0, N - 1); // 정답 출력
}