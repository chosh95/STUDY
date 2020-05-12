#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	priority_queue<int> pq;
	queue < pair<int, int>> q;

	for (int i = 0; i < priorities.size(); i++) {
		pq.push(priorities[i]);
		q.push({ priorities[i],i });
	}
	
	while (!q.empty()) {
		int x = q.front().first;
		int pos = q.front().second;
		q.pop();
		if (x == pq.top()) {
			pq.pop();
			answer++;
			if (pos == location) break;
		}
		else 
			q.push({ x,pos });
	}

	return answer;
}

int main()
{
	cout << solution({ 2,1,3,2 }, 2) << endl;
	cout << solution({ 1,1,9,1,1,1 }, 0) << endl; 
}