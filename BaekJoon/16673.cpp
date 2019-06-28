#include <iostream>
using namespace std;
int main()
{
	int C, K, P;
	cin >> C >> K >> P;
	int res = 0;
	for (int i = 1; i <= C; i++) {
		int tmp = K * i + P * i*i;
		res += tmp;
	}
	cout << res;
}