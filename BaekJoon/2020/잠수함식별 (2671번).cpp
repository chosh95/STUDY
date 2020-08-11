#include <iostream>
#include <algorithm>
#include <regex>
using namespace std;

int main()
{
	string str;
	cin >> str;
	regex reg("(100+1+|01)+");
	if (regex_match(str, reg)) {
		cout << "SUBMARINE";
	}
	else
		cout << "NOISE";
}