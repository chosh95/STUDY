#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int N, M;
vector<string> v;
int main()
{
	cin >> N >> M;
	string s;
	for (int i = 0; i < N; i++) {
		cin >> s;
		v.push_back(s);
	}
	sort(v.begin(), v.end());

	vector<string> res;
	for (int i = 0; i < M; i++) {
		cin >> s;
		if (binary_search(v.begin(), v.end(), s)) {
			res.push_back(s);
		}
	}
	sort(res.begin(), res.end());
	cout << res.size() << endl;
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}
	return 0;	
}
