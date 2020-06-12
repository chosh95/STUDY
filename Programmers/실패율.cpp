#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int p[501];
vector<pair<double, int>> v; // (실패율, 스테이지)

bool cmp(pair<double, int> a, pair<double, int> b) {
	if (a.first == b.first)
		return a.second > b.second;
	return a.first < b.first;
}
vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	for (int i : stages) 
		p[i]++;
		
	int cnt = stages.size();
	for (int i = 1; i <= N; i++) {
		double ratio = (double)p[i] / (double)cnt;
		if (p[i] == 0) ratio = 0;
		v.push_back({ ratio,i });
		cnt -= p[i];
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = v.size() - 1 ; i >= 0 ;i--)
		answer.push_back(v[i].second);
	
	return answer;
}


int main()
{
	vector<int> ans = solution(5, { 2,1,2,6,2,4,3,3, });
	for (int tmp : ans) 
		cout << tmp << " ";
	
}