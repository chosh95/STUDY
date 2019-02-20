#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <cmath>
#include <vector>
using namespace std;
long long init(vector<long long> &p, vector<long long> &tree, int node, int start, int end)
{
	if (start == end) return tree[node] = p[start];
	else 
		return tree[node] = init(p, tree, node * 2, start, (start + end) / 2) + init(p, tree, node * 2 + 1, (start + end) / 2 + 1, end);
}
long long sum(vector<long long> &tree, int node, int start, int end, int left, int right)
{
	if (left > end || right < start) {
		return 0;
	}
	if (left <= start && end <= right) {
		return tree[node];
	}
	return sum(tree, node * 2, start, (start + end) / 2, left, right) + sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}
void update(vector<long long> &tree, int node, int start, int end, int index, long long diff)
{
	if (index < start || index > end) return;
	tree[node] = tree[node] + diff;
	if (start != end) {
		update(tree, node * 2, start, (start + end) / 2, index, diff);
		update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	}
}

int main()
{
	int N, M, K;
	cin >> N >> M >> K;
	vector<long long> p(N);
	int h = (int)ceil(log2(N)); //트리 높이
	int tree_size = (1 << (h + 1)); // 트리의 최대 노드 개수
	vector<long long> tree(tree_size);
	for (int i = 0; i < N; i++) scanf("%lld",&p[i]);
	init(p, tree, 1, 0, N - 1);
	M += K;
	while (M--) {
		int a;
		scanf("%d", &a);
		if (a == 1) {
			int b;
			long long c;
			scanf("%d %lld", &b, &c);
			b -= 1;
			long long dif = c - p[b];;
			p[b] = c;
			update(tree, 1, 0, N - 1, b, dif);
		}
		else if (a == 2) {
			int b, c;
			scanf("%d %d", &b, &c);
			cout << sum(tree, 1, 0, N - 1, b - 1, c - 1) << endl;
		}
	}
	return 0;
}