#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	for (int i = 0; i < commands.size(); i++) {
		int a = commands[i][0];
		int b = commands[i][1];
		int k = commands[i][2];
		vector<int> sub = vector<int>(array.begin() + a - 1, array.begin() + b);
		sort(sub.begin(), sub.end());
		answer.push_back(sub[k-1]);
	}
	return answer;
}

int main()
{
	vector<int> v = solution({ 1,5,2,6,3,7,4 }, { {2,5,3},{4,4,1},{1,7,3} });
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
}