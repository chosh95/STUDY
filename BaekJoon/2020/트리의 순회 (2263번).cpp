#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<int> inOrder, postOrder;
int pos[100001]; // inOrder의 각 값의 위치
struct Node {
	int data;
	Node* leftNode;
	Node* rightNode;
	Node() {
		data = -1;
		leftNode = NULL;
		rightNode = NULL;
	}
};

Node* makeTree(int inStart, int inEnd, int poStart, int poEnd) {
	if (inStart > inEnd || poStart > poEnd) return NULL;
	Node* cur = new Node();
	cur->data = postOrder[poEnd];

	int rootPos = pos[cur->data];
	cur->leftNode = makeTree(inStart, rootPos - 1, poStart, poStart + (rootPos - inStart) - 1);
	cur->rightNode = makeTree(rootPos + 1, inEnd, poStart + (rootPos - inStart), poEnd - 1);

	return cur;	
}

void preOrder(Node* cur) {
	if (cur == NULL) return;
	cout << cur->data << " ";
	preOrder(cur->leftNode);
	preOrder(cur->rightNode);
}

int main()
{
	cin >> N;
	for (int tmp, i = 1; i <= N; i++) {
		cin >> tmp;
		inOrder.push_back(tmp);
	}
	for (int tmp, i = 1; i <= N; i++) {
		cin >> tmp;
		postOrder.push_back(tmp);
	}
	for (int i = 0; i < N; i++)
		pos[inOrder[i]] = i;
	Node *root;
	root = makeTree(0, N - 1, 0, N - 1);

	preOrder(root);
}