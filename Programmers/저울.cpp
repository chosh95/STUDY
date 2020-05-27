#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> weight) {
	int answer = 1;
	sort(weight.begin(), weight.end());
	for (int i = 0; i < weight.size(); i++) {
		if (answer < weight[i]) break;
		answer += weight[i];
	}

	return answer;
}

int main()
{
	cout << solution({ 3,1,6,2,7,30,1 });
}