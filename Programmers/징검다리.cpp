#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool isPossible(int mid, int distance, vector<int> rocks, int n) {
	int last = -1, dist = 0, cnt = 0;
	for(int i=0;i<rocks.size();i++){
		if (last == -1)
			dist = rocks[i];
		else if (i == rocks.size())
			dist = distance - rocks.back();
		else
			dist = rocks[i] - rocks[last];

		if (dist < mid)
			cnt++;
		else
			last = i;
	}

	if (cnt <= n) return true;
	return false;
}

int solution(int distance, vector<int> rocks, int n) {
	int answer = 0;
	int lo = 0, hi = distance;
	sort(rocks.begin(), rocks.end());
	while (lo <=hi) {
		int mid = (lo + hi) / 2;
		if (isPossible(mid, distance, rocks, n))
			lo = mid + 1;
		else
			hi = mid - 1;
	}
	answer = hi;
	return answer;
}

int main()
{
	cout << solution(25, { 2,14,11,21,17 }, 2);
}