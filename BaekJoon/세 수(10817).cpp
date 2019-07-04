#include <iostream>
using namespace std;
int a, b, c;
int main()
{
	cin >> a >> b >> c;
	if (a + b == c) printf("%d+%d=%d", a, b, c);
	else if(a-b==c)printf("%d-%d=%d", a, b, c);
	else if (a * b == c)printf("%d*%d=%d", a, b, c);
	else if (a / b == c)printf("%d/%d=%d", a, b, c);
	else if (a == b + c)printf("%d=%d+%d", a, b, c);
	else if (a == b * c)printf("%d=%d*%d", a, b, c);
	else if (a == b / c)printf("%d=%d/%d", a, b, c);
	else if (a == b - c)printf("%d=%d-%d", a, b, c);
	return 0;
}