#include <iostream>
#include <algorithm>
using namespace std;
int M, N;
int L[1000001];
int res;

void bisearch(long long lo, long long hi)
{
	if (lo > hi) return;
	long long mid = (lo + hi) / 2;
	int cnt = 0;

	for (int i = 0; i < N; i++) 
		cnt += (L[i] / mid);
	if (cnt >= M) {
		if (res < mid) res = mid;
		bisearch(mid+1, hi);
	}
	else{
		bisearch(lo, mid-1);
	}
}


int main()
{
	cin >> M >> N;
	for (int i = 0; i < N; i++) 
		cin >> L[i];
	sort(L, L + N);
	bisearch(1, L[N - 1]);
	cout << res;
}