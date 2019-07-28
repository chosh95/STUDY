#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int p[3];

int main()
{
	cin >> p[0] >> p[1] >> p[2];
	sort(p, p + 3);
	string s;
	cin >> s;
	for (int i = 0; i < 3; i++) 
		cout << p[s[i] - 'A'] << " ";	
}