#include <iostream>
using namespace std;

int N, M, K;

int main()
{
	cin >> N >> M >> K;
	if (K > N+M || N==0 || M==0) {
		cout << 0;
		return 0;
	}

	int t = 0;
	if(N>=2*M) t = M;
	else t = N / 2;
	int res = (N - 2 * t) + (M - t);
	if (res >= K) {
		cout << t;
		return 0;
	}
	else {
		K -= res;
		while (K > 0) {
			K -= 3;
			t -= 1;
		}
		cout << t;
		return 0;
	}
}