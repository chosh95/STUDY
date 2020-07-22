#include <iostream>
#include <regex>
#include <cstring>
using namespace std;
int N;
int main()
{
	cin >> N;
	regex origin("((100+1+)|(01))+");
	while (N--) {
		string str;
		cin >> str;
		if (regex_match(str, origin))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}