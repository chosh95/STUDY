<<<<<<< HEAD
#include <iostream>
#include <string>
using namespace std;
int p[30];

int main()
{
	string s;
	cin >> s;
	for (int i = 0; i <s.length(); i++) {
		p[s[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) cout << p[i] << ' ';
=======
#include <iostream>
#include <string>
using namespace std;
int p[30];

int main()
{
	string s;
	cin >> s;
	for (int i = 0; i <s.length(); i++) {
		p[s[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) cout << p[i] << ' ';
>>>>>>> 7f36c76f4ad21fe245254ea3f1b3c6e1e3bbbd90
}