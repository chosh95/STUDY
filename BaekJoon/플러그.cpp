#include <iostream>
using namespace std;

int main()
{
	int N,tmp;
	double res = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		res += tmp;
	}
	res -= (N-1);
	cout << res;
}