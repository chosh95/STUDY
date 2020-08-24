#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
string a, b;

int main()
{
	cin >> a >> b;
	if (strstr((char*)a.c_str(), (char*)b.c_str()) == NULL)
		cout << 0;
	else
		cout << 1;
}