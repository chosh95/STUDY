#include <iostream>
#include <string>
#include <set>
using namespace std;
set<string> s;
int N;

int main()
{
	cin >> N;
	string name, log;
	while (N--) {
		cin >> name >> log;
		if (log == "enter") {
			s.insert(name);
		}
		else {
			s.erase(name);
		}
	}
	for (auto iter = s.rbegin(); iter != s.rend(); ++iter) {
		cout << *iter << "\n";
	}
}