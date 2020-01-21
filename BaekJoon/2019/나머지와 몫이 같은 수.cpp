#include <iostream>
using namespace std;
long long N;

int main()
{
	cin >> N;
	long long sum = 0;
	for (long long  i = 1; i < N; i++) {
		sum += (i * N + i);
	}
	cout << sum;
}