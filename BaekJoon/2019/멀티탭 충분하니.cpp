#include <iostream>
using namespace std;
int N, K;
int main()
{
	cin >> N >> K;
	int sum = 0;
	for (int i = 0, tmp; i < K; i++) {
		cin >> tmp;
		if (tmp % 2 == 0) sum += tmp / 2;
		else sum += (tmp / 2 + 1);
	}
	if (sum >= N) cout << "YES";
	else cout << "NO";
	return 0;
}