#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

vector<int> selection_sort(const vector<int> input) {
	vector<int> v = input;
	for (int i = 0; i < v.size()-1; i++) {
		int tmp = i;
		for (int j = i + 1; j < v.size(); j++) {
			if (v[tmp] >= v[j]) tmp = j;
		}
		swap(v[i], v[tmp]);
	}
	return v;
}

vector<int> bubble_sort(const vector<int> input) {
	vector<int> v = input;
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v.size()-i-1; j++) {
			if (v[j] > v[j+1]) swap(v[j], v[j+1]);
		}
	}
	return v;
}

vector<int> insertion_sort(const vector<int> input) {
	vector<int> v = input;
	for (int i = 1; i < v.size(); i++) {
		int key = v[i], j = i - 1;
		while (j >= 0 && key < v[j]) {
			swap(v[j], v[j+1]);
			j--;
		}
		v[j + 1] = key;
	}
	return v;
}

vector<int> merge(const vector<int> input, int start, int end, int med) {
	vector<int> v = input;
	vector<int> tmp;
	int i = start, j = med + 1;

	while (i <= med && j <= end) {
		if (v[i] < v[j]) tmp.push_back(v[i++]);
		else if (v[i] > v[j]) tmp.push_back(v[j++]);
	}

	while (i <= med) tmp.push_back(v[i++]);
	while (j <= end) tmp.push_back(v[j++]);

	for (int a = 0, b = start; b <= end; b++) {
		v[b] = tmp[a++];
	}
	return v;
}

vector<int> merge_sort(const vector<int> input, int start, int end) {
	vector<int> v = input;
	if (start < end) {
		int med = (start + end) / 2;
		v = merge_sort(v, start, med);
		v = merge_sort(v, med + 1, end);
		v = merge(v, start, end, med);
	}
	return v;
}

vector<int> quick_sort(const vector<int> input, int start, int end) {
	vector<int> v = input;
	if (start >= end) return v;
	int pivot = start, left = start + 1, right = end;
	while (left <= right) {
		while (left <= end && v[left] <= v[pivot]) left++;
		while (right > start && v[right] >= v[pivot]) right--;
		if (left > right) swap(v[pivot], v[right]);
		else swap(v[left], v[right]);
	}
	v = quick_sort(v, start, right - 1);
	v = quick_sort(v, right + 1, end);
	return v;
}
int main()
{
	vector<int> input;
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 100; i++) {
		input.push_back(rand() % 10000 + 1);
	}

	cout << "selection sort\n";
	vector<int> res;
	res = selection_sort(input);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << endl << endl;

	cout << "bubble sort\n";
	res = bubble_sort(input);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << endl << endl;

	cout << "insertion sort\n";
	res = insertion_sort(input);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << endl << endl;

	cout << "merge sort\n";
	res = merge_sort(input,0,input.size()-1);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << endl << endl;

	cout << "quick sort\n";
	res = quick_sort(input, 0, input.size() - 1);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << endl << endl;
}