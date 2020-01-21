#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
int p[2000001];

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N + M; i++) cin >> p[i];
	sort(p, p + N + M);
	for (int i = 0; i < N + M; i++) cout << p[i] << " ";
}