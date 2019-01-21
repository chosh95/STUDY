#include <iostream>
using namespace std;

int main()
{
	int N,t;
	cin >> N;
	long long sum = 0;
	for (int i = 1; i <= N*N; i++) {
		cin >> t;
		sum += t;
	}
	cout << sum;
}