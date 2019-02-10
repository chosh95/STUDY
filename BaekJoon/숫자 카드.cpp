#include <iostream>
#include <algorithm>
using namespace std;
int n[500002];
int m[500002];
bool search(int low,int high,int key)
{
	int mid = (low + high) / 2;
	if (n[low]==key || n[mid] == key || n[high] == key) return true;
	if (low == mid && n[low] != key) return false;
	if (n[mid] > key) search(low, mid, key);
	else search(mid, high, key);
}

int main()
{
	int N, M;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> n[i];
	cin >> M;
	for (int j = 1; j <= M; j++) cin >> m[j];
	sort(n, n + N);
	for (int i = 1; i <= M; i++) {
		bool tmp = search(0,N-1,m[i]);
		if (tmp) cout << "1 ";
		else cout << "0 ";
	}
}
