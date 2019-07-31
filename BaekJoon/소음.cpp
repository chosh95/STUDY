#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a, b;
	char op;
	cin >> a >> op >> b;
	int alen = a.size();
	int blen = b.size();

	if (op == '+') {
		if (alen < blen) {
			int tmp = blen;
			blen = alen;
			alen = tmp;
		}

		if (alen == blen) {
			cout << "2";
			for (int i = 1; i < alen; i++) cout << "0";
		}
		else {
			cout << "1";
			for (int i = 1; i < alen; i++) {
				if (i == alen - blen) {
					cout << "1";
					continue;
				}
				cout << "0";
			}
		}
	}
	else {
		cout << "1";
		for (int i = 1; i < alen + blen - 1; i++) cout << "0";
	}
}