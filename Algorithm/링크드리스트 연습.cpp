#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* nextNode;

	Node(int a) {
		this->data = a;
		this->nextNode = NULL;
	}
};

class LinkedList {
	private :
		Node* root;

	public :
		LinkedList() {this->root = NULL;}
		LinkedList(int data) {this->root = new Node(data);}

		void insert(int data);
		void insert(Node* curNode, int data);

		void print();
		void print(Node* curNode);

		void reverse();
		void reverse(Node* curNode);

		void deleteNode(int data);
		void deleteNode(Node* curNode, int data);
};

void LinkedList::insert(int data) {
	insert(root, data);
}

void LinkedList::insert(Node* curNode, int data) {
	if (curNode->nextNode != NULL) {
		insert(curNode->nextNode, data);
	}
	else {
		Node* nextNode = new Node(data);
		curNode->nextNode = nextNode;
	}
}

void LinkedList::reverse() {
	reverse(this->root);
}

void LinkedList::reverse(Node* curNode) {
	if (curNode->nextNode == NULL) {
		this->root = curNode;
		return;
	}
	else {
		reverse(curNode->nextNode);
		curNode->nextNode->nextNode = curNode;
		curNode->nextNode = NULL;
		return;
	}
}

void LinkedList::deleteNode(int data) {
	if (this->root->data == data) {
		Node* dNode = this->root;
		this->root = this->root->nextNode;
		delete(dNode);
		return;
	}
	deleteNode(this->root, data);
}

void LinkedList::deleteNode(Node* curNode, int data) {
	if (curNode->nextNode == NULL) return;
	if (curNode->nextNode->data == data) {
		Node* dNode = curNode->nextNode;
		curNode->nextNode = curNode->nextNode->nextNode;
		delete(dNode);
	}
	else
		deleteNode(curNode->nextNode, data);
}

void LinkedList::print() {
	cout << "=============Node Print=============\n";
	print(root);
	cout << "=============Print Ended============\n";
}

void LinkedList::print(Node* curNode) {
	if (curNode->nextNode != NULL) {
		cout << curNode->data << "->";
		print(curNode->nextNode);
	}
	else
		cout << curNode->data <<"\n";
}

int main()
{
	LinkedList linkedList(1);
	linkedList.insert(2);
	linkedList.insert(3);
	linkedList.print();

	linkedList.reverse();

	linkedList.print();

	linkedList.insert(4);
	linkedList.insert(5);

	linkedList.print();

	linkedList.reverse();
	linkedList.print();

	linkedList.deleteNode(5);
	linkedList.deleteNode(3);
	linkedList.print();
}