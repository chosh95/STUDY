#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int p[100005];
void search(int m,int low,int high) {
	int mid = (low + high) / 2 ;
	if (p[mid] == m || p[low] == m || p[high] == m) printf("1\n");
	else if (mid == low) printf("0\n");
	else if (m > p[mid]) search(m, mid, high);
	else if (m < p[mid]) search(m, low, mid);
}

int main()
{
	int N,M,tmp;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &p[i]);
	sort(p + 1, p + N+1);
	scanf("%d", &M);
	for (int i = 1; i <= M; i++) {
		scanf("%d", &tmp);
		search(tmp,1,N);
	}
}