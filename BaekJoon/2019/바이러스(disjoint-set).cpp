#include <iostream>
using namespace std;
int p[102];
int Find(int x)
{
	if (p[x] == x) return x;
	else {
		int c = Find(p[x]);
		p[x] = c;
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
	int N, M, a, b;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) p[i] = i;
	while (M--) {
		cin >> a >> b;
		Union(a, b);
	}
	int res = 0;
	for (int i = 2; i <= N; i++) {
		if (Find(i) == Find(1)) res++;
	}
	cout << res;
}