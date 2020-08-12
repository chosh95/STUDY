#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> res;

int main()
{
	string A, B;
	cin >> A >> B;
	int i = A.length(), j = B.length();
	for (; i >= 0 && j >= 0; i--,j--) {
		int a = A[i] - '0';
		int b = B[j] - '0';
		res.push_back(a + b);
	}

	while (i >= 0)
		res.push_back(A[i--] - '0');
	while (j >= 0)
		res.push_back(B[j--] - '0');

	for (int i = res.size() - 1; i > 0; i--) {
		cout << res[i];
	}
}