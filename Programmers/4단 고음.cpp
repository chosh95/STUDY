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

// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
int solution(int n) {
	return dfs(n - 2, 2);
}
