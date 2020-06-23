#include <iostream>
#include <algorithm>
using namespace std;
int N;
int resM, resY;

int main()
{
	cin >> N;
	int num;
	while (N--) {
		cin >> num;
		resM += ((num / 60) + 1) * 15;
		resY += ((num / 30) + 1) * 10;
	}

	if (resM == resY)
		cout << "Y M " << resM;
	else if (resM < resY)
		cout << "M " << resM;
	else
		cout << "Y " << resY;
}