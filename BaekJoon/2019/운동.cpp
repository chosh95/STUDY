#include <iostream>
using namespace std;
int N, m, M, T, R;

int main()
{
	cin >> N >> m >> M >> T >> R;
	int totalTime = 0, nTime = 0; // �� �ҿ�ð�, ��ð�
	int heart = m; // ���� ���� �ڵ�
	while (nTime < N) {
		totalTime++;
		if (heart + T <= M) {
			heart += T;
			nTime++;
		}
		else {
			heart -= R;
			if (heart < m) heart = m;
		}
		if (heart + T > M && heart == m) { //��������
			cout << -1;
			return 0;
		}
	}
	cout << totalTime;
	return 0;
}