#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--) {
		string p, t, tmp;
		int N;
		cin >> p >> N >> t;
		deque<int> d;
		for (int i = 0; i < t.length(); i++) {
			if (t[i] == '[') continue;
			else if (t[i] >= '0' && t[i] <= '9') tmp += t[i];
			else {
				if (!tmp.empty()) {
					d.push_back(stoi(tmp));
					tmp.clear();
				}
			}
		}
		bool dir = true; // true면 정방향 false면 역방향
		bool emp = false;
		for (int i = 0; i < p.length(); i++) {
			if (p[i] == 'R') dir = !dir;
			else {
				if (d.empty()) emp = true;
				if (dir) d.pop_front();
				else d.pop_back();
			}
		}
		if (emp) cout << "error\n";
		else if (dir==true) {
			cout << "[";
			while (!d.empty()) {
				cout << d.front();
				d.pop_front();
				if (!d.empty()) cout << ",";
			}
			cout << "]\n";
		}
		else {
			cout << "[";
			while (!d.empty()) {
				cout << d.back();
				d.pop_back();
				if (!d.empty()) cout << ",";
			}
			cout << "]\n";
		}
	}
}