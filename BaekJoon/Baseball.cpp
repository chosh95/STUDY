#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--) {
		int suma = 0, sumb = 0;
		for (int i = 1,a,b; i <= 9; i++) {
			cin >> a >> b;
			suma += a;
			sumb += b;
		}
		if (suma > sumb) cout << "Yonsei\n";
		else if (suma == sumb) cout << "Draw\n";
		else cout << "Korea\n";
	}
}