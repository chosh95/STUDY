#include <iostream>
using namespace std;

struct Tree {
	int left = 0, right = 0;
};
Tree tree[100001];

void postorder(int n) {
	if (tree[n].left != 0) {
		postorder(tree[n].left);
	}
	if (tree[n].right != 0) {
		postorder(tree[n].right);
	}
	cout << n << "\n";
}

int main()
{
	int root = 0, value = 0;
	scanf_s("%d", &root);
	while (scanf_s("%d", &value) != EOF) {
		int node = root;
		while (true) {
			if (node < value) {
				if (tree[node].right != 0) {
					node = tree[node].right;
				}
				else {
					tree[node].right = value;
					break;
				}
			}
			else {
				if (tree[node].left != 0) {
					node = tree[node].left;
				}
				else {
					tree[node].left = value;
					break;
				}
			}
		}
	}
	postorder(root);
	return 0;
}