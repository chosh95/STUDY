#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int C, N;

vector<int> slice(const vector<int>& v, int a, int b) {
	return vector<int>(v.begin() + a, v.begin() + b);
}

void printPostorder(const vector<int>& preorder, const vector<int>& inorder) {
	const int vsize = preorder.size();
	if (preorder.empty()) return;
	const int root = preorder[0];
	const int L = find(inorder.begin(), inorder.end(), root) - inorder.begin();
	const int R = vsize - 1 - L;

	printPostorder(slice(preorder, 1, L + 1), slice(inorder, 0, L));
	printPostorder(slice(preorder, L + 1, vsize), slice(inorder, L + 1, vsize));
	cout << root << " ";
	return;
}

int main()
{
	cin >> C;
	while (C--) {
		cin >> N;
		vector<int> preorder;
		vector<int> inorder;
		for (int tmp, i = 0; i < N; i++) {
			cin >> tmp;
			preorder.push_back(tmp);
		}
		for (int tmp, i = 0; i < N; i++) {
			cin >> tmp;
			inorder.push_back(tmp);
		}		
		printPostorder(preorder, inorder);
		cout << endl;
	}
}
