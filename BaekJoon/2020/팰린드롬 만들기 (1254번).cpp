#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
using namespace std;
string str;
int n = str.size();

bool isPalin(int idx) {
	int half = (n - idx) / 2;
	for (int i = 0; i < half; i++) {
		if (str[idx + i] != str[n - 1 - i]) return false;
	}
	return true;
}

int main()
{
	cin >> str;
	n = str.size();

	for (int i = 0; i < n; i++) {
		if (isPalin(i)) {
			cout << n + i;
			return 0;
		}
	}
}