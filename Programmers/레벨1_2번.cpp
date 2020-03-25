#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
	vector<long long> answer;
	for (int i = 1; i <= n; i++) {
		long long tmp = (long long)x + (i - 1) * (long long)x;
		answer.push_back(tmp);
	}
	return answer;
}

int main()
{
	vector<long long> tmp = solution(-10000000, 1000);
	for (int i = 0; i < tmp.size(); i++)
		cout << tmp[i] << " ";
}