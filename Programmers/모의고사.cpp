#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answer) {
	vector<int> res;
	vector<int> ap = { 1,2,3,4,5 }; // size = 5
	vector<int> bp = { 2, 1, 2, 3, 2, 4, 2, 5 }; // size = 8
	vector<int> cp = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 }; // size = 10
	int a = 0, b = 0, c = 0;
	for (int i = 0; i < answer.size(); i++) {
		if (answer[i] == ap[i % 5]) a++;
		if (answer[i] == bp[i % 8]) b++;
		if (answer[i] == cp[i % 10]) c++;
	}
	//cout << a << " " << b << " " << c;
	vector<pair<int, int>> tmp = {{a,1},{b,2},{c,3}};
	sort(tmp.begin(), tmp.end());
	res.push_back(tmp[2].second);
	if (tmp[2].first == tmp[1].first) {
		res.push_back(tmp[1].second);
		if (tmp[1].first == tmp[0].first)
			res.push_back(tmp[0].second);
	}
	sort(res.begin(), res.end());
	return res;
}

int main()
{
	vector<int> res = solution({ 1,3,2,4,2 });
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
}