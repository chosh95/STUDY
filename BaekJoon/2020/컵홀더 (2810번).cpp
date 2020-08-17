#include <iostream>
#include <string>
using namespace std;
int N;

int main()
{
	cin >> N;
	string str;
	cin >> str;
	int res = N + 1;
	int lCnt = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'L') {
			lCnt++;
		}
	}
	if (lCnt == 0) res = N;
	else res -= (lCnt / 2);
	cout << res;
}