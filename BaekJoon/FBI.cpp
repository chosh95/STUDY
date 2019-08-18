#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1 = "FBI";
	bool tmp = false;
	for (int i = 1; i <= 5; i++) {
		string s;
		cin >> s;
		int loc = s.find(s1);
		if (loc == -1) continue;
		else {
			tmp = true;
			cout << i << " ";
		}
	}
	if (tmp == false) cout << "HE GOT AWAY!";
	return 0;
}