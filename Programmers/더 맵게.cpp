#include <string>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int solution(vector<int> v, int K) {
	int answer = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < v.size(); i++)
		pq.push(v[i]);

	while (1) {
		if (pq.top() < K) {
			if (pq.size() < 2) return -1;
			answer++;
			int x = pq.top();
			pq.pop();
			int y = pq.top();
			pq.pop();
			int z = x + y * 2;
			pq.push(z);
		}
		else
			break;
	}

	return answer;
}

int main()
{
	cout << solution({ 1,2,3,9,10,12 }, 7);
}