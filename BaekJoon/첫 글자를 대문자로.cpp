#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N;
	cin >> N;
	cin.ignore();
	int u = 'a'-'A';
	for (int i = 0; i < N; i++) {
		string str;
		getline(cin, str);
		if (str[0] >= 'Z') str[0] -= u;
		cout << str << "\n";
	}
}