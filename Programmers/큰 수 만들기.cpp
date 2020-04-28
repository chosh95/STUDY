#include <string>
#include <iostream>
#include <vector>
using namespace std;

string solution(string number, int k) {
	string answer = "";
	int cur = 0;
	for (int i = 0; i < number.size()-k; i++) {
		char maxNum = number[cur];
		int maxIdx = cur;
		for (int j = cur; j <= k + i; j++) {
			if (maxNum < number[j]) {
				maxNum = number[j];
				maxIdx = j;
			}
		}
		cur = maxIdx + 1;
		answer += number[maxIdx];
	}
	return answer;
}

int main()
{
	cout << solution("4177252841", 4);
}