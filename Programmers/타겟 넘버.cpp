#include <string>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int solution(vector<int> n, int t) {
	int answer = 0;
	queue<pair<int, int>> q;
	q.push({ n[0],0 });
	q.push({ -n[0],0 });
	while (!q.empty()) {
		int x = q.front().first;
		int idx = q.front().second;
		q.pop();
		if (idx == n.size()-1) {
			if (x == t) answer++;
			continue;
		}
		for (int nx : {x + n[idx + 1], x - n[idx + 1]}) {
			q.push({ nx,idx + 1 });
		}
	}

	return answer;
}

int main()
{
	cout << solution({ 1,1,1,1,1 }, 3);
}