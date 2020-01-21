#include <iostream>
using namespace std;

int N, K;
int main()
{
	cin >> N >> K;
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (N%i == 0) {
			cnt += 1;
			if (cnt == K) {
				cout << i;
				return 0;
			}
		}
	}
	cout << 0;
	return 0;
}