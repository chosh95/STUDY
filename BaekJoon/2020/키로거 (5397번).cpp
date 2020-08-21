#include <iostream>
#include <list>
#include <string>
#include <algorithm>
using namespace std;
int N;

int main()
{
	cin >> N;
	while (N--) {
		string str;
		list<char> res;
		cin >> str;
		auto iter = res.begin();

		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '<') {
				if (iter != res.begin()) iter--;
			}
			else if (str[i] == '>') {
				if (iter != res.end()) iter++;
			}
			else if (str[i] == '-') {
				if (!res.empty() && iter != res.begin())
					iter = res.erase(--iter);
			}
			else {
				res.insert(iter,str[i]);
			}
		}
		for (auto it = res.begin(); it != res.end(); it++)
			cout << *it;
		cout << "\n";
		res.clear();
	}
}