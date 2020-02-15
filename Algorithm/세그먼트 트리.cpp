#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M, K;
int a, b, c;
int p[1000001];
vector<int> range;

int init(int left, int right, int node) {
	//�ܸ������ ��� �� ����
	if (left == right) return range[node] = p[left];
	int mid = (left + right) / 2;
	//node�� ���� ��,�� �ڼյ��� ���� ��
	return range[node] = init(left, mid, node * 2) + init(mid + 1, right, node * 2 + 1);
}

int query(int left, int right, int node, int nodeLeft, int nodeRight) {
	if (nodeRight < left || right < nodeLeft) return 0; //���Ϸ��� ������ ���Ե��� �ʴ� ���
	if (left <= nodeLeft && nodeRight <= right) return range[node]; //������ ������ ���Ե� ���
	int mid = (nodeLeft + nodeRight) / 2;
	//��,�� �ڼյ��� �������� ��� ���� ��ȯ.
	return query(left, right, node * 2, nodeLeft, mid) + query(left, right, node * 2 + 1, mid + 1, nodeRight);
}

void update(int idx, int newValue, int node, int nodeLeft, int nodeRight) {
	if (idx < nodeLeft || nodeRight < idx) return; //�ٲٷ��� idx �������� ���
	if (nodeLeft == nodeRight) { //�ٲٷ��� idx�� �� ���
		range[node] = newValue; //�� ����
		return;
	}
	int mid = (nodeLeft + nodeRight) / 2;
	update(idx, newValue, node * 2, nodeLeft, mid);
	update(idx, newValue, node * 2 + 1, mid + 1, nodeRight);
	range[node] = range[node * 2] + range[node * 2 + 1]; //��,�� �ڼյ��� ���� �ֽ�ȭ���� �� �ٽ� ������ ���
}

int main()
{
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) cin >> p[i];
	range.resize(N * 4);
	init(0, N - 1, 1);
	for (int i = 0; i < M + K; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			update(b - 1, c, 1, 0, N - 1);
		}
		else {
			cout << query(b - 1, c - 1, 1, 0, N - 1) << "\n";
		}
	}
}