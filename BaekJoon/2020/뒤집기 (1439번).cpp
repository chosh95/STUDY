#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string origin;

int main()
{
	cin >> origin;
	
	int zero = 0, one = 0;
	if (origin[0] == '0') zero++;
	else one++;

	for (int i = 1; i < origin.size(); i++) {
		if (origin[i] != origin[i - 1]) {
			if (origin[i] == '1') one++;
			else zero++;
		}
	}

	cout << min(zero, one);
}