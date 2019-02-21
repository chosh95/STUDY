#include <iostream>
#include <string>
using namespace std;
int main()
{
	int p[27];
	int N;
	cin >> N;
	int count = 0;
	bool tmp = true;
	for (int i = 1; i <= N; i++) {
		string s;
		cin >> s;
		tmp = true;
		for (int i = 0; i <= 26; i++) p[i] = 0;
		p[s[0] - 'a'] = 1;
		for (int i = 1; i < s.length(); i++) {
			int a = s[i] - 'a';
			p[a]++;
			if (s[i] != s[i - 1] && p[a] > 1) {
				tmp = false;
				break;
			}
		}
		if (tmp) count++;
	}
	cout << count;
}