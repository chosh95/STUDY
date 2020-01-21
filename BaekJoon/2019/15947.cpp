#include <iostream>
#include <string>
using namespace std;
int N;
void tururu(int l)
{
	if (l >= 3)
		cout << "tu+ru*" << l + 2;
	else {
		cout << "tururu";
		for (int i = 1; i <= l; i++) cout << "ru";
	}
}
void turu(int l)
{
	if(l>=4)
		cout << "tu+ru*" << l + 1;
	else {
		cout << "turu";
		for (int i = 1; i <= l; i++) cout << "ru";
	}
}

int main()
{
	cin >> N;
	int loop = N / 14;
	N -= 14 * loop;
	if (N == 3 || N == 7 || N == 11)
		tururu(loop);
	else if(N==4 || N==8 || N==12)
		turu(loop);

	while (true) {
		if (N == 1 || N == 13)
			cout << "baby";
		else if (N == 2 || N == 0)
			cout << "sukhwan";
		else if (N == 5)
			cout << "very";
		else if (N == 6)
			cout << "cute";
		else if (N == 9)
			cout << "in";
		else if (N == 10)
			cout << "bed";
		return 0;
	}
}