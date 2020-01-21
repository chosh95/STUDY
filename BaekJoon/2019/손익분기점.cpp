#include <iostream>
using namespace std;
int A, B, C;
int main()
{
	cin >> A >> B >> C;
	int tmp = -1;
	if (B < C) tmp = A / (C - B) + 1;
	cout << tmp;

}