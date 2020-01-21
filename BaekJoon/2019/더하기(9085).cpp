#include <iostream>
using namespace std;
int main()
{
	int T;
	cin >> T;
	while (T--) {
		int N, sum = 0, tmp;
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> tmp;
			sum += tmp;
		}
		cout << sum << "\n";
	}
}