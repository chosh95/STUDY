#include <iostream> // ±ÍÂúÀº Çì´õµé
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
char p[20001][51];
vector<string> v;
bool cmp(const string &s1, const string &s2) {
	if (s1.size() == s2.size()) {
		return s1 < s2;
	}
	return s1.size() < s2.size();
}


int main()
{
	string s;
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> s;
		v.push_back(s);
	}
	vector<string>::iterator iter;
	vector<string>::iterator end_iter;
	sort(v.begin(),v.end(),cmp);
	end_iter = unique(v.begin(), v.end());
	for (iter = v.begin();iter!=end_iter; iter++){
		cout << *iter << endl;
	}
}