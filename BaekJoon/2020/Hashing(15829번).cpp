#include <iostream>
#include <string>
using namespace std;
const long long mod = 1234567891;
int L;
string str;

int main()
{
	cin >> L >> str;
	long long res = 0;
	long long R = 1;
	for (int i = 0; i < L; i++) {
		res = (res + (str[i] - 'a' + 1)*R)%mod;
		R = (R * 31) % mod;
	}
	cout << res;
}