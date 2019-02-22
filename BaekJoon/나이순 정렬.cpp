#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int N;
vector<pair<int, int>> v; //나이,가입순서,인덱스
string s[100000 + 1];
int main()
{
	cin >> N;
	int tmp;
	for (int i = 1; i <= N; i++) {
		cin >> tmp >> s[i];
		v.push_back(make_pair(tmp, i));
	}
	stable_sort(v.begin(), v.end());
	for (int i = 0; i < N; i++) {
		cout << v[i].first << " " << s[v[i].second] << "\n";
	}
	return 0;
}