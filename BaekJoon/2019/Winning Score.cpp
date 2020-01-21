#include <iostream>
using namespace std;

int main()
{
	int a, b, c,res1,res2;
	cin >> a >> b >> c;
	res1 = 3 * a + 2 * b + c;
	cin >> a >> b >> c;
	res2 = 3 * a + 2 * b + c;
	if (res1 > res2)cout << "A";
	else if (res1 == res2)cout << "T";
	else cout << "B";

}
