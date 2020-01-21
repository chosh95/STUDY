#include <iostream>
#include <string>
#include <cmath>
using namespace std;
string N;
int B;

int main()
{
	int tmp, res = 0;
	cin >> N >> B;
	int len = N.size();
	for (int i = 0; i < len; i++) {
		if (N[i] >= '0' && N[i] <= '9') tmp = N[i] - '0';
		else tmp = N[i] - 'A' + 10;
		res += pow(B, len - i - 1)*tmp;
	}
	cout << res;
}