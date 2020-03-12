#include <iostream>
#include <string>
#include <queue>
using namespace std;
int N;
string str;
int input;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	queue<int> q;
	while (N--) {
		cin >> str;
		if (str == "push") {
			cin >> input;
			q.push(input);
		}
		else if (str == "size") {
			cout << q.size() << "\n";
		}
		else if (str == "front") {
			if (q.empty()) cout << "-1\n";
			else cout << q.front() << "\n";
		}
		else if (str == "pop") {
			if (q.empty()) cout << "-1\n";
			else {
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (str == "empty") {
			if (q.empty()) cout << "1\n";
			else cout << "0\n";
		}
		else if (str == "back") {
			if (q.empty()) cout << "-1\n";
			else cout << q.back() << "\n";
		}
	}
}