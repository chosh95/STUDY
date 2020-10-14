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
		Tree() { this->root = NULL; };
		Tree(int data) { this->root = new Node(data);}

		void traverse() { traverse(root); cout << endl; }
		void add(int data);
		void deleteNode(int data) { deleteNode(this->root, data);}

		void traverse(Node* currentNode);
		void add(Node* currentNode, int data);
		Node* deleteNode(Node* currentNode, int data);
		Node* findMax(Node* currentNode);
};

void Tree::traverse(Node* currentNode) {
	if (currentNode == NULL) return;
	cout << currentNode->data << " ";
	traverse(currentNode->leftChild);
	traverse(currentNode->rightChild);
}

void Tree::add(int data) {
	if (this->root == NULL) root = new Node(data);
	else add(this->root, data);
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

Node* Tree::findMax(Node* currentNode) {
	if (currentNode == NULL) return NULL;
	while (currentNode->rightChild != NULL) {
		currentNode = currentNode->rightChild;
	}
	return currentNode;
}

Node* Tree::deleteNode(Node* currentNode, int data) {
	if (currentNode == NULL) return NULL;
	if (data < currentNode->data) currentNode->leftChild = deleteNode(currentNode->leftChild, data);
	else if (data > currentNode->data) currentNode->rightChild = deleteNode(currentNode->rightChild, data);
	else{
		if (currentNode->leftChild == NULL && currentNode->rightChild == NULL){
			delete currentNode;
			return NULL;
		}
		else if (currentNode->leftChild != NULL && currentNode->rightChild != NULL) {
			Node* maxNode = findMax(currentNode->leftChild);
			currentNode->data = maxNode->data;
			currentNode->leftChild = deleteNode(currentNode->leftChild, maxNode->data);
			return currentNode;
		}
		else {
			Node* returnNode = currentNode->leftChild != NULL ? currentNode->leftChild : currentNode->rightChild;
			delete currentNode;
			return returnNode;
		}
	}
	return currentNode;
}

int main()
{
	Tree t;
	t.add(5);
	t.add(3);
	t.add(2);
	t.add(4);
	t.add(8);
	t.add(7);
	t.add(9);
	t.traverse();

	t.deleteNode(5);
	t.traverse();

	
}