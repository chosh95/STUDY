#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int N, B;

int main()
{
	cin >> N >> B;
	string res = "";

	while (N!=0) {
		int tmp = N % B;
		if (tmp < 10) res += ('0' + tmp);
		else res += ('A' - 10 + tmp);
		N /= B;
	}
	reverse(res.begin(), res.end());
	cout << res;
}