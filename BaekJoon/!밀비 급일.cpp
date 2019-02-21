<<<<<<< HEAD
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main()
{
	string str;

	while (true) {
		char s[501];
		cin.getline(s,500);
		str = s;
		if (str == "END") break;
		reverse(str.begin(), str.end());
		cout << str << endl;
	}
=======
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main()
{
	string str;

	while (true) {
		char s[501];
		cin.getline(s,500);
		str = s;
		if (str == "END") break;
		reverse(str.begin(), str.end());
		cout << str << endl;
	}
>>>>>>> 7f36c76f4ad21fe245254ea3f1b3c6e1e3bbbd90
}