#include <iostream>
#include <algorithm>
using namespace std;

long long S;

int main()
{
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
}