#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;
	string str(n, ' ');
	for (int i = 0; i < n; i++) 
		answer.push_back(str);


	for (int i = 0; i < n; i++) {
		int mok = 0, mod = 0;
		int cur = arr1[i];
		int idx = n - 1;
		while (cur != 0) {
			mod = cur % 2;
			cur = cur / 2;
			if (mod == 1)
				answer[i][idx] = '#';
			idx--;
		}
	}

	for (int i = 0; i < n; i++) {
		int mok = 0, mod = 0;
		int cur = arr2[i];
		int idx = n - 1;
		while (cur != 0) {
			mod = cur % 2;
			cur = cur / 2;
			if (mod == 1)
				answer[i][idx] = '#';
			idx--;
		}
	}
	return answer;
}

int main()
{
	vector<string> res = solution(5, { 9,20,28,18,11 }, { 30,1,21,17,28 });
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << endl;
}