#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int N;
vector<string> v;

bool cmp(string a, string b) {
	if (a.size() != b.size()) return a.size() < b.size();
	else{
		int num1 = 0, num2 = 0;
		for (int i = 0; i < a.size(); i++) {
			if (a[i] >= '0' && a[i] <= '9')
				num1 += (a[i] - '0');
			if (b[i] >= '0' && b[i] <= '9')
				num2 += (b[i] - '0');
		}
		if (num1 != num2) return num1 < num2;
		
		return a < b;
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		v.push_back(str);
	}

	sort(v.begin(), v.end(), cmp);

	for (string str : v) {
		cout << str << "\n";
	}
}