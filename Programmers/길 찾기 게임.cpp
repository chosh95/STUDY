#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

struct Node {
	int x;
	int y;
	int index;
	Node* leftNode;
	Node* rightNode;
};

void insert(Node* parent, Node* child) {
	if (parent->x < child->x) {
		if (parent->rightNode == NULL) parent->rightNode = child;
		else insert(parent->rightNode, child);
	}
	else {
		if (parent->leftNode == NULL) parent->leftNode = child;
		else insert(parent->leftNode, child);
	}
}

vector<Node> Tree;
vector<int> preResult;
vector<int> postResult;

void preorder(Node* cur) {
	if (cur == NULL) return;
	preResult.push_back(cur->index);
	preorder(cur->leftNode);
	preorder(cur->rightNode);
}

void postorder(Node* cur) {
	if (cur == NULL) return;
	postorder(cur->leftNode);
	postorder(cur->rightNode);
	postResult.push_back(cur->index);
}

bool cmp(Node& a, Node& b) {
	if (a.y == b.y)
		return a.x < b.x;
	return a.y > b.y;
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	vector<vector<int>> answer;
	
	for (int i = 0; i < nodeinfo.size(); i++) 
		Tree.push_back({nodeinfo[i][0],nodeinfo[i][1], i + 1 });

	sort(Tree.begin(), Tree.end(),cmp);
	Node* root = &Tree[0];
	
	for (int i = 1; i < Tree.size(); i++) 
		insert(root, &Tree[i]);

	preorder(root);
	postorder(root);

	answer.push_back(preResult);
	answer.push_back(postResult);
	return answer;
}

int main()
{
	vector<vector<int>> ans = solution({ {5,3},{11,5},{13,3},{3,5},{6,1},{1,3},{8,6},{7,2},{2,2} });
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}