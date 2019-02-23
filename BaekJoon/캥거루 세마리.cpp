#include <iostream>
using namespace std;
int A, B, C;
int max(int a, int b)
{
	return a < b ? b : a;
}
int main()
{
	cin >> A >> B >> C;
	int tmp = max(B - A, C - B);
	cout << tmp - 1;
}