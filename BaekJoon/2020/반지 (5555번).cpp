#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string origin;
	int N, res = 0;

	cin >> origin;
	cin >> N;

	while (N--) {
		string tmp;
		cin >> tmp;
		tmp += tmp;
		if (tmp.find(origin) != string::npos)
			res++;
	}

	cout << res;
}
