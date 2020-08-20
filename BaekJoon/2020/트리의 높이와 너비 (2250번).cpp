#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N;
int minLevel[10001]; // 해당 레벨에서 최소 열
int maxLevel[10001]; // 해당 레벨에서 최대 열
int cur = 1; // inorder할 때 열을 기록해줄 변수
int levelCnt; // 최대 레벨을 기록하는 변수

int leftChild[10001]; // i번 노드의 왼쪽 자식
int rightChild[10001]; // i번 노드의 오른쪽 자식
int parentNum[10001]; // i번 노드의 부모 노드

struct Node {
	int data; 
	int level;
	Node* leftNode;
	Node* rightNode;
	Node(int data, int level, int left, int right) { //생성자
		this->data = data;
		this->level = level;

		levelCnt = max(level, levelCnt);

		if (left == -1) this->leftNode = NULL;
		else this->leftNode = new Node(left, level + 1, -1 , -1);

		if (right == -1) this->rightNode = NULL;
		else this->rightNode = new Node(right, level + 1, -1, -1);
	}
};

class Tree {
	Node* root;

	public:
		Tree(int parent, int left, int right) { // 트리 생성자
			this->root = new Node(parent, 1, left, right);
		}

		void insert(int parent, int left, int right) { // insert의 helper 함수
			insert(root, parent, left, right);
		}

		void insert(Node* currentNode, int parent, int left, int right) { // 트리에 노드 삽입하는 함수
			if (currentNode == NULL) return;
			if (currentNode->data == parent) { // 삽입할 노드를 찾았으면 left, right 생성
				if (left == -1) currentNode->leftNode = NULL;
				else currentNode->leftNode = new Node(left, currentNode->level + 1, -1, -1);
				if (right == -1) currentNode->rightNode = NULL;
				else currentNode->rightNode = new Node(right, currentNode->level + 1, -1, -1);
			}
			else { // 삽입할 곳을 찾아 재귀 호출
				insert(currentNode->leftNode, parent, left, right);
				insert(currentNode->rightNode, parent, left, right);
			}
		}

		void inorder() { //inorder의 helper 함수
			inorder(root);
		}

		void inorder(Node* currentNode) { // 중위순회
			if (currentNode == NULL) return;

			inorder(currentNode->leftNode); // left 방문

			minLevel[currentNode->level] = min(minLevel[currentNode->level], cur); // 현재 방문
			maxLevel[currentNode->level] = max(maxLevel[currentNode->level], cur); // 현재 레벨의 최소, 최대 열을 기록한다.
			cur++; // 열 증가

			inorder(currentNode->rightNode); // right 방문
		}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		minLevel[i] = 987654321; // min배열 최대값으로 초기화
		maxLevel[i] = 0;
	}

	for (int a, b, c, i = 1; i <= N; i++) {
		cin >> a >> b >> c;
		leftChild[a] = b; //a의 left, rightChild 기록
		rightChild[a] = c;
		if (b != -1) parentNum[b] = a; // b, c가 NULL이 아니면 a가 부모노드
		if (c != -1) parentNum[c] = a;
	}
	
	int rootNum = 0; // root 노드가 몇번인지 검색
	for (int i = 1; i <= N; i++) {
		if (parentNum[i] == 0) {
			rootNum = i;
			break;
		}
	}

	queue<int> q; // 트리에 삽입할 노드를 차례대로 저장하는 큐
	Tree t(rootNum, leftChild[rootNum], rightChild[rootNum]); //루트 노드를 이용해 트리 생성
	if (leftChild[rootNum] != -1) q.push(leftChild[rootNum]); // left, right가 NULL이 아니면 삽입
	if (rightChild[rootNum] != -1) q.push(rightChild[rootNum]);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		t.insert(cur, leftChild[cur], rightChild[cur]); // left, right를 cur에 삽입
		if (leftChild[cur] != -1) q.push(leftChild[cur]); // 다음에 삽입할 노드 삽입
		if (rightChild[cur] != -1) q.push(rightChild[cur]);
	}

	t.inorder(); // 중위 순회

	int resLevel = 1, resWidth = 1; // 결과 레벨, 너비
	for (int i = 1; i <= levelCnt; i++) {
		if (resWidth < maxLevel[i] - minLevel[i] + 1) {
			resWidth = maxLevel[i] - minLevel[i] + 1;
			resLevel = i;
		}
	}

	cout << resLevel << " " << resWidth;
}
