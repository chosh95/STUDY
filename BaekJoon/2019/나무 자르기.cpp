#include <iostream>
#include <algorithm>
using namespace std;
long long N, M;
long long res;
long long p[1000001];
void search(long long low, long long high)
{
	if (low > high) return;
	long long mid = (low + high) / 2;;
	long long tmp = 0;
	for (int i = 0; i < N; i++) {
		if(p[i]>mid)
			tmp += (p[i] - mid);
	}
	if (tmp >= M) {
		if (res < mid) res = mid;
		search(mid + 1, high);
	}
	else search(low, mid - 1);
}
int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> p[i];
	sort(p, p + N);
	search(0,p[N-1]);
	cout << res;
}