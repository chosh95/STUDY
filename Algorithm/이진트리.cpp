#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* leftChild;
	Node* rightChild;
	Node(int d) {
		data = d;
		this->leftChild = NULL;
		this->rightChild = NULL;
	}
};

class Tree {
	private:
		Node* root;
	public:
		Tree(int data) {
			Node* tmp = new Node(data);
			this->root = tmp;
		}
		void traverse() { traverse(root); }
		void add(int data) { add(root, data);}
		void traverse(Node* currentNode);
		void add(Node* currentNode, int data);
};
void Tree::traverse(Node* currentNode) {
	if (currentNode == NULL) return;
	cout << currentNode->data << " ";
	traverse(currentNode->leftChild);
	traverse(currentNode->rightChild);
}

void Tree::add(Node* currentNode, int data) {
	if (currentNode->data <= data)
		if (currentNode->rightChild == NULL) {
			Node* tmp = new Node(data);
			currentNode->rightChild = tmp;
		}
		else
			add(currentNode->rightChild, data);
	else {
		if (currentNode->leftChild == NULL) {
			Node* tmp = new Node(data);
			currentNode->leftChild = tmp;
		}
		else
			add(currentNode->leftChild, data);
	}
}
int main()
{
	Tree t(3);
	t.add(1);
	t.add(0);
	t.add(2);
	t.add(6);
	t.traverse();

}