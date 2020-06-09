#include <cmath>
#include <stdio.h>

int dfs(int n, int nPlus) {
	int result = 0;

	if (n < 1 || 2 * log(n) / log(3) < nPlus) {
		return 0;
	}
	else if (n == 3 && nPlus == 2) {
		return 1;
	}
	else if (n == 3 && nPlus == 3) {
		return 0;
	}

	if (n % 3 == 0 && nPlus >= 2) {
		result += dfs(n / 3, nPlus - 2);
	}
	result += dfs(n - 1, nPlus + 1);

	return result;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n) {
	return dfs(n - 2, 2);
}
