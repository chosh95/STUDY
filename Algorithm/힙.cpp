#include <iostream>
#include <vector>
using namespace std;

vector<int> Heap;

void push_heap(int value)
{
	Heap.push_back(value);
	int idx = Heap.size() - 1;
	while (idx > 0 && Heap[idx] > Heap[(idx - 1) / 2]) {
		swap(Heap[idx], Heap[(idx - 1) / 2]);
		idx = (idx - 1) / 2;
	}
}

void pop_heap() {
	Heap[0] = Heap.back();
	Heap.pop_back();
	int here = 0;
	while (true) {
		int left = here * 2 + 1, right = here * 2 + 2;
		if (left >= Heap.size()) break;
		int next = here;
		if (Heap[next] < Heap[left])
			next = left;
		if (right < Heap.size() && Heap[next] < Heap[right])
			next = right;
		if (next == here) break;
		swap(Heap[here], Heap[next]);
		here = next;
	}
}

int main()
{
	push_heap(3);
	push_heap(1);
	push_heap(4);
	push_heap(2);
	push_heap(6);
	push_heap(9);
	push_heap(5);
	for (int i = 0; i < Heap.size();i++) {
		cout << Heap[i] << " ";
	}
	cout << endl;

	pop_heap();
	for (int i = 0; i < Heap.size(); i++) {
		cout << Heap[i] << " ";
	}
	cout << endl;

	pop_heap();
	for (int i = 0; i < Heap.size(); i++) {
		cout << Heap[i] << " ";
	}
	cout << endl;

	pop_heap();
	for (int i = 0; i < Heap.size(); i++) {
		cout << Heap[i] << " ";
	}
	cout << endl;
}