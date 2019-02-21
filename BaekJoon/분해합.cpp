#include <iostream>
using namespace std;
int p[1000000 + 1];

int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int sum = i;
		int tmp = i;
		while (i>0) {
			sum += (i % 10);
			i /= 10;
		}
		if (sum == N) {
			cout << tmp;
			return 0;
		}
		i = tmp;
	}
	cout << "0"; 
	return 0;
}