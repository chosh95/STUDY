#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int C, N;

vector<int> getPi(const string& str) {
	int m = str.size(), j = 0;
	vector<int> pi(m, 0);
	for (int i = 1; i < m; i++) {
		while (j > 0 && str[i] != str[j])
			j = pi[j - 1];
		if (str[i] == str[j])
			pi[i] = ++j;
	}
	return pi;
}

vector<int> kmp(const string& A, const string& B) {
	int n = A.size(), m = B.size(), j = 0;
	vector<int> res;
	vector<int> pi = getPi(B);
	for (int i = 0; i < n; i++) {
		while (j > 0 && A[i] != B[j])
			j = pi[j - 1];
		if (A[i] == B[j]) {
			if (j == m - 1) res.push_back(i - m + 1);
			else j++;
		}
	}
	return res;
}

int main()
{
	cin >> C;
	while (C--) {
		int res = 0;
		vector<string> str;
		cin >> N;
		string tmp;
		for (int i = 0; i <= N; i++) {			
			cin >> tmp;
			str.push_back(tmp);
		}
		for (int i = 0; i < N; i++) {
			if (i % 2 == 1)
				res += kmp(str[i] + str[i], str[i + 1])[0];
			else
				res += kmp(str[i + 1] + str[i + 1], str[i])[0];
		}
		cout << res << endl;
	}
}