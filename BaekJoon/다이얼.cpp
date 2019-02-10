#include <iostream>
#include <string>
using namespace std;
int main()
{
	int arr[30] = { 3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10 };
	string s;
	cin >> s;
	int count = 0;
	for (int i = 0; i < s.length(); i++) {
		count += arr[s[i] - 'A'];
	}
	cout << count;
}
