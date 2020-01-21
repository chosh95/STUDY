#include <iostream>
#include <string>
#include <list>
using namespace std;
int main()
{
	int N;
	string str;
	cin >> str >> N;
	list<char> li(str.begin(), str.end());
	auto c = li.end();
	while (N--) {
		char cmd;
		cin >> cmd;
		if (cmd == 'L') {
			if (c != li.begin()) c--;
		}
		else if (cmd == 'D') {
			if (c != li.end()) c++;
		}
		else if (cmd == 'B') {
			if (c != li.begin()) {
				auto tmp = c;
				c--;
				li.erase(c);
				c = tmp;
			}
		}
		else if (cmd == 'P') {
			char cmd2;
			cin >> cmd2;
			li.insert(c, cmd2);
		}
	}
	for (char x : li) {
		cout << x;
	}	
}