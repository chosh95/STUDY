#include <iostream>
#include <vector>
using namespace std;

int search(int lo, int hi, int w) {
	if (lo > hi) return 0;
	int size = hi - lo + 1;
	int mod = 2 * w + 1;
	int res = size / mod;
	if (size % mod != 0) res++;
	return res;
}

int solution(int n, vector<int> stations, int w)
{
	int answer = 0;

	answer += search(1, stations[0] - w - 1, w);
	for (int i = 1; i <= stations.size() - 1; i++) 
		answer += search(stations[i - 1] + w + 1, stations[i] - w -1, w);
	answer += search(stations[stations.size() - 1] + w + 1, n, w);
	return answer;
}

int main()
{
	cout << solution(16, { 9 }, 2);
	cout << solution(11, { 4,11 }, 1);
}