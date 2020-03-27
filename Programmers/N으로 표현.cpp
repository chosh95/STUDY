#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int res = 9;

//cnt : N �� Ƚ��, sum : ������� ���� ��
void dfs(int N, int target, int cnt, int sum) {
	if (cnt > 8) return;
	if (sum == target) {
		res = min(cnt, res);
		return;
	}

	int tmp = 0;
	for (int i = 1; i <= 8; i++) {
		tmp = tmp * 10 + N;
		dfs(N, target, cnt + i, sum + tmp);
		dfs(N, target, cnt + i, sum - tmp);
		dfs(N, target, cnt + i, sum * tmp);
		if(sum != 0) dfs(N, target, cnt + i, sum / tmp);
	}
}

int solution(int N, int number) {
	int answer = 0;
	dfs(N, number, 0, 0);
	
	if (res == 9) answer = -1;
	else answer = res;
	return answer;
}

int main()
{
	cout << solution(5, 16);
}