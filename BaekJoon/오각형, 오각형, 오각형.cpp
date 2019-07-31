#include <iostream>
using namespace std;
int N;
 
int main()
{
	cin >> N;
	int res = 1, idx = 1;
	while (idx <= N) {
		res += ((idx + 1) * 2 + idx - 1);
		res %= 45678;
		idx++;
	}
	cout << res;
}