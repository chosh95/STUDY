#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<int> food_times, long long k) {
	int answer = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	long long sum = 0;
	for (int i = 0; i < food_times.size(); i++) {
		q.push({ food_times[i],i + 1 });
		sum += food_times[i];
	}
	if (sum <= k) return -1;

	int before = 0;
	while ((q.top().first-before)*q.size() <= k) {
		k -= (q.top().first - before) * q.size();
		before = q.top().first;
		q.pop();
	}
	vector<pair<int, int>> origin;
	while (!q.empty()) {
		origin.push_back({ q.top().second, q.top().first });
		q.pop();
	}
	sort(origin.begin(), origin.end());
	answer = origin[k % origin.size()].first;
	return answer;
}

int main()
{
	cout << solution({ 3,1,2 }, 5);
}