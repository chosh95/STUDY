#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> v, int M) {
	long long answer = 1;
	long long lo = 1, hi = 100000;
	long long mid = 50000;
	long long sum = 0;

	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) 
		sum += v[i];
	if (sum <= M) return v[v.size() - 1];

	while (lo <= hi) {
		mid = (lo + hi) / 2;
		sum = 0;

		for (int i = 0; i < v.size(); i++) {
			if (v[i] < mid) sum += v[i];
			else sum += mid;
		}

		if (sum > M) {
			hi = mid-1;
		}
		else {
			answer = max(answer, mid);
			lo = mid+1;
		}
	}

	return answer;
}

int main()
{
	cout << solution({1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, 56);
}