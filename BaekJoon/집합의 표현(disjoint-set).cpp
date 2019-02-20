#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int p[1000000 + 2];
int Find(int a)
{
	if (p[a] == a) return a;
	else {
		int c = Find(p[a]);
		p[a] = c;
		return c;
	}
}
void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);
	p[b] = a;
}
int main()
{
	int N,M;
	cin >> N >> M;
	for (int i = 0; i <= N; i++) p[i] = i;
	while (M--)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if (a == 0) {
			Union(b, c);
		}
		if (a == 1) {
			if (Find(b)==Find(c)) printf("YES\n");
			else printf("NO\n");
		}
	}
}