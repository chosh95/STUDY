#include <iostream>
#include <string>
using namespace std;

int N;
string a, b;

int main()
{
	bool isDelete = false;
	cin >> N >> a >> b;

	if (N % 2 == 0) {
		if (a == b) isDelete = true;
	}
	else {
		isDelete = true;
		for (int i = 0; i < a.size(); i++) {
			if (a[i] == b[i]) {
				isDelete = false;
				break;
			}
		}
	}

	if (isDelete)
		cout << "Deletion succeeded\n";
	else
		cout << "Deletion failed\n";
}