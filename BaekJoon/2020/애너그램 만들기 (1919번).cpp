#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
string A, B;
int p[30], q[30];

int main()
{
	cin >> A >> B;
	for (int i = 0; i < A.size(); i++) 
		p[A[i] - 'a']++;
	for (int i = 0; i < B.size(); i++)
		q[B[i] - 'a']++;

	int res = 0;
	for (int i = 0; i < 26; i++) {
		res += abs(p[i] - q[i]);
	}
	cout << res;
}