#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

struct cmp {
	bool operator()(vector<int> a, vector<int> b) {
		return a[1] > b[1];
	}
};


int solution(vector<vector<int>> jobs) {
	int answer = 0;
	priority_queue<vector<int>, vector<vector<int>>, cmp> q;
	sort(jobs.begin(), jobs.end());

	int idx = 0, currentTime = 0;
	while (1) {
		if (idx < jobs.size() && currentTime >= jobs[idx][0]) {
			q.push(jobs[idx]);
			idx++;
			continue;
		}
		if (!q.empty()) {
			currentTime += q.top()[1];
			answer += currentTime - q.top()[0];
			q.pop();
		}
		else
			currentTime = jobs[idx][0];

		if (q.empty() && idx == jobs.size()) break;
	}

	return answer/jobs.size();
}

int main()
{
	cout << solution({ {0,3},{1,9},{2,6} });
}