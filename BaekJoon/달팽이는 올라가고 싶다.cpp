#include <iostream>
#include <algorithm>
using namespace std;
int A, B, V;
int main()
{
	cin >> A >> B >> V;
	int res = (V - B - 1) / (A - B) + 1;
	cout << res;
}