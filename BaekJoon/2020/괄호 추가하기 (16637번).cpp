#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int N;
int num[20];
char op[20];
int numCnt, opCnt;
int res = -987654321;

int cal(int num1, int num2, char oper) {
	if (oper == '+')
		return num1 + num2;
	else if (oper == '-')
		return num1 - num2;
	else
		return num1 * num2;
}

void dfs(int sum, int idx) {
	if (idx >= opCnt) {
		res = max(res, sum);
		return;
	}

	//괄호 안씌우고 앞에 두 숫자 계산
	int cur = cal(sum, num[idx + 1], op[idx]);
	dfs(cur, idx + 1);

	//괄호를 뒤의 숫자 두 개에 씌우기 
	//ex) a * b + c -> a * (b + c)
	if (idx + 1 < opCnt) {
		int tmp = cal(num[idx + 1], num[idx + 2], op[idx + 1]);
		int next = cal(sum, tmp, op[idx]);
		dfs(next, idx + 2);
	}
}

int main()
{
	string str;
	cin >> N;
	cin >> str;

	for (int i = 0; i < N; i++) {
		if (i % 2 == 0) num[numCnt++] = str[i] - '0';
		else op[opCnt++] = str[i];
	}

	dfs(num[0], 0);

	cout << res;
}