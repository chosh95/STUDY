#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int p[1000000 + 2];
int M, N;
int res;
void search(ll low, ll high)
{
	if (low > high) return;
	ll mid = (low + high) / 2;
	int tmp = 0;
	for (int i = 0; i < N; i++) {
		if(mid <= p[i]) tmp += (p[i] / mid);
	}
	if (tmp >= M) {
		if (res < mid) res = mid;
		search(mid + 1, high);
	}
	else
		search(low, mid - 1);
}

int main()
{
	cin >> M >> N;
	for (int i = 0; i < N; i++) scanf("%d", &p[i]);
	sort(p, p + N);
	search(1, p[N - 1]);
	cout << res;
}
