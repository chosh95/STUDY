#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool isPossible(long long mid, int n, vector<int> times) {
	long long cnt = 0;
	for (int i = 0; i < times.size(); i++) {
		cnt += (mid / times[i]);
	}
	if (cnt >= n) return true;
	return false;
}

long long solution(int n, vector<int> times) {
	sort(times.begin(), times.end());
	long long lo = 1, hi = ((long long)times[times.size()-1] * (long long)n); //형변환 명시적으로 안해줘서 오류났었다.
	long long answer = hi;
	while (lo <= hi) {
		long long mid = (lo + hi) / 2;
		if (isPossible(mid,n,times)) {
			answer = min(answer, mid);
			hi = mid - 1;
		}
		else {
			lo = mid + 1;
		}
	}
	return answer;
}

int main()
{
	cout << solution(6, { 7,10 });
}