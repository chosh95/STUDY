#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a, b;
	cin >> a >> b;
	int alen = a.size();
	int blen = b.size();

	for (int i = 0; i < alen; i++) if (a[i] == '6') a[i] = '5';
	for (int i = 0; i < blen; i++) if (b[i] == '6') b[i] = '5';
	int r1 = stoi(a) + stoi(b);

	for (int i = 0; i < alen; i++) if (a[i] == '5') a[i] = '6';
	for (int i = 0; i < blen; i++) if (b[i] == '5') b[i] = '6';
	int r2 = stoi(a) + stoi(b);

	cout << r1 << " " << r2;
}