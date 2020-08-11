#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
int p[30];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string str;
	while (cin>>str) {
		for (int i = 0; i < str.size(); i++) {
			if(str[i]>='a' && str[i]<='z')
				p[str[i] - 'a']++;
		}
		str.clear();
	}

	int maxnum = 0;
	for (int i = 0; i < 26; i++) 
		maxnum = max(maxnum, p[i]);

	for (int i = 0; i < 26; i++)
		if (p[i] == maxnum)
			cout << (char)(i + 'a');
	return 0;
}