#include <iostream>
#include <algorithm>
using namespace std;
int N, M, tmp;
int p[500001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0 ; i < N; i++) {
		cin >> p[i];
	}
	sort(p, p + N);
	cin >> M;
	for (int i = 1; i <= M; i++) {
		cin >> tmp;
		cout << upper_bound(p, p + N, tmp) - lower_bound(p, p + N, tmp) << " ";
	}
}
