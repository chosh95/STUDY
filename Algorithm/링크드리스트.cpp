#include <iostream>
using namespace std;

class Node {
	private:
		Node* next;
		int num;
	public:
		Node(int n) : num(n) { next = NULL; }
		friend class linkedList;//friend 선언이 번거로우면 struct로 선언할 것.
};

class linkedList {
	private:
		Node* head;
		Node* tail;

	public:
		int size;
		linkedList(int);
		void pushBack(int);
		void deleteNode(int);
		void show();
		void popFront();
		void popBack();
		void insert(int, int);
		int Size() { return this->size; }
};

linkedList::linkedList(int n){
	head = tail = new Node(n);
	size = 1;
}
void linkedList::pushBack(int n) {
	Node* tmp = new Node(n);
	if (head == NULL) head = tail = tmp;
	else tail->next = tmp;
	tail = tmp;
	size++;
}
void linkedList::deleteNode(int value) {
	Node* tmp = head;
	Node* tmp2 = head;
	while (tmp2 != NULL) {
		if (tmp2->num == value) break;
		else {
			tmp = tmp2;
			tmp2 = tmp2->next;
		}
	}
	if (tmp2 == NULL) cout << value << "값을 갖는 노드가 없습니다.\n";
	else {
		tmp->next = tmp2->next;
		delete tmp2;
		size--;
	}
}
void linkedList::show() {
	if (head == NULL) cout << "Empty\n";
	else {
		Node* tmp = head;
		for (int i = 1; i <= size; i++) {
			cout << tmp->num << " -> ";
			tmp = tmp->next;
		}
		cout << "사이즈는 : " <<size<<"입니다.\n";
	}
}
void linkedList::popFront() {
	Node* tmp = head;
	head = head->next;
	delete tmp;
	size--;
}
void linkedList::popBack() {
	Node* tmp = head;
	Node* tmp2 = head;
	while (tmp2->next != NULL) {
		tmp = tmp2;
		tmp2 = tmp2->next;
	}
	size--;
	tail = tmp;
	tmp->next = NULL;
	delete tmp2;
}
//idx위치에 value 값을 갖는 노드를 삽입
void linkedList::insert(int idx, int value) {
	Node* tmp = head;
	int cnt = 1;
	while (true) {
		if (cnt == idx) {
			Node* newNode = new Node(value);
			newNode->next = tmp->next;
			tmp->next = newNode;
			break;
		}
		else {
			cnt++;
			tmp = tmp->next;
		}
	}
	size++;
}
int main()
{
	//정적할당
	linkedList list(1);
	list.pushBack(2);
	list.pushBack(3);
	list.pushBack(4);
	list.pushBack(5);
	list.show();

	list.popFront();
	list.insert(1, 10);
	list.popBack();
	list.show();

	list.deleteNode(4);
	list.deleteNode(50);
	list.show();

	//동적할당
	linkedList* list2 = new linkedList(10);
	list2->pushBack(20);
	list2->pushBack(30);
	list2->pushBack(40);
	list2->show();
}