#include <iostream>
using namespace std;
int T,a,b,c;
int main()
{
	cin >> T;
	bool t = true;
	while (T >= 0) {
		if (T >= 300) {
			T -= 300;
			a++;
		}
		else if (T >= 60) {
			T -= 60;
			b++;
		}
		else if (T >= 10) {
			T -= 10;
			c++;
		}
		else if (T == 0) {
			break;
		}
		else {
			t = false;
			break;
		}
	}
	if (t) {
		cout << a << " " << b << " " << c;
	}
	else
		cout << -1;
}