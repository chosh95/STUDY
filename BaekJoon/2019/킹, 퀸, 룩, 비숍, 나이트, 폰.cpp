#include <iostream>
using namespace std;
int res[6] = { 1,1,2,2,2,8 };
int p[6];
int main()
{
	for (int i = 0; i < 6; i++) {
		cin >> p[i];
		cout << res[i] - p[i] << " ";
	}
}