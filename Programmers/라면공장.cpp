#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	int answer = 0;
	priority_queue<pair<int, int>> q;

	for (int idx = 0, day = 0; day < k; day++) {
		stock--;
		if (idx < dates.size() && dates[idx]-1 == day) {
			q.push({ supplies[idx],dates[idx] });
			idx++;
		}
		if (stock == 0 && day != k-1) {
			stock += q.top().first;
			q.pop();
			answer++;
		}
	}

	return answer;
}

int main()
{
	cout << solution(4, { 4,10,15 }, { 20,5,10 }, 30);
}