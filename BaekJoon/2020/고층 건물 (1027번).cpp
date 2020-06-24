#include <iostream>
#include <algorithm>
using namespace std;
int N, res;
int p[52]; //건물 높이
const double INF = 1000000001;

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) 
		cin >> p[i];

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		int tmp = 0;
		double mn = INF;
		for (int j = i - 1; j >= 1; j--) {
			double xx = (double)(p[j] - p[i]) / (double)(j - i);
			if (xx < mn) {
				tmp++;
				mn = xx;
			}
		}
		double mx = -INF;
		for (int j = i + 1; j <= N; j++) {
			double xx = (double)(p[j] - p[i]) / (double)(j - i);
			if (xx > mx) {
				tmp++;
				mx = xx;
			}
		}
		ans = max(ans, tmp);
	}
	cout << ans;
	return 0;
}