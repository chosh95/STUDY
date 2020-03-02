#include <iostream>
using namespace std;
int E, S, M;

int main()
{
	int res = 0;
	cin >> E >> S >> M;
	for (int i = 1; ; i++) {
		if ( (i-E)%15 == 0 && (i-S)%28 == 0 && (i-M)%19 == 0){
			res = i;
			break;
		}
	}
	cout << res;
}