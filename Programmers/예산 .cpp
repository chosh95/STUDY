#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> d, int budget) {
	int answer = 0;
	sort(d.begin(), d.end());
	int sum = 0;
	for (int i = 0; i < d.size(); i++) {
		if (sum + d[i] <= budget) {
			sum += d[i];
			answer++;
		}
	}
	return answer;
}

int main()
{
	cout << solution({ 2,2,3,3 }, 10);
}