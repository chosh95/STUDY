#include <iostream>
#include <string>
using namespace std;

int main()
{
	//방식 1
	string str;
	while (getline(cin,str)) {
		cout << str << "\n";
	}

	//방식 2
	char s[101];
	while (fgets(s, 101, stdin)) {
		printf("%s", s);
	}
}