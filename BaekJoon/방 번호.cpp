#include <iostream>
#include <string>
using namespace std;
int arr[11];
int main()
{
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		arr[s[i] - '0']++;
	}
	arr[6] += arr[9];
	arr[6] = (arr[6] / 2 + arr[6] % 2);
	int max = 0;
	for (int i = 0; i <= 8; i++) if (arr[i] > max) max = arr[i];
	cout << max;
}