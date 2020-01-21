#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int res=0,tmp,minnum=999;
	for (int i = 0; i < 7; i++) {
		cin >> tmp;
		if (tmp % 2 == 1) {
			res += tmp;
			minnum = min(minnum, tmp);
		}
	}
	if (res == 0) cout << -1;
	else cout << res << endl << minnum;
}