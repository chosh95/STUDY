#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int n = s.size();
	vector<string> v;

	for (int i = 0; i < n; i++) {
		v.push_back(s.substr(i, n));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) 
		cout << v[i] << "\n";
	
}