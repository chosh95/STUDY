#include <iostream>
using namespace std;
int N;

int main()
{
	cin >> N;
	int res = 0, idx = 1;
	while (idx <= N) {
		res += (N - idx + 1);
		idx *= 10;
	}
	cout << res;
}