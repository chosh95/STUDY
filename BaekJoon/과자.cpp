#include <iostream>
using namespace std;

int main()
{
	int K, N, M;
	cin >> K >> N >> M;
	int res = K * N - M;
	if (res > 0) cout << res;
	else cout << 0;
}