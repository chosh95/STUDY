#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int C, N, longest;
int x[101], y[101], r[101];
struct Tree {
	vector<Tree*> children;
};

int sqr(int x) {
	return x * x;
}

int sqrdist(int a, int b) {
	return (sqr(y[a] - y[b]) + sqr(x[a] - x[b]));
}

bool enclose(int a, int b) {
	return r[a] > r[b] && sqrdist(a, b) < sqr(r[a] - r[b]);
}

bool isChild(int parent, int child) {
	if (!enclose(parent, child))
		return false;
	for (int i = 0; i < N; i++) {
		if (i != parent && i != child && enclose(parent, i) && enclose(i, child))
			return false;
	}
	return true;
}

Tree* getTree(int root) {
	Tree* tmp = new Tree();
	for (int i = 0; i < N; i++) {
		if (isChild(root, i)) {
			tmp->children.push_back(getTree(i));
		}
	}
	return tmp;
}

int height(Tree* root) {
	vector<int> heights;
	for (int i = 0; i < root->children.size(); i++)
		heights.push_back(height(root->children[i]));
	if (heights.empty()) return 0;
	sort(heights.begin(), heights.end());
	if (heights.size() >= 2)
		longest = max(longest, 2 + heights[heights.size() - 2] + heights[heights.size() - 1]);
	return heights.back() + 1;
}

int solve(Tree* root) {
	longest = 0;
	int h = height(root);
	return max(longest, h);
}
int main()
{
	cin >> C;
	while (C--) {
		cin >> N;
		for (int i = 0; i < N; i++) 
			cin >> x[i] >> y[i] >> r[i];
		Tree* T = getTree(0);
		cout << solve(T) << endl;
	}
	return 0;
}