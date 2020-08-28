#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, S;
int p[100001];
int res = 9987654321;
vector<int> v;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main()
{
	cin >> N >> S;

	for (int i = 1; i <= N; i++) {
		cin >> p[i];
		v.push_back(abs(S - p[i]));
	}

	int res = v[0];
	for (int i = 0; i < v.size(); i++) {
		res = gcd(res, v[i]);
	}

	cout << res;
	
}