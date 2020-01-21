#include <iostream>
#include <string>
using namespace std;

int main()
{
	int T;
	cin >> T;
	cin.ignore();
	while(T--) {
		string tmp;
		getline(cin, tmp);
		int gcnt = 0, bcnt = 0;
		for (int i = 0; i < tmp.size(); i++) {
			if (tmp[i] == 'g' || tmp[i] == 'G') gcnt++;
			else if (tmp[i] == 'b' || tmp[i] == 'B') bcnt++;
			else continue;
		}
		if (gcnt > bcnt) cout << tmp << " is GOOD\n";
		else if (gcnt == bcnt)cout << tmp << " is NEUTRAL\n";
		else cout << tmp << " is A BADDY\n";
	}
}