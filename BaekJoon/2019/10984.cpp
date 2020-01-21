#include <iostream>
using namespace std;
int main()
{
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		int res = 0;
		double sum = 0;
		for (int i = 1; i <= N; i++) {
			int a; double b;
			cin >> a >> b;
			res += a;
			sum += a * b;
		}
		sum /= res;
		printf("%d %.1lf\n", res, sum);
	}
}