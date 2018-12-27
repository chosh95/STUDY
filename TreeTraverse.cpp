#include <iostream>
using namespace std;

struct Node{
	char name;
	Node* leftchild;
	Node* rightchild;
	Node(char a, char b, char c){
		name = a;
		if(b=='.') leftchild = NULL;
		else leftchild->name = b;
		if(c=='.') rightchild = NULL;
		else rightchild->name = c;
	}
};

class Tree{
	private:
		Node* root;
		Node* currentNode;
	public:
		Tree(char a, char b, char c){
			root = new Node(a,b,c);
			currentNode = root;
		}
		void Insert(char a, char b, char c);
		void Find(char a);
		
		
		void Visit(Node* currentNode){
			cout<<currentNode->name;
		}
		void Preorder(Node* currentNode){
			Visit(currentNode);
			Preorder(currentNode->leftchild);
			Preorder(currentNode->rightchild);
		}
		void Inorder(Node* currentNode){
			Inorder(currentNode->leftchild);
			Visit(currentNode);
			Inorder(currentNode->rightchild);
		}
		void Postorder(Node* currentNode){
			Postorder(currentNode->leftchild);
			Postorder(currentNode->rightchild);
			Visit(currentNode);
		}
};

int main()
{
	int N;
	char node[30][4];
	cin>>N;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=3;j++){
			cin>>node[i][j];
		}
	}
	
	Tree T = new Tree(node[1][1],node[1][2],node[1][3]);
	for(int i=2;i<=N;i++){
		T.Insert(node[i][1],node[i][2],node[i][3]);		
	}
	cout<<T.Preorder()	
	
	
	
	
	
	
	
	
}
