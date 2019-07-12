#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int N;
vector<string> v;

int main()
{
	cin >> N;
	string tmp;
	for (int i = 1; i <= N; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	for (int i = 0; i < v.size() - 1; i++) {
		tmp = v[i];
		reverse(tmp.begin(), tmp.end());
		for (int j = i; j < v.size(); j++) {
			if (tmp == v[j]) {
				cout << tmp.length() << " " << tmp[tmp.length() / 2];
				return 0;
			}
		}
	}
}