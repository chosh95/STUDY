#include <iostream>
using namespace std;

int main()
{
	long long N, S;
	cin >> S;
	long long cnt = 0, sum = 0;
	for (int i = 1;; i++) {
		if (sum + i <= S) {
			sum += i;
			cnt++;
		}
		else break;
	}
	cout << cnt;
	return 0;
}