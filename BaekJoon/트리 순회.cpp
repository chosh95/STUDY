#include <iostream>
using namespace std;
struct Node {
	Node(char a, char b , char c ) {
		this->data = a;
		if (b == '.') this->leftchild = NULL;
		else this->leftchild = new Node(b);
		if (c == '.') this->rightchild = NULL;
		else this->rightchild = new Node(c);
	}
	Node(char a) {
		this->data = a;
		this->leftchild = NULL;
		this->rightchild = NULL;
	}
	char data;
	Node* leftchild;
	Node* rightchild;
};
class Tree {
private:
	Node* root;
	void Preorder(Node *);
	void Inorder(Node *);
	void Postorder(Node *);
	void Insert(Node *, char a, char b, char c);
public :
	Tree(char a, char b, char c) { this->root = new Node(a, b, c); }
	void Insert(char a, char b, char c) { Insert(root, a, b, c); }
	void Preorder() { Preorder(root); }
	void Inorder() { Inorder(root); }
	void Postorder() { Postorder(root); }
};
void Tree::Insert(Node * currentNode, char a, char b, char c) {
	if (currentNode == NULL) currentNode = new Node(a, b, c);
	if (currentNode->data == a){
		currentNode->leftchild = new Node(b);
		currentNode->rightchild = new Node(c);
	}
	else {
		Insert(currentNode->leftchild, a, b, c);
		Insert(currentNode->rightchild, a, b, c);
	}
}
void Tree::Preorder(Node *currentNode) {
	if (currentNode) {
		if(currentNode->data != '.') printf("%c", currentNode->data); 
		Preorder(currentNode->leftchild);
		Preorder(currentNode->rightchild);
	}
}
void Tree::Inorder(Node *currentNode) {
	if (currentNode) {
		Inorder(currentNode->leftchild);
		if (currentNode->data != '.')	printf("%c", currentNode->data);
		Inorder(currentNode->rightchild);
	}
}
void Tree::Postorder(Node *currentNode) {
	if (currentNode) {
		Postorder(currentNode->leftchild);
		Postorder(currentNode->rightchild);
		if (currentNode->data != '.')	printf("%c", currentNode->data);
	}
}

int main()
{
	int N;
	cin >> N;
	char a, b, c;
	cin >> a >> b >> c;
	Tree T(a,b,c);
	for (int i = 2; i <= N; i++) {
		cin >> a >> b >> c;
		T.Insert(a, b, c);
	}
	T.Preorder();
	cout << endl;
	T.Inorder();
	cout << endl;
	T.Postorder();
	cout << endl;
}