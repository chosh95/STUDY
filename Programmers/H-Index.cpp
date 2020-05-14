#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
	int answer = 0;
	int csize = citations.size();
	sort(citations.begin(), citations.end());
	for (int h = 0; h <= csize; h++) {
		int cnt = 0;
		for (int j = csize-1; j >=0; j--) {
			if (citations[j] >= h) cnt++;
			else break;
		}
		if (cnt >= h) {
			answer = h;
		}
	}
	return answer;
}

int main()
{
	cout << solution({ 5,5,5,5 });
}