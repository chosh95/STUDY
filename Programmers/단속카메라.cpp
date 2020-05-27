#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int visit[10001];

bool isTrue(int n) {
	for (int i = 0; i < n; i++)
		if (visit[i] == 0) return false;
	return true;
}

int solution(vector<vector<int>> routes) {
	int answer = 0;
	vector<pair<int, int>> v;
	int rSize = routes.size();
	for (int i = 0; i < rSize; i++) 
		v.push_back({ routes[i][1],i });
	sort(v.begin(), v.end());

	for (int i = 0; i < rSize; i++) {
		if (isTrue(rSize)) break;
		int y = v[i].first;
		int idx = v[i].second;
		if (visit[idx] == 1) continue;
		for (int j = 0; j < rSize; j++) {
			if (visit[j] == 1) continue;
			if (routes[j][0] <= y && y <= routes[j][1]) visit[j] = 1;
		}
		answer++;
	}

	return answer;
}

int main()
{
	cout << solution({ {-20,-15},{-14,-5},{-18,-13},{-5,-3} });
}