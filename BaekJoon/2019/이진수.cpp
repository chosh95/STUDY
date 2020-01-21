#include <iostream>
#include <string>
using namespace std;
int T;
void binary(int n)
{
	string s = "";
	while (n != 0) {
		int tmp = n % 2;
		if (tmp == 0) s += "0";
		else s += "1";
		n /= 2;
	}
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '1') cout << i << " ";
	}
	cout << "\n";
}
int main()
{
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		binary(N);
	}
}