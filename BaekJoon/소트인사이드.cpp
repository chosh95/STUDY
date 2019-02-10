#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	char c[15];
	string s;
	cin >> s;
	int N = s.length();
	for (int i = 0; i < N; i++) c[i] = s[i];
	sort(c, c + N,cmp);
	for (int i = 0; i < N; i++) cout << c[i];
}