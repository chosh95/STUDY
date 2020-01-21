#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	cin >> str;
	int N = str.size();
	for (int i = 0; i < N / 2; i++) {
		if (str[i] == str[N - i - 1]) continue;
		else {
			cout << "0";
			return 0;
		}
	}
	cout << "1";
}