#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <algorithm>
using namespace std;
int p[200001];
int N, C, res;

void binary_search(int low, int high)
{
	int mid = (low + high) / 2;
	if (mid<low || high<mid) return;
	int cnt = 1;
	int tmp = p[0];
	for (int i = 1; i < N; i++) {
		if (p[i] - tmp >= mid) {
			cnt++;
			tmp = p[i];
		}
	}
	if (cnt >= C) {
		if (res < mid) res = mid;
		binary_search(mid + 1, high);
	}
	else binary_search(low, mid - 1);
}

int main()
{
	cin >> N >> C;
	for (int i = 0; i < N; i++) scanf("%d", &p[i]);
	sort(p, p + N);
	binary_search(1, p[N-1] - p[0]);
	cout << res;
}