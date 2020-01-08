#include <iostream>
#include <algorithm>
using namespace std;
int C, N;
int p[20001];

int fence(int lo, int hi)
{
	if (lo == hi) return p[lo];
	int mid = (lo + hi) / 2;
	int res = max(fence(lo, mid), fence(mid + 1, hi));
	int left = mid, right = mid + 1; //경계선의 왼, 오른쪽 울타리
	int height = min(p[left], p[right]);
	res = max(res, height * 2);
	while (left > lo || right < hi) {
		if (right < hi && (left == lo || p[left - 1] < p[right + 1])) {
			++right;
			height = min(height, p[right]);
		}
		else {
			--left;
			height = min(height, p[left]);
		}
		res = max(res, height * (right - left + 1));
	}
	return res;
}
int main()
{
	cin >> C;
	while (C--) {
		cin >> N;
		for (int i = 1; i <= N; i++) cin >> p[i];
		cout << fence(1, N) << endl;
	}
}