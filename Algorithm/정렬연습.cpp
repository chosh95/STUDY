#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> bubble_sort(vector<int> arr) {

	for (int i = 0; i < arr.size(); i++) {
		for (int j = i + 1; j < arr.size(); j++) {
			if (arr[i] > arr[j])
				swap(arr[i], arr[j]);
		}
	}
	return arr;
}

vector<int> insertion_sort(vector<int> arr) {

	for (int i = 1; i < arr.size(); i++) {
		int key = arr[i];
		int j = i;
		while(j>0 && arr[j-1] > key){
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = key;
	}
	return arr;
}

vector<int> selection_sort(vector<int> arr) {

	for (int i = 0; i < arr.size(); i++) {
		int idx = i;
		for (int j = i; j < arr.size(); j++) {
			if (arr[idx] > arr[j])
				idx = j;
		}
		swap(arr[i], arr[idx]);
	}

	return arr;
}

vector<int> merge(vector<int> arr, int left, int mid, int right) {
	int i = left, j = mid+1, idx = left;
	vector<int> result(arr.size());

	while (i <= mid && j <= right) {
		if (arr[i] < arr[j]) result[idx++] = arr[i++];
		else result[idx++] = arr[j++];
	}
	while (i <= mid)
		result[idx++] = arr[i++];
	while (j <= right)
		result[idx++] = arr[j++];

	for (int i = left; i <= right; i++)
		arr[i] = result[i];

	return arr;
}

vector<int> merge_sort(vector<int> arr, int left, int right) {
	if (left >= right) return arr;

	int mid = (left + right) / 2;
	arr = merge_sort(arr, left, mid);
	arr = merge_sort(arr, mid + 1, right);
	arr = merge(arr,left,mid,right);

	return arr;
}

vector<int> quick_sort(vector<int> arr, int left, int right) {
	if (left >= right) return arr;

	int pivot = left, start = left + 1, end = right;
	while (start <= end) {
		while (start <= right&& arr[pivot] >= arr[start]) start++;
		while (end > left && arr[pivot] <= arr[end]) end--;
		if (start > end) swap(arr[pivot], arr[end]);
		else swap(arr[start], arr[end]);
	}

	arr = quick_sort(arr, left, end - 1);
	arr = quick_sort(arr, end + 1, right);

	return arr;
}

vector<int> quick_easy(vector<int> arr, int start, int end) {
	if (start >= end) return arr;
	int pivot = arr[(start + end) / 2];
	int left = start, right = end;

	while (left <= right) {
		while (arr[left] < pivot) left++;
		while (pivot < arr[right]) right--;
		if (left <= right) {
			swap(arr[left], arr[right]);
			left++, right--;
		}
	}

	arr = quick_easy(arr, start, right);
	arr = quick_easy(arr, left, end);

	return arr;
}

int main()
{
	vector<int> input = { 10,5,2,3,4,6,8,7,9,1 };
	
	vector<int> bubble = bubble_sort(input);
	for (int x : bubble)
		cout << x << " ";
	cout << endl;
	
	vector<int> selection = selection_sort(input);
	for (int x : selection)
		cout << x << " ";
	cout << endl;
	
	vector<int> insertion = insertion_sort(input);
	for (int x : insertion)
		cout << x << " ";
	cout << endl;
	
	vector<int> merge = merge_sort(input,0,input.size()-1);
	for (int x : merge)
		cout << x << " ";
	cout << endl;

	vector<int> quick = quick_easy(input,0,input.size()-1);
	for (int x : quick)
		cout << x << " ";
	cout << endl;
}