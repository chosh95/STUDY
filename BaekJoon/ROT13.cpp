#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	getline(cin,s);
	for (int i = 0; i < s.size(); i++) {
		if ((s[i]>='A' && s[i]<='A'+12) || (s[i]>='a' && s[i]<='a'+12)){
			s[i] = char(s[i]+13);
		}
		else if((s[i]>='0' && s[i]<='9') || s[i] == ' ')
			continue;
		else
			s[i] = (s[i]-13);
	}
	cout << s;
}