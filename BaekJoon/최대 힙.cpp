#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <algorithm>
using namespace std;
int h[100001];
int c = 0; //capacity
void swap(int a, int b)
{
	int tmp = h[a];
	h[a] = h[b];
	h[b] = tmp;
}
void removeHeap(void)
{
	if (c == 0)
		cout << "0\n";
	else {
		cout << h[1] << "\n";
		h[1] = h[c];
		h[c--] = 0;
		int i = 1;
		while (2 * i <= c) {
			if (h[i] >= h[2 * i] && h[i] >= h[2 * i + 1]) break;
			else {
				if (h[2 * i] > h[2 * i + 1]) {
					swap(i, 2 * i);
					i *= 2;
				}
				else {
					swap(i, 2 * i + 1);
					i = 2 * i + 1;
				}
			}
		}
	}
}

void insertHeap(int t)
{
	h[++c] = t;
	for (int i = c; i > 1; i /= 2) {
		if (h[i] >= h[i / 2])
			swap(i, i / 2);
		else break;
	}
}

int main()
{
	int N, tmp;
	cin >> N;
	while (N--) {
		scanf("%d", &tmp);
		if (tmp == 0) removeHeap();
		else insertHeap(tmp);
	}
}