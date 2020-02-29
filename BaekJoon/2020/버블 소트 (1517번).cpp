#include <iostream>
using namespace std;
int p[500001];
int tmp[500001];
int N, res;

long long merge(int start, int end) {
	if (start == end) return 0;
	int mid = (start + end) / 2;
	long long res = merge(start, mid) + merge(mid + 1, end);
	int i = start;
	int j = mid + 1;
	int idx = 0;
	while (i <= mid || j <= end) {
		if (i <= mid && (j > end || p[i] <= p[j]))
			tmp[idx++] = p[i++];
		else {
			res += (long long)(mid - i + 1);
			tmp[idx++] = p[j++];
		}
	}

	for (int k = start; k <= end; k++) {
		p[k] = tmp[k - start];
	}
	return res;
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) 
		cin >> p[i];

	long long res = merge(1, N);

	cout << res;
}