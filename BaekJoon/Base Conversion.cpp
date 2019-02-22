#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
vector<int> v;
int main()
{
	int A, B;
	cin >> A >> B;
	int m, tmp, res = 0;
	cin >> m;
	for (int i = m - 1; i >= 0; i--) {
		cin >> tmp;
		res += (tmp*pow(A, i));
	}
	while (res) {
		v.push_back(res%B);
		res /= B;
	}

	reverse(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
}