#include <iostream>
#include <algorithm>
using namespace std;
int N;
int p[1001];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) cin >> p[i];
	sort(p, p + N);
	int res = 0;
	int tmp = 0;
	for (int i = 0; i < N; i++) {
		tmp += p[i];
		res += tmp;
	}
	cout << res;
}