#include <iostream>
using namespace std;
int p[100][2];

int main()
{
	int N, sum = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> p[i][0] >> p[i][1];
		sum += (p[i][1] % p[i][0]);
	}
	cout << sum;
}