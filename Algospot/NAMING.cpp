#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

vector<int> getPartialMatch(const string& str)
{
	int m = str.size(), j = 0;
	vector<int> pi(m,0);
	for (int i = 1; i < m; i++) {
		while (j > 0 && str[i] != str[j])
			j = pi[j - 1];
		if (str[i] == str[j])
			pi[i] = ++j;
	}
	return pi;
}

vector<int> getPreffixSuffix(const string& str)
{
	vector<int> res, pi = getPartialMatch(str);
	int k = str.size();
	while (k > 0) {
		res.push_back(k);
		k = pi[k - 1];
	}
	return res;
}

int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	string str = str1 + str2;
	vector<int> res = getPreffixSuffix(str);

	for (int i = res.size()-1; i >= 0; i--) 
		cout << res[i] << " ";

}