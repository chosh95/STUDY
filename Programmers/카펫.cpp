#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int brown, int yellow) {
	vector<int> answer;
	
	for (int i = 1; i <= 2500; i++) {
		for (int j = i; j <= 2000; j++) {
			int tmpB = (i + j - 2) * 2;
			int tmpY = (i * j) - tmpB;
			if (tmpB == brown && tmpY == yellow) {
				answer.push_back(j);
				answer.push_back(i);
				return answer;
			}
		}
	}
}

int main()
{
	cout << solution(5000,2000000)[0] << " " << solution(5000, 2000000)[1];
}